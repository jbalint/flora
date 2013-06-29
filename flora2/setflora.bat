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
@echo +++++ FLORA-2 must be first compiled with the makeflora.bat command
@echo.
goto end

:usage
@echo.
@echo +++++ Usage:  setflora full-path-to-prolog
@echo.
goto end

:end
@echo.
