@echo off

REM  Generate the files that contain the Prolog & Flora installation directories
REM  Generates runflora.bat file that can be used to run flora

if "%1" == "" goto florausage

if "%2" == "" (if not exist genincludes\flrtable.flh goto floranotcompilederror)

@echo.
@set PROLOG=%1
call %PROLOG% -e "halt." > null 2>&1 || goto xsbinstallerror
call %PROLOG% -e "[flrdepstest]. halt." > null 2>&1 || goto xsbsourceserror
call %PROLOG% -e "[flrconfig]. halt." || goto floraconfigerror

if "%2" == "" goto success

goto end

:success
@echo.
@echo.
@echo +++++ All is well: run FLORA-2 using the script
@echo +++++    runflora.bat
@echo.
goto end

:xsbinstallerror
@echo.
@echo.
@echo +++++ Engine %PROLOG% has failed to start:
@echo +++++    XSB has not been configured properly
@echo.
goto end

:xsbsourceserror
@echo.
@echo.
@echo +++++ XSB sources do not seem to have been installed
@echo.
goto end

:floranotcompilederror
@echo.
@echo.
@echo +++++ FLORA-2 must first be compiled with the makeflora.bat command
@echo.
goto end

:floraconfigerror
@echo.
@echo.
@echo +++++ Failed to configure FLORA-2
@echo +++++ Please report to flora-users@lists.sf.net and include the log
@echo.
goto end

:florausage
@echo.
@echo.
@echo +++++ Usage:
@echo +++++    floraconfig path-to-\XSB\bin\xsb.bat    (32 bit installations)
@echo +++++    floraconfig path-to-\XSB\bin\xsb64.bat  (64 bit installations)
@echo.
goto end

:end
@echo.


REM Local Variables:
REM coding-system-for-write:  iso-2022-7bit-dos
REM End:
