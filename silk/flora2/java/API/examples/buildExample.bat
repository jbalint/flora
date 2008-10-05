@echo off
REM File:      buildExample.bat
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
echo Building javaInterfaceCode

CALL ..\..\windowsVariables.bat
CALL ..\..\flora_settings.bat

CALL %1%\floraVariables.bat


CALL ..\..\..\runflora.bat -e "_load('%FLORA_FILE%'>>example),_load(javaAPI),%%%%write('%FLORA_CLASS%',example,'%JAVA_FILE%'),_halt."

echo Compiling files
%JAVA_BIN%\javac -classpath ..;..\..\interprolog.jar %1%\*.java

REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
