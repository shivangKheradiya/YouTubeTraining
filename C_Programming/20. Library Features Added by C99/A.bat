@echo off
setlocal enabledelayedexpansion

set prefix=20

set i=1

for %%A in (
"The_Complex_Library"
"The_Floating-Point_Environment_Library"
"stdint_h_Header"
"Integer_Format_Conversion_Functions"
"Type-Generic_Math_Macros"
"stdbool_h_Header"
) do (
    set "num=0!i!"
    set "num=!num:~-2!"
    set "fname=%prefix%.!num!. %%A.md"

    echo # %prefix%.!num!. %%A > "!fname!"
    echo Created !fname!

    set /a i+=1
)

echo.
echo All indexed Markdown files created successfully.
pause