## File:      flora2/NMakefile.mak -- Make file for Microsoft NMAKE
##
## Author(s): Michael Kifer
##
## Contact:   kifer@cs.stonybrook.edu
##
## Copyright (C) by
##      The Research Foundation of the State University of New York, 1999-2008.
##
## All rights reserved.
##
## For information about licensing terms, please see
## http://silk.projects.semwebcentral.org/flora2-license.html
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
	  flrwrapper$(OBJEXT)

OPTIONS = [optimize,ti_all]

!IF EXISTS (.prolog_path_wind) 
!INCLUDE .prolog_path_wind
!ENDIF

.SUFFIXES: $(PROLOGEXT) $(OBJEXT)

## p2h is handled specially, buy makeflora
ALL:: CLEANTEMP $(ALLOBJS)
	cd closure
	nmake /f NMakefile.mak
	cd ..\genincludes
	nmake /f NMakefile.mak
	cd ..\syslib
	nmake /f NMakefile.mak
	cd ..\lib
	nmake /f NMakefile.mak
	cd ..\debugger
	nmake /f NMakefile.mak
	cd ..\pkgs
	nmake /f NMakefile.mak
	cd ..\demos
	nmake /f NMakefile.mak
	cd ..

CLEAN : CLEANTEMP
	-@erase *~
	-@erase *$(OBJEXT)
	-@erase *.bak
	-@erase .#*
	-@erase ..\flora2$(OBJEXT)
	cd p2h
	nmake /f NMakefile.mak clean
	cd ..\closure
	nmake /f NMakefile.mak clean
	cd ..\genincludes
	nmake /f NMakefile.mak clean
	cd ..\datatypes
	nmake /f NMakefile.mak clean
	cd ..\syslib
	nmake /f NMakefile.mak clean
	cd ..\debugger
	nmake /f NMakefile.mak clean
	cd ..\lib
	nmake /f NMakefile.mak clean
	cd ..\pkgs
	nmake /f NMakefile.mak clean
	cd ..\demos
	nmake /f NMakefile.mak clean
	cd ..\docs
	nmake /f NMakefile.mak clean
	cd ..\emacs
	nmake /f NMakefile.mak clean
	cd ..

CLEANTEMP :
	-@erase "%HOME%\.xsb\flora*\*$(OBJEXT)
	-@erase "%HOME%\.xsb\flora*\*$(PROLOGEXT)


$(PROLOGEXT)$(OBJEXT):
	$(PROLOG) -e "['.\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora,mc(%|fF,$(OPTIONS)). halt."


