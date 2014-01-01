@echo OFF

set flrshell=ergo_shell
if [%0] == [runergo]  set flrshell=ergo_shell

set STARTUPOPTIONS=
if [%1] == [--devel] (shift
) else set STARTUPOPTIONS=--noprompt --quietload --nofeedback --nobanner

@set thisdir=%0\..\
@call %thisdir%.flora_paths.bat

REM @set PROLOGOPTIONS="-m 2000000 -c 50000"
REM @set PROLOGOPTIONS="-p -m 2000000 -c 50000"
REM @set PROLOGOPTIONS="-p"
REM @set PROFILING=xsb_profiling:profile_unindexed_calls(on).

@%PROLOG% %STARTUPOPTIONS% %PROLOGOPTIONS% -e "%PROFILING% asserta(library_directory(%FLORADIR%)). [flora2]. %flrshell%." %1 %2 %3 %4 %5 %6 %7
