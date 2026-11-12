<#
  C 语言「一键运行」脚本
  ------------------------------------------------------------------
  由 VS Code 的 Code Runner 调用，做三件事：
    1. 把 .c 编译到临时目录（不在代码文件夹里留 exe）
    2. 后台把 exe 推送到 GitHub 的 exe/ 目录
    3. 弹出独立的 cmd 黑窗运行程序，按任意键关闭

  用法（由 Code Runner 自动调用，一般不需要手动执行）：
    powershell -NoProfile -ExecutionPolicy Bypass -File run-c.ps1 -SourcePath "C:\...\xxx.c"
#>
param(
    [Parameter(Mandatory = $true)]
    [string]$SourcePath
)

$ErrorActionPreference = 'Continue'

$Gcc  = 'C:\mingw64\bin\gcc.exe'
$Repo = 'C:\01-编程代码\C语言学习'
$Tmp  = Join-Path $env:TEMP 'crun'

$Src     = [System.IO.Path]::GetFullPath($SourcePath)
$SrcDir  = Split-Path $Src -Parent
$Name    = [System.IO.Path]::GetFileNameWithoutExtension($Src)
$ExePath = Join-Path $Tmp "$Name.exe"
$BatPath = Join-Path $Tmp "run_$Name.bat"

New-Item -ItemType Directory -Force -Path $Tmp | Out-Null

# ---------- 1. 编译到临时目录 ----------
Push-Location $SrcDir
$Output = & $Gcc $Src -o $ExePath 2>&1
$Code   = $LASTEXITCODE
Pop-Location

if ($Code -ne 0) {
    Write-Host ''
    Write-Host '========== 编译失败 ==========' -ForegroundColor Red
    $Output | ForEach-Object { Write-Host $_ -ForegroundColor Red }
    Write-Host ''
    exit 1
}

if ($Output) {
    Write-Host '========== 编译警告 ==========' -ForegroundColor Yellow
    $Output | ForEach-Object { Write-Host $_ -ForegroundColor Yellow }
}

Write-Host ("编译成功 -> " + $ExePath) -ForegroundColor Green

# ---------- 2. 后台把 exe 传到 GitHub（不阻塞，失败会弹窗提醒）----------
try {
    Start-Process -FilePath 'powershell.exe' `
        -ArgumentList '-NoProfile', '-ExecutionPolicy', 'Bypass',
                      '-File', "`"$Repo\tools\upload-exe.ps1`"",
                      '-ExePath', "`"$ExePath`"",
                      '-Name', $Name `
        -WindowStyle Hidden -ErrorAction Stop
} catch {
    Write-Host ("[提示] 上传进程启动失败: " + $_.Exception.Message) -ForegroundColor Yellow
}

# ---------- 3. 弹出独立 cmd 窗口运行 ----------
# 用临时 bat 启动，避免路径里的中文/空格在 cmd 引号里出错
$batContent = @"
@echo off
chcp 65001 >nul
cd /d "$SrcDir"
"$ExePath"
echo.
pause
del "%~f0"
"@
$batContent | Out-File -FilePath $BatPath -Encoding Default

Start-Process -FilePath 'cmd.exe' -ArgumentList '/c', "`"$BatPath`""
