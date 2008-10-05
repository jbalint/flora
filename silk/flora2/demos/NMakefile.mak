## File:      flora2/demos/NMakefile.mak - Make file for Microsoft NMAKE
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

ALLOBJS = aggregate$(PROLOGEXT) benchmark$(PROLOGEXT) \
	  clpdemo$(PROLOGEXT) default$(PROLOGEXT) family_obj$(PROLOGEXT) \
	  family_rel$(PROLOGEXT) flogic_basics$(PROLOGEXT) \
	  metavar$(PROLOGEXT) mix$(PROLOGEXT) module1$(PROLOGEXT) \
	  mod1$(PROLOGEXT) \
	  mono_inherit$(PROLOGEXT) rel_ops$(PROLOGEXT) \
	  tree_traversal$(PROLOGEXT) diamond$(PROLOGEXT)\
	  btupdates$(PROLOGEXT) pretty$(PROLOGEXT)

OPTIONS = [optimize]

.SUFFIXES: $(PROLOGEXT) .flr

ALL: $(ALLOBJS)


.flr$(PROLOGEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. import ('_compile')/1 from flora2. '_compile'(%|fF). halt."


CLEAN:
	-@erase *~
	-@erase *$(OBJEXT)
	-@erase *$(PROLOGEXT)
	-@erase *$(PROLOGEXT)_gpp
	-@erase *.fdb
	-@erase *.fld
	-@erase *.bak
	-@erase .#*

