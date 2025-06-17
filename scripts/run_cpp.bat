@echo off
chcp 65001

REM 1. 获取第一个参数：要编译的 CPP 文件绝对路径
set "CPP_FILE=%~1"

REM 如果没有传入参数，则提示并退出
if "%CPP_FILE%"=="" (
    echo Error: no C++ source file specified.
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

REM 4. 用 g++ 编译，产物输出到脚本同级的 Build 文件夹
REM    请确保 g++ 在环境变量 PATH 中；否则可改为完整路径，如 C:\msys64\ucrt64\bin\g++.exe
echo Compiling %CPP_FILE% ...
g++ -std=c++23 -DLOCAL "%CPP_FILE%" -o "%BUILD_DIR%\%FILE_NAME%.exe"

REM 检查编译是否成功
if errorlevel 1 (
    echo Compile failed. Please fix errors.
    pause
    exit /b 1
)

REM 5. 编译成功后，打开一个新的 cmd 窗口来运行可执行，/k 保留窗口
start "" cmd /k "%BUILD_DIR%\%FILE_NAME%.exe"

REM 脚本结束
exit /b 0
