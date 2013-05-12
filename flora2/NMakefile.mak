## File:      flora2/NMakefile.mak -- Make file for Microsoft NMAKE
##
## Author(s): Michael Kifer
##
## Contact:   kifer@cs.stonybrook.edu
##
## Copyright (C) by
##      The Research Foundation of the State University of New York, 1999-2013;
##      and Vulcan, Inc., 2008-2013.
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
##
##

OBJEXT = .xwam
PROLOGEXT = .P

ALLOBJS = flrarguments$(OBJEXT) \
	  flrcomposer$(OBJEXT) \
	  flrcompiler$(OBJEXT) \
	  flrcoder$(OBJEXT) \
	  flrdependency$(OBJEXT) \
	  flrlexer$(OBJEXT) \
	  flrlibman$(OBJEXT) \
	  flrnodefp$(OBJEXT) \
	  flrnowsp$(OBJEXT) \
	  flroperator$(OBJEXT) \
	  flrparser$(OBJEXT) \
	  flrporting$(OBJEXT) \
	  flrpretifydump$(OBJEXT) \
	  flrprint$(OBJEXT) \
	  flrprolog$(OBJEXT) \
	  flrregistry$(OBJEXT) \
	  flrshell$(OBJEXT) \
	  flrundefined$(OBJEXT) \
	  flrundefhook$(OBJEXT) \
	  flrutils$(OBJEXT) \
	  flrversion$(OBJEXT) \
	  flrwraparound$(OBJEXT) \
	  flrsynonym$(OBJEXT) \
	  flrsimpleprimitive$(OBJEXT) \
	  flrwrapper$(OBJEXT)

OPTIONS = [optimize,ti_all]

!IF EXISTS (.prolog_path_wind) 
!INCLUDE .prolog_path_wind
!ENDIF

.SUFFIXES: $(PROLOGEXT) $(OBJEXT)

## p2h is handled specially, by makeflora
ALL:: CLEANTEMP $(ALLOBJS)
	cd closure
	nmake /nologo /f NMakefile.mak
	cd ..\includes
	nmake /nologo /f NMakefile.mak
	cd ..\genincludes
	nmake /nologo /f NMakefile.mak
	cd ..\syslib
	nmake /nologo /f NMakefile.mak
	cd ..\lib
	nmake /nologo /f NMakefile.mak
	cd ..\AT
	nmake /nologo /f NMakefile.mak
	cd ..\debugger
	nmake /nologo /f NMakefile.mak
	cd ..\pkgs
	nmake /nologo /f NMakefile.mak
	cd ..\demos
	nmake /nologo /f NMakefile.mak
	cd ..

CLEAN : CLEANTEMP
	-@if exist *~ erase *~
	-@if exist *$(OBJEXT) erase *$(OBJEXT)
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*
	-@if exist ..\flora2$(OBJEXT) erase ..\flora2$(OBJEXT)
	cd p2h
	nmake /nologo /f NMakefile.mak clean
	cd ..\closure
	nmake /nologo /f NMakefile.mak clean
	cd ..\genincludes
	nmake /nologo /f NMakefile.mak clean
	cd ..\includes
	nmake /nologo /f NMakefile.mak clean
	cd ..\datatypes
	nmake /nologo /f NMakefile.mak clean
	cd ..\syslib
	nmake /nologo /f NMakefile.mak clean
	cd ..\debugger
	nmake /nologo /f NMakefile.mak clean
	cd ..\lib
	nmake /nologo /f NMakefile.mak clean
	cd ..\AT
	nmake /nologo /f NMakefile.mak clean
	cd ..\pkgs
	nmake /nologo /f NMakefile.mak clean
	cd ..\demos
	nmake /nologo /f NMakefile.mak clean
	cd ..\docs
	nmake /nologo /f NMakefile.mak clean
	cd ..\emacs
	nmake /nologo /f NMakefile.mak clean
	cd ..


$(PROLOGEXT)$(OBJEXT):
	$(PROLOG) -e "['.\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora,mc(%|fF,$(OPTIONS)). halt."


.SILENT:

CLEANTEMP :
	-@for /D %%i in (%USERPROFILE%\.xsb\"flora-*") do \
	     if exist %%i\*$(OBJEXT) erase %%i\*$(OBJEXT) %%i\*$(PROLOGEXT)