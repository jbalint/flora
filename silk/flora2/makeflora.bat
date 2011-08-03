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

if "%1" == "clean" if not exist binary-distribution.txt nmake /nologo /f NMakefile.mak clean
if "%1" == "clean" goto end

if not exist .prolog_path_wind  echo. > .prolog_path_wind

REM  Generate the files that contain the Prolog & Flora installation directories
REM  Generates runflora.bat file that can be used to run flora

if exist runflora.bat  del runflora.bat
call %PROLOG% -e "[flrconfig]. halt."

cd p2h
if exist *.dll   del *.dll
if exist *.lib   del *.lib
if exist *.def   del *.def
if exist *.exp   del *.exp
if exist *.obj   del *.obj
if exist *.a     del *.a
if exist *.o     del *.o
if exist *.xwam  del *.xwam

if "%1" == "-c"   if not exist ..\binary-distribution.txt nmake /nologo /f NMakefile.mak
if "%1" == "-c64" if not exist ..\binary-distribution.txt nmake /nologo /f NMakefile64.mak

cd ..

if not exist binary-distribution.txt  nmake /nologo /f NMakefile.mak

:end
@echo.

REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
