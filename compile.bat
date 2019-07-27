@echo off
setlocal enabledelayedexpansion
set STR=
for /r %%A in (src\*.cpp) do (
  set STR=!STR! %%A
)

rem make bin directory
IF NOT EXIST "bin" (
mkdir bin
)
rem make exe
g++ -std=c++2a -Wall -Wextra --pedantic-error -O3 -o bin\app.exe %STR% -I. --exec-charset=cp932

rem make asm directory
IF NOT EXIST "asm" (
mkdir asm
)
rem make assembly
g++ -std=c++2a -Wall -Wextra --pedantic-error -O3 -o asm\asm.s -S %STR% -I. --exec-charset=cp932

endlocal