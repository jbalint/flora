@echo off

REM  Call:
REM     makeflora [-S] [-c|-c64] full-path-to-prolog
REM     makeflora clean

REM   makeflora -S full-path-to-prolog
REM       means: configure FLORA for subsumptive tabling
REM   makeflora -c full-path-to-prolog
REM       means: use the C compiler to recompile the directory
REM   makeflora -c64 full-path-to-prolog
REM       Like -c, but make for the 64 bit version of Windows
REM   .\p2h - developer's option

REM  NOTE: DOS batch language is very brittle. For instance, replacing
REM        %1 with %ARG%, where set ARG=%1 will not work if
REM        full-path-to-prolog has a file extension, e.g., \xsb\bin\wxsb.bat

set default_tabling=flrincludes\.flora_default_tabling
echo. > %default_tabling%
if "%1" == "-S" echo #define FLORA_SUBSUMPTIVE_TABLING > %default_tabling%
if "%1" == "-S" shift
if "%1" == "-I" echo #define FLORA_INCREMENTAL_TABLING > %default_tabling%
if "%1" == "-I" shift
if "%1" == "-S" echo #define FLORA_SUBSUMPTIVE_TABLING > %default_tabling%
if "%1" == "-S" shift

if "%1" == "" echo Usage:  makeflora [-c|-c64] full-path-to-prolog
if "%1" == "" goto end

if        "%1" == "-c"    (set PROLOG=%2 -s -m 40000 -c 4000
) else if "%1" == "-c64"  (set PROLOG=%2 -s -m 40000 -c 4000
) else                    set PROLOG=%1 -s -m 40000 -c 4000

@echo.
if "%PROLOG%" == "" echo Usage:  makeflora [-c|-c64] full-path-to-prolog
if "%PROLOG%" == "" goto end

if "%1" == "clean" if not exist binary-distribution.txt nmake /f NMakefile.mak clean
if "%1" == "clean" goto end

if not exist .prolog_path_wind  echo. > .prolog_path_wind

REM  Generate the files that contain the Prolog & Flora installation directories
REM  Generates runflora.bat file that can be used to run flora

if exist runflora.bat  del runflora.bat
call %PROLOG% -e "[flrconfig]. halt."

cd p2h
if exist prolog2hilog.dll   del prolog2hilog.dll
if exist prolog2hilog.lib   del prolog2hilog.lib
if exist prolog2hilog.def   del prolog2hilog.def
if exist prolog2hilog.exp   del prolog2hilog.exp
if exist prolog2hilog.obj   del prolog2hilog.obj
if exist prolog2hilog.a     del prolog2hilog.a
if exist prolog2hilog.o     del prolog2hilog.o
if exist prolog2hilog.xwam  del prolog2hilog.xwam

if "%1" == "-c"   if not exist ..\binary-distribution.txt nmake /f NMakefile.mak
if "%1" == "-c"   if not exist ..\binary-distribution.txt if exist prolog2hilog.obj del prolog2hilog.obj
if "%1" == "-c64" if not exist ..\binary-distribution.txt nmake /f NMakefile64.mak
if "%1" == "-c64" if not exist ..\binary-distribution.txt if exist prolog2hilog.obj del prolog2hilog.obj

cd ..

if not exist binary-distribution.txt  nmake /f NMakefile.mak

:end
@echo.

REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
