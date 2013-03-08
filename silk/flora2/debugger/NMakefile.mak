## File:      flora2debugger/NMakefile.mak - Make file for Microsoft NMAKE
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

ALLOBJS=  flrdebugger$(OBJEXT) \
	flrtabledump$(OBJEXT) \
	flrterminyzer$(OBJEXT) \
	dynamic_data.dat \
	static_data.dat

OPTIONS=[optimize]

.SUFFIXES:  .in .dat $(PROLOGEXT) .H $(OBJEXT)

ALL:: $(ALLOBJS)

CLEAN :
	-@if exist *~ erase *~
	-@if exist *$(OBJEXT) erase *$(OBJEXT)
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*
	-@if exist *.dat erase *.dat

$(PROLOGEXT)$(OBJEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora,mc(%|fF,$(OPTIONS)). halt."

static_data.dat: static_data.in
	copy static_data.in static_data.dat

dynamic_data.dat: dynamic_data.in
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. import flrWrapAround/1 from flrwraparound. flWrapAround(%|fF). halt.


