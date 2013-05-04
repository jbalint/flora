@echo off
REM File:      windowsVariables.bat
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

REM Change JAVA_BIN, ENGINE, and PROTEGE_DIR, if necessary
set JAVA_BIN="C:\Program Files\Java\jdk1.6.0\bin"
REM Valid values: Native or Subprocess
set ENGINE=Subprocess
REM set ENGINE=Native
set PROTEGE_DIR="C:\Program Files\Protege_3.1"


REM Don't change this!
set JARS="%PROTEGE_DIR%\protege.jar";"%PROTEGE_DIR%\looks.jar";"%PROTEGE_DIR%\unicode_panel.jar";"%PROTEGE_DIR%\driver.jar";"%PROTEGE_DIR%\driver1.jar";"%PROTEGE_DIR%\driver2.jar"
