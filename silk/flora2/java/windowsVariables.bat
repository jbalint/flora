@echo off
REM File:      windowsVariables.bat
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

REM Change JAVA_BIN, ENGINE, and PROTEGE_DIR, if necessary
set JAVA_BIN="C:\Program Files\Java\jdk1.6.0\bin"
REM Valid values: Native or Subprocess
set ENGINE=Subprocess
REM set ENGINE=Native
set PROTEGE_DIR="C:\Program Files\Protege_3.1"


REM Don't change this!
set JARS="%PROTEGE_DIR%\protege.jar";"%PROTEGE_DIR%\looks.jar";"%PROTEGE_DIR%\unicode_panel.jar";"%PROTEGE_DIR%\driver.jar";"%PROTEGE_DIR%\driver1.jar";"%PROTEGE_DIR%\driver2.jar"
