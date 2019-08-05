@echo off
setlocal enabledelayedexpansion
set STR=
for /r %%A in (src\*.cpp) do (
  set STR=!STR! %%A
)

rem command option
set OPTION=-std=c++2a -Wall -Wextra -Xclang -flto-visibility-public-std -O3 -I. -o

rem make bin directory
IF NOT EXIST "bin" (
mkdir bin
)
rem make exe
clang++ %OPTION% bin\app.exe  %STR%

rem make asm directory
IF NOT EXIST "asm" (
mkdir asm
)
rem make assembly
clang++ %OPTION% asm\asm.s -S %STR%

endlocal