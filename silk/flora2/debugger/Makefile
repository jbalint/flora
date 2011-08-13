## File:      flora2/syslib/Makefile
##
## Author(s): Michael Kifer
##            Guizhen Yang
##
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
PROLOGEXT=.P

FLORADIR = ..

ALLOBJS = flrdebugger${OBJEXT} \
	flrtabledump${OBJEXT} \
	dynamic_data.dat \
	static_data.dat

FLORA_INCLUDES_DIR = ../flrincludes
DYN_INCLUDES_DIR = ../includes

FLORA_TERMS = $(FLORA_INCLUDES_DIR)/flora_terms.flh
FLORA_ERRORS = $(FLORA_INCLUDES_DIR)/flora_errors.flh
FLRHEADER = $(DYN_INCLUDES_DIR)/flrheader.flh

.SUFFIXES:  .in .dat ${PROLOGEXT} .H ${OBJEXT}


OPTION = [optimize]

PROLOG = none

PROLOG_COMMAND = $(PROLOG) -s -m 2000 -c 2000 -e 'segfault_handler(warn).'

# Make sure warnings are saved in a file.
SVFILE = '$(FLORADIR)/.flora_debug_warn.tmp'
STDWARN = 3
STDERR = 2
HDRMSG = "While compiling .../flora2/debugger:"


all: init $(ALLOBJS) finish
	@../touch.sh cmd...
	$(PROLOG_COMMAND) < cmd...
	/bin/rm -f cmd...
	@cat $(SVFILE)

static_data.dat: static_data.in $(FLORA_TERMS)
	cp -f static_data.in static_data.dat

%.dat: %.in $(FLORA_TERMS)
	@echo 'flWrapAround($*).' >> cmd...


%$(OBJEXT) : %$(PROLOGEXT) $(FLORA_TERMS) $(FLORA_PORTING) $(FLORA_EXTENSIONS)
	@echo 'mc($*,$(OPTION)).' >> cmd...


init:
	/bin/rm -f $(SVFILE)
	@echo "asserta(library_directory('..'))." >> cmd...
	@echo "['../flora2']." >> cmd...
	@echo "import bootstrap_flora/0 from flora2." >> cmd...
	@echo "bootstrap_flora." >> cmd...
	@echo "[flrwraparound]." >> cmd...
	@echo "file_reopen($(SVFILE),a,$(STDWARN),_)." >> cmd...
	@echo "file_clone($(STDWARN),$(STDERR),_)." >> cmd...
	@echo "write($(STDWARN),'-------------- Warnings/Errors --------------------'), nl($(STDWARN))." >> cmd...
	@echo "write($(STDWARN),'$(HDRMSG)'), nl($(STDWARN))." >> cmd...
	@echo "file_flush($(STDWARN),_)." >> cmd...


finish:
	@echo "write($(STDWARN),'-------------------- End --------------------------'), nl($(STDWARN))." >> cmd...


clean:
	/bin/rm -f *~ .*~ *$(OBJEXT) *.O *.dat *.bak .#*


.DONE:
	@echo Done
