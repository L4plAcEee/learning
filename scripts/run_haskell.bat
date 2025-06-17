@echo off
chcp 65001

REM 1. 获取第一个参数：要编译的 Haskell 文件绝对路径
set "HS_FILE=%~1"

REM 如果没有传入参数，则提示并退出
if "%HS_FILE%"=="" (
    echo Error: no Haskell source file specified.
    pause
    exit /b 1
)

REM 2. 提取文件名（不含扩展名），用于命名可执行文件
set "FILE_NAME=%~n1"

REM 3. 获取脚本所在目录（带尾部反斜杠），并在该目录下定义 Build 文件夹
set "SCRIPT_DIR=%~dp0"
set "BUILD_DIR=%SCRIPT_DIR%build"

REM 如果 Build 文件夹不存在，则创建
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)

REM 4. 编译 Haskell 文件，产物输出到 build 目录
REM    请确保 ghc 已加入环境变量 PATH
echo Compiling %HS_FILE% ...
ghc -outputdir "%BUILD_DIR%" -o "%BUILD_DIR%\%FILE_NAME%.exe" "%HS_FILE%"

REM 检查编译是否成功
if errorlevel 1 (
    echo Compile failed. Please fix errors.
    pause
    exit /b 1
)

REM 5. 编译成功后，打开一个新的 cmd 窗口来运行可执行文件，/k 保留窗口
start "" cmd /k "%BUILD_DIR%\%FILE_NAME%.exe"

REM 脚本结束
exit /b 0
