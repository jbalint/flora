## File:      flora2/pkgs/NMakefile.mak - Make file for Microsoft NMAKE
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



!IF EXISTS (..\.prolog_path_wind) 
!INCLUDE ..\.prolog_path_wind
!ENDIF

OBJEXT = .xwam
PROLOGEXT = .P

ALLOBJS = flrxml_aux$(PROLOGEXT) javaAPI$(PROLOGEXT) \
	  gclpe$(PROLOGEXT) \
	  ogclp$(PROLOGEXT) \
	  ogclpe$(PROLOGEXT) \
	  atck2$(PROLOGEXT) \
	  atck3$(PROLOGEXT) \
	  atck1alt$(PROLOGEXT) \
	  persistentmodules$(PROLOGEXT) prettyprint$(PROLOGEXT)

OPTIONS=[optimize]

.SUFFIXES: $(PROLOGEXT) .flr

ALL: $(ALLOBJS)


flrxml_aux$(PROLOGEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. import ('_compile')/1 from flora2. '_compile'(%|fF >> flrxml). halt."

.flr$(PROLOGEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. import ('_compile')/1 from flora2. '_compile'(%|fF). halt."


CLEAN:
	-@if exist *$(PROLOGEXT) erase *$(PROLOGEXT)
	-@if exist *$(OBJEXT) erase *$(OBJEXT)
	-@if exist *.flh erase *.fdb
	-@if exist *.fld erase *.fld
	-@if exist *.flt erase *.flt
	-@if exist *.fls erase *.fls
	-@if exist *~ erase *~
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*
