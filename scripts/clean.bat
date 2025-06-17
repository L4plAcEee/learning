@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

:: 获取当前脚本路径
set "SCRIPT_PATH=%~dp0"
:: 去掉末尾反斜杠
set "SCRIPT_PATH=%SCRIPT_PATH:~0,-1%"
:: 获取父目录
for %%I in ("%SCRIPT_PATH%\..") do set "ROOT=%%~fI"

echo 开始清理目录: %ROOT%
echo.

:: 递归删除 .exe, .o, .hi 文件
for /r "%ROOT%" %%F in (*.exe *.o *.hi) do (
    echo 删除文件: "%%F"
    del /f /q "%%F"
)

echo.
echo ✅ 清理完成！
pause
