## File:      flora2/syslib/Makefile
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


OBJEXT=.xwam
PROLOGEXT = .P
PROLOGHEADEREXT=.H

PROLOG = none
FLORADIR = ..

ALLOBJS = flranswer$(OBJEXT) \
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
	  flrerrhandler$(OBJEXT)  \
	  flrdecode$(OBJEXT)  \
	  flrcanon$(OBJEXT)  \
	  flrmetaops$(OBJEXT)  \
	  flrtrim$(OBJEXT) \
	  flrtruthvalue$(OBJEXT) \
	  flrexport$(OBJEXT) \
	  flroptimize$(OBJEXT) \
	  flrnewoid$(OBJEXT) \
	  flrimport$(OBJEXT) \
	  flrhooks$(OBJEXT) \
	  flrcallflora$(OBJEXT) \
	  flrcommon_definitions$(OBJEXT) \
	  flrrulesigops$(OBJEXT) \
	  flrdelaysupport$(OBJEXT) \
	  flrhypothetical$(OBJEXT) \
	  flrcheckcard$(OBJEXT) \
	  flrunify_handlers$(OBJEXT) \
	  flrprefixdef$(OBJEXT)

FLORA_INCLUDES_DIR = ../flrincludes
DYN_INCLUDES_DIR = ../includes

FLORA_TERMS = $(FLORA_INCLUDES_DIR)/flora_terms.flh
FLORA_ERRORS = $(FLORA_INCLUDES_DIR)/flora_errors.flh
FLRHEADER = $(DYN_INCLUDES_DIR)/flrheader.flh


OPTION = [optimize,ti_all,spec_repr]
#OPTION = [optimize]

PROLOG_COMMAND = $(PROLOG) -s -m 60000 -c 10000 -e 'segfault_handler(warn).'

# Make sure warnings are saved in a file.
SVFILE = '$(FLORADIR)/.flora_syslib_warn.tmp'
STDWARN = 3
STDERR = 2
HDRMSG = "While compiling .../flora2/syslib:"

.SUFFIXES: $(PROLOGEXT) $(PROLOGHEADEREXT) $(OBJEXT)

all: init $(ALLOBJS) finish
	./CompileChangedFiles.sh $(PROLOG_COMMAND)
	@cat $(SVFILE)


%$(OBJEXT): %$(PROLOGEXT) $(FLORA_TERMS)
	@echo 'mc($*,$(OPTION)).' >> cmd...

%$(PROLOGEXT) : %$(PROLOGHEADEREXT)
	../touch.sh $@

flrcontrol$(OBJEXT) : flrcontrol$(PROLOGEXT) $(FLORA_TERMS) $(XSB_STANDARD)
	@echo 'mc(flrcontrol,$(OPTION)).' >> cmd...

flrdisplay$(OBJEXT) : flrdisplay$(PROLOGEXT) $(FLORA_TERMS) $(XSB_STANDARD)
	@echo 'mc(flrdisplay,$(OPTION)).' >> cmd...

flrimport$(OBJEXT): flrimport$(PROLOGEXT) $(FLORA_TERMS) $(FLRHEADER)
	@echo 'mc(flrimport,$(OPTION)).' >> cmd...


init:
	/bin/rm -f $(SVFILE)
	@echo "write($(STDWARN),'-------------- Warnings/Errors --------------------'), nl($(STDWARN))." >> cmd...
	@echo "write($(STDWARN),'$(HDRMSG)'), nl($(STDWARN))." >> cmd...
	@echo "file_flush($(STDWARN),_)." >> cmd...
	@echo "asserta(library_directory('..'))." >> cmd...hdr
	@echo "['../flora2']." >> cmd...hdr
	@echo "import bootstrap_flora/0 from flora2." >> cmd...hdr
	@echo "bootstrap_flora." >> cmd...hdr
	@echo "file_reopen($(SVFILE),a,$(STDWARN),_)." >> cmd...hdr
	@echo "file_clone($(STDWARN),$(STDERR),_)." >> cmd...hdr


finish:
	@echo "write($(STDWARN),'-------------------- End --------------------------'), nl($(STDWARN))." >> cmd...


clean:
	/bin/rm -f core *~ .*~ *$(OBJEXT) *.O *.bak .#* cmd*


.DONE:
	@echo Done
