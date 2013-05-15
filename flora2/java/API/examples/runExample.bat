@echo off
REM File:      runExample.bat
REM
REM Author(s): Aditi Pandit
REM
REM Contact:   flora-users@lists.sourceforge.net
REM
REM Copyright (C) by
REM      The Research Foundation of the State University of New York, 1999-2013.
REM
REM Licensed under the Apache License, Version 2.0 (the "License");
REM you may not use this file except in compliance with the License.
REM You may obtain a copy of the License at
REM
REM      http://www.apache.org/licenses/LICENSE-2.0
REM
REM Unless required by applicable law or agreed to in writing, software
REM distributed under the License is distributed on an "AS IS" BASIS,
REM WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
REM See the License for the specific language governing permissions and
REM limitations under the License.
REM
REM




echo ==============================
CALL ..\..\windowsVariables.bat
CALL ..\..\flora_settings.bat

CALL %1%\floraVariables.bat

echo Executing code

set INTERPROLOG = ..\..\..\..\interprolog.jar

%JAVA_BIN%\java -DPROLOGDIR=%PROLOGDIR% -DFLORA_FILE=%FLORA_FILE% -DFLORADIR=%FLORADIR% -DXSB_BIN_DIRECTORY=%XSB_BIN_DIRECTORY% -Djava.library.path=%PROLOGDIR% -DENGINE=%ENGINE% -classpath %CLASSPATH%;..\javaAPI\src;..\javaAPI\util;%INTERPROLOG%;fooExample;flogicbasicsExample %1%


REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
