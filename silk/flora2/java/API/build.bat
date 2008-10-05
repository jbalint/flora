@echo off
REM File:      build.bat
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
echo ------------------------------

CALL ..\windowsVariables.bat
CALL ..\flora_settings.bat

del javaAPI\util\*.class

del javaAPI\src\*.class

echo *** The above "Could Not Find ... " warnings (if any) are normal


echo ------------------------------
echo Compiling files ...
echo ------------------------------

%JAVA_BIN%\javac -Xlint  -classpath ..;..\interprolog.jar javaAPI\util\*.java javaAPI\src\*.java 

echo *** If you saw a warning "The system cannot find the path specified",
echo *** change the variable JAVA_BIN in flora2\java\windowsVariables.bat
echo *** appropriately for your system.


REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
