@echo off
REM File:      runExample.bat
REM
REM Author(s): Aditi Pandit
REM
REM Contact:   kifer@cs.stonybrook.edu
REM
REM Copyright (C) by
REM      The Research Foundation of the State University of New York, 1999-2008.
REM
REM All rights reserved.
REM
REM For information about licensing terms, please see
REM http://silk.projects.semwebcentral.org/flora2-license.html
REM
REM




echo ==============================
CALL ..\..\windowsVariables.bat
CALL ..\..\flora_settings.bat

CALL %1%\floraVariables.bat

echo Executing code

%JAVA_BIN%\java -DPROLOGDIR=%PROLOGDIR% -DFLORA_FILE=%FLORA_FILE% -DFLORADIR=%FLORADIR% -DXSB_BIN_DIRECTORY=%XSB_BIN_DIRECTORY% -Djava.library.path=%PROLOGDIR% -DENGINE=%ENGINE% -classpath %CLASSPATH%;..;..\..\interprolog.jar;fooExample;flogicbasicsExample %1%


REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
