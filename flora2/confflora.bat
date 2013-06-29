@echo off

REM  Generate the files that contain the Prolog & Flora installation directories
REM  Generates runflora.bat file that can be used to run flora

if "%1" == "" goto usage

if "%2" == "" (if not exist genincludes\flrtable.flh goto floraerror)

@echo.
@set PROLOG=%1
call %PROLOG% -e "[flrdepstest]. halt." || goto xsberror
call %PROLOG% -e "[flrconfig]. halt."

goto end

:xsberror
@echo.
@echo +++++ XSB is not configured or its sources have not been installed
@echo.
goto end

:floraerror
@echo.
@echo +++++ FLORA-2 must first be compiled with the makeflora.bat command
@echo.
goto end

:usage
@echo.
@echo +++++ Usage:
@echo +++++    confflora path-to-\XSB\bin\xsb.bat    (32 bit installations)
@echo +++++    confflora path-to-\XSB\bin\xsb64.bat  (64 bit installations)
@echo.
goto end

:end
@echo.


REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
