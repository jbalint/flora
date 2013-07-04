@echo off

REM  Call:
REM     makeflora [-S] [-c|-c64] path-for-\XSB\bin\xsb[64].bat
REM     makeflora clean

REM   makeflora -S path-for-\XSB\bin\xsb[64].bat
REM       means: configure FLORA for subsumptive tabling
REM   makeflora -c path-for-\XSB\bin\xsb[64].bat
REM       means: use the C compiler to recompile the directory
REM   makeflora -c64 path-for-\XSB\bin\xsb[64].bat
REM       Like -c, but make for the 64 bit version of Windows
REM   .\cc - developer's option

REM  NOTE: DOS batch language is very brittle. For instance, replacing
REM        %1 with %ARG%, where ARG=%1 will not work if
REM        path-for-\XSB\bin\... has a file extension, e.g., \xsb\bin\wxsb.bat

if exist binary-distribution.txt goto binary

set default_tabling=flrincludes\.flora_default_tabling
if [%1] == [-S] echo #define FLORA_SUBSUMPTIVE_TABLING > %default_tabling%
if [%1] == [-S] shift
if [%1] == [-I] echo #define FLORA_INCREMENTAL_TABLING > %default_tabling%
if [%1] == [-I] shift
if [%1] == [-S] echo #define FLORA_SUBSUMPTIVE_TABLING > %default_tabling%
if [%1] == [-S] shift

if [%1] == [] goto usage

if        [%1] == [-c]    (set prologcmd=%2
) else if [%1] == [-c64]  (set prologcmd=%2
) else                    set prologcmd=%1

if [%prologcmd%] == [] goto usage


if [%1] == [clean] nmake /nologo /f NMakefile.mak clean
if [%1] == [clean] goto end

call floraconfig.bat %prologcmd% compiling || goto end
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

if [%1] == [-c]  nmake /nologo /f NMakefile.mak PROLOG=%PROLOG% PROLOGDIR=%PROLOGDIR%
if [%1] == [-c64]  nmake /nologo /f NMakefile64.mak PROLOG=%PROLOG% PROLOGDIR=%PROLOGDIR%

cd ..

nmake /nologo /f NMakefile.mak PROLOG=%PROLOG%


goto end

:usage
@echo.
@echo +++++ Usage:
@echo +++++   makeflora [-c] path-for-\XSB\bin\xsb      (32 bit installations)
@echo +++++   makeflora [-c64] path-for-\XSB\bin\xsb64  (64 bit installations)
@echo.
goto end

:binary
@echo.
@echo +++++ This seems to be a binary distribution of FLORA-2.
@echo +++++ Please use floraconfig.bat to configure it:
@echo +++++   floraconfig path-for-\XSB\bin\xsb.bat    (32 bit installations)
@echo +++++   floraconfig path-for-\XSB\bin\xsb64.bat  (64 bit installations)
@echo.
goto end

:end
@echo.

REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
