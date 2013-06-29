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
REM   .\cc - developer's option

REM  NOTE: DOS batch language is very brittle. For instance, replacing
REM        %1 with %ARG%, where ARG=%1 will not work if
REM        full-path-to-prolog has a file extension, e.g., \xsb\bin\wxsb.bat

set default_tabling=flrincludes\.flora_default_tabling
echo. > %default_tabling%
if "%1" == "-S" echo #define FLORA_SUBSUMPTIVE_TABLING > %default_tabling%
if "%1" == "-S" shift
if "%1" == "-I" echo #define FLORA_INCREMENTAL_TABLING > %default_tabling%
if "%1" == "-I" shift
if "%1" == "-S" echo #define FLORA_SUBSUMPTIVE_TABLING > %default_tabling%
if "%1" == "-S" shift

if "%1" == "" echo ***** Usage:  makeflora [-c or -c64] full-path-to-prolog
if "%1" == "" goto end

if        "%1" == "-c"    (set prologcmd=%2
) else if "%1" == "-c64"  (set prologcmd=%2
) else                    set prologcmd=%1

@echo.
if "%prologcmd%" == "" echo ***** Usage:  makeflora [-c or -c64] full-path-to-prolog
if "%prologcmd%" == "" goto end


if "%1" == "clean" if not exist binary-distribution.txt nmake /nologo /f NMakefile.mak clean
if "%1" == "clean" goto end

call setflora.bat %prologcmd% compiling || goto end
REM This sets %PROLOG%, %PROLOGDIR%, %FLORADIR%
call .flora_paths.bat


cd cc
if exist *.dll   del *.dll
if exist *.lib   del *.lib
if exist *.def   del *.def
if exist *.exp   del *.exp
if exist *.obj   del *.obj
if exist *.a     del *.a
if exist *.o     del *.o
if exist *.xwam  del *.xwam

if "%1" == "-c"   if not exist ..\binary-distribution.txt nmake /nologo /f NMakefile.mak PROLOG=%PROLOG% PROLOGDIR=%PROLOGDIR%
if "%1" == "-c64" if not exist ..\binary-distribution.txt nmake /nologo /f NMakefile64.mak PROLOG=%PROLOG% PROLOGDIR=%PROLOGDIR%

cd ..

if not exist binary-distribution.txt  nmake /nologo /f NMakefile.mak PROLOG=%PROLOG%

:end
@echo.

REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
