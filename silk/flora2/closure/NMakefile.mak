## File:      flora2/closure/NMakefile.mak - Make file for Microsoft NMAKE
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


ALLOBJS = flrcommon.flh \
	  flrcommon_inh.flh \
	  flrsigaxioms.flh \
          flrnoeqltrailer.flh \
          flrnoeqltrailer_inh.flh \
	  flreqltrailer.flh \
	  flreqltrailer_inh.flh \
          flrscalareql.flh \
          flrimportaxioms.flh \
	  flrpredeql.flh \
	  flrprednoeql.flh

!IF EXISTS (..\.prolog_path_wind) 
!INCLUDE ..\.prolog_path_wind
!ENDIF

.SUFFIXES: .flh .fli

ALL: $(ALLOBJS)

CLEAN :
	-@erase *~
	-@erase *.flh
	-@erase *.bak
	-@erase .#*

.fli.flh:
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. import flWrapAround/1 from flrwraparound. flWrapAround(%|fF). halt."

