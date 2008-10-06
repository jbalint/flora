## File:      flora2/lib/NMakefile.mak - Make file for Microsoft NMAKE
##
## Author(s): Michael Kifer
##            Guizhen Yang
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

ALLOBJS = flrio$(PROLOGEXT) \
	  flrstorage$(PROLOGEXT) flrsystem$(PROLOGEXT) \
	  flrbasetype$(PROLOGEXT) \
	  flrparse$(PROLOGEXT) \
	  flrtypeconstraint$(PROLOGEXT) \
	  flrgclp$(PROLOGEXT) \
          flreval$(PROLOGEXT)

!IF EXISTS (..\.prolog_path_wind) 
!INCLUDE ..\.prolog_path_wind
!ENDIF

OPTIONS = [optimize]

.SUFFIXES: $(PROLOGEXT) .flr

ALL: $(ALLOBJS)


.flr$(PROLOGEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. import flora_compile_system_module/1 from flrutils. flora_compile_system_module(%|fF). halt."


CLEAN:
	-@erase *~
	-@erase *$(OBJEXT)
	-@erase *$(PROLOGEXT)
	-@erase *.fdb
	-@erase *.fld
	-@erase *.bak
	-@erase .#*
