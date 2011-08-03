## File:      flora2/datatypes/NMakefile.mak - Make file for Microsoft NMAKE
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

ALLOBJS = flrdatatype$(OBJEXT) \
	flrdtype_sub$(OBJEXT) \
	flrdatatype_parse$(OBJEXT) \
	flrtime_arith$(OBJEXT) \
	flrdatatype_utils$(OBJEXT)

OPTIONS = [optimize]

.SUFFIXES: $(PROLOGEXT) $(OBJEXT)

ALL:: $(ALLOBJS)

CLEAN :
	-@if exist *~ erase *~
	-@if exist *$(OBJEXT) erase *$(OBJEXT)
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*


$(PROLOGEXT)$(OBJEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora,mc(%|fF,$(OPTIONS)). halt."
