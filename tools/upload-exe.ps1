<#
  把编译好的 exe 推送到 GitHub 的 exe/ 目录
  ------------------------------------------------------------------
  由 run-c.ps1 在后台调用，一般不直接执行。

  规则：
    - 推完就删掉本地的 exe 副本，代码文件夹里不留任何 exe
    - exe 内容没变（MD5 相同）就不重复提交
    - 推送失败会弹窗提醒，程序本身不受影响
#>
param(
    [Parameter(Mandatory = $true)][string]$ExePath,
    [Parameter(Mandatory = $true)][string]$Name
)

$Repo    = 'C:\01-编程代码\C语言学习'
$Git     = 'C:\Program Files\Git\cmd\git.exe'
$ExeDir  = Join-Path $Repo 'exe'
$Target  = Join-Path $ExeDir "$Name.exe"
$LogFile = Join-Path $Repo 'tools\upload.log'
$ErrMsg  = $null

function Write-Log([string]$Text) {
    try {
        ("{0}  {1}" -f (Get-Date -Format 'yyyy-MM-dd HH:mm:ss'), $Text) |
            Out-File -FilePath $LogFile -Append -Encoding utf8
    } catch { }
}

try {
    if (-not (Test-Path -LiteralPath $ExePath)) { throw "找不到编译产物：$ExePath" }
    if (-not (Test-Path -LiteralPath $Git))     { throw "找不到 git.exe：$Git" }

    New-Item -ItemType Directory -Force -Path $ExeDir | Out-Null

    # 内容没变就不提交，避免制造无意义的 commit
    $Same = $false
    if (Test-Path -LiteralPath $Target) {
        $h1 = (Get-FileHash -LiteralPath $Target  -Algorithm MD5).Hash
        $h2 = (Get-FileHash -LiteralPath $ExePath -Algorithm MD5).Hash
        if ($h1 -eq $h2) { $Same = $true }
    }

    if ($Same) {
        Write-Log "SKIP  $Name.exe 未变化"
    }
    else {
        Copy-Item -LiteralPath $ExePath -Destination $Target -Force

        # 允许 git 重新读取这个文件（上次推完可能被标记为 skip-worktree）
        & $Git -C $Repo update-index --no-skip-worktree "exe/$Name.exe" 2>&1 | Out-Null

        & $Git -C $Repo add -f "exe/$Name.exe" 2>&1 | Out-Null
        $msg = "exe: $Name ($(Get-Date -Format 'yyyy-MM-dd HH:mm'))"
        & $Git -C $Repo commit -m $msg -- "exe/$Name.exe" 2>&1 | Out-Null

        $push = & $Git -C $Repo push origin main 2>&1 | Out-String
        if ($LASTEXITCODE -ne 0) { throw ("推送失败：" + $push.Trim()) }

        Write-Log "OK    $Name.exe"
    }
}
catch {
    $ErrMsg = $_.Exception.Message
    Write-Log "FAIL  $Name :: $ErrMsg"
}
finally {
    # 本地不留 exe
    if (Test-Path -LiteralPath $Target) {
        Remove-Item -LiteralPath $Target -Force -ErrorAction SilentlyContinue
    }
    # 关键：告诉 git「别管这个文件在本地被删了」
    # 否则以后你提交代码时，会把「删除 exe」也一起提交，GitHub 上的文件就没了
    & $Git -C $Repo update-index --skip-worktree "exe/$Name.exe" 2>&1 | Out-Null
}

# ---------- 失败时弹窗提醒 ----------
if ($ErrMsg) {
    $title = 'GitHub 上传失败'
    $text  = "exe 没能推送到 GitHub：`n`n$ErrMsg`n`n程序本身已经正常运行，不影响使用。`n联网后重新运行一次就能补传。"
    $shown = $false
    try {
        Add-Type -AssemblyName PresentationFramework -ErrorAction Stop
        [System.Windows.MessageBox]::Show($text, $title, 'OK', 'Warning') | Out-Null
        $shown = $true
    } catch { }
    if (-not $shown) {
        try {
            Start-Process -FilePath 'mshta.exe' `
                -ArgumentList ("javascript:alert('exe 没能推送到 GitHub，程序已正常运行，联网后重跑一次即可补传。');close();")
        } catch { }
    }
}
