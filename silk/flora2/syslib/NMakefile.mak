## File:      flora2/syslib/Makefile - Make file for Microsoft NMAKE
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

ALLOBJS =  flranswer$(OBJEXT) \
	   flrcontrol$(OBJEXT) \
	   flrclause$(OBJEXT) \
	   flrdisplay$(OBJEXT) \
	   flrload$(OBJEXT) \
	   flraggavg$(OBJEXT) \
	   flraggcolbag$(OBJEXT) \
	   flraggcolset$(OBJEXT) \
	   flraggcount$(OBJEXT) \
	   flraggmax$(OBJEXT) \
	   flraggmin$(OBJEXT) \
	   flraggsum$(OBJEXT) \
	   flrstorageutils$(OBJEXT) \
	   flrstoragebase$(OBJEXT) \
	   flrdbop$(OBJEXT) \
	   flrbtdbop$(OBJEXT) \
	   flrshdirect$(OBJEXT) \
	   flrdynmod$(OBJEXT) \
	   flrdynrule$(OBJEXT) \
	   flrsemantics$(OBJEXT) \
	   flrnegation$(OBJEXT) \
	   flrtables$(OBJEXT) \
	   flrimportedcalls$(OBJEXT) \
	   flrerrhandler$(OBJEXT) \
	   flrdecode$(OBJEXT)  \
	   flrcanon$(OBJEXT)  \
	   flrmetaops$(OBJEXT)  \
	   flrtrim$(OBJEXT) \
	   flrtruthvalue$(OBJEXT) \
	   flrexport$(OBJEXT) \
	   flroptimize$(OBJEXT) \
	   flrnewoid$(OBJEXT) \
	   flrhooks$(OBJEXT) \
	   flrimport$(OBJEXT) \
	   flrcallflora$(OBJEXT) \
	   flrcommon_definitions$(OBJEXT) \
	   flrrulesigops$(OBJEXT) \
	   flrdelaysupport$(OBJEXT) \
	   flrunify_handlers$(OBJEXT) \
	   flrprefixdef$(OBJEXT)

OPTIONS = [optimize,ti_all]

.SUFFIXES: $(PROLOGEXT) $(OBJEXT)

ALL:: $(ALLOBJS)

CLEAN :
	-@erase *~
	-@erase *$(OBJEXT)
	-@erase *.bak
	-@erase .#*


$(PROLOGEXT)$(OBJEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora,mc(%|fF,$(OPTIONS)). halt."


