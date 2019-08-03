@echo off
setlocal enabledelayedexpansion
set STR=
for /r %%A in (src\*.cpp) do (
  set STR=!STR! %%A
)

rem command option
set OPTION=-std=c++2a -Wall -Wextra --pedantic-error -O3 -I. --exec-charset=cp932 -o

rem make bin directory
IF NOT EXIST "bin" (
mkdir bin
)
rem make exe
g++ %OPTION% bin\app.exe  %STR%

rem make asm directory
IF NOT EXIST "asm" (
mkdir asm
)
rem make assembly
g++ %OPTION% asm\asm.s -S %STR%

endlocal