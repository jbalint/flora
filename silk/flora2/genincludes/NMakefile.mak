## File:      flora2/genincludes/NMakefile.mak - Make file for Microsoft NMAKE
##
## Author(s): Michael Kifer
##            Guizhen Yang
##
## Contact:   kifer@cs.stonybrook.edu
##
## Copyright (C) by
##      The Research Foundation of the State University of New York, 1999-2013.
##
## All rights reserved.
##
## For information about licensing terms, please see
## http://silk.projects.semwebcentral.org/flora2-license.html
##
##



ALLOBJS = flrpatch.flh flrpreddef.flh flrindex_P.flh \
	  flrdyndeclare.flh \
	  flrdyna.flh flrdynz.flh \
	  flrexportcheck.flh \
	  flrtable.flh flrhilogtable.flh \
	  flrdefeasible.flh \
	  flropposes.flh \
	  flropposes_data.flh \
	  flrdescriptor_metafacts.flh \
	  flrrefreshtable.flh

!IF EXISTS (..\.prolog_path_wind) 
!INCLUDE ..\.prolog_path_wind
!ENDIF

.SUFFIXES: .fli .flh

ALL: $(ALLOBJS)

CLEAN :
	-@if exist *~ erase *~
	-@if exist *.flh erase *.flh
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*

flrpreddef.flh:
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. flWrapAround(flrpreddef). halt."

flrindex_P.flh:
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. flWrapAround(flrindex_P). halt."


.fli.flh:
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. import flWrapAround/1 from flrwraparound. flWrapAround(%|fF). halt." 
