@echo OFF
@set FLORADIR="'H:\SILK\\silk\\trunk\\silk\\flora2'"
@set PROLOG=\xsb\xsb\config\x86-pc-windows\bin\xsb
REM @set PROLOGOPTIONS="-m 2000000 -c 50000"
REM @set PROLOGOPTIONS="-p -m 2000000 -c 50000"
REM @set PROLOGOPTIONS="-p"
REM @set PROFILING="xsb_profiling:profile_unindexed_calls(on)."
@%PROLOG% %PROLOGOPTIONS% -e "%PROFILING% asserta(library_directory(%FLORADIR%)). [flora2]. flora_shell." %1 %2 %3 %4 %5 %6 %7