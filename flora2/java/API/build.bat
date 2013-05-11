@echo off
REM File:      build.bat
REM
REM Author(s): Aditi Pandit
REM
REM Contact:   kifer@cs.stonybrook.edu
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

set SILKLIB = ..\..\..\lib
set LOG4J = %SILKLIB%\jena\log4j-1.2.12.jar
set INTERPROLOG = %SILKLIB%\interprolog.jar
set LOG4J=""

%JAVA_BIN%\javac -Xlint  -classpath %LOG4J%;..;%INTERPROLOG% javaAPI\util\org\semwebcentral\flora2\API\util\*.java javaAPI\src\org\semwebcentral\flora2\API\*.java 

echo *** If you saw a warning "The system cannot find the path specified",
echo *** change the variable JAVA_BIN in flora2\java\windowsVariables.bat
echo *** appropriately for your system.


REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
