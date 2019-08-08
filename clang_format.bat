@echo off
setlocal enabledelayedexpansion
set STR=
for /r %%A in (*.cpp,*.hpp,*.c,*.h) do (
  set STR=!STR! %%A
)

clang-format -i %STR%

endlocal