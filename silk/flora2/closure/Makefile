## File:      flora2/closure/Makefile
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



FLORADIR = ..

ALLOBJS = flrcommon.flh \
	flrcommon_inh.flh \
	flrsigaxioms.flh \
	flrnoeqltrailer.flh \
	flrnoeqltrailer_inh.flh \
	flreqltrailer.flh \
	flreqltrailer_inh.flh \
	flrscalareql.flh \
	flrpredeql.flh \
	flrimportaxioms.flh \
	flrprednoeql.flh

PROLOG = none

PROLOG_COMMAND = $(PROLOG) -s -m 60000 -c 10000 -e 'segfault_handler(warn).'

FLORA_PRED_DEF = ../flrincludes/flora_wspredicates.flh

# Make sure warnings are saved in a file.
SVFILE = '$(FLORADIR)/.flora_closure_warn.tmp'
STDWARN = 3
STDERR = 2
HDRMSG = "While compiling .../flora2/closure:"

# suffix rules
.SUFFIXES: .flh .fli

all: clean init $(ALLOBJS) finish
	@../touch.sh cmd...
	$(PROLOG_COMMAND) < cmd...
	@rm cmd...
	@cat $(SVFILE)


%.flh: %.fli $(FLORA_PRED_DEF)
	@echo 'flWrapAround($*).' >> cmd...


init:
	/bin/rm -f $(SVFILE)
	@echo "asserta(library_directory('..'))." >> cmd...
	@echo "['../flora2']." >> cmd...
	@echo "import bootstrap_flora/0 from flora2." >> cmd...
	@echo "bootstrap_flora." >> cmd...
	@echo "import flWrapAround/1 from flrwraparound." >> cmd...
	@echo "file_reopen($(SVFILE),w,$(STDWARN),_)." >> cmd...
	@echo "file_clone($(STDWARN),$(STDERR),_)." >> cmd...
	@echo "write($(STDWARN),'-------------- Warnings/Errors --------------------'), nl($(STDWARN))." >> cmd...
	@echo "write($(STDWARN),'$(HDRMSG)'), nl($(STDWARN))." >> cmd...
	@echo "file_flush($(STDWARN),_)." >> cmd...


finish:
	@echo "write($(STDWARN),'-------------------- End --------------------------'), nl($(STDWARN))." >> cmd...


clean:
	/bin/rm -f *~ .*~ *.flh *.bak .#* cmd...
	/bin/rm -f includes/*~


.DONE:
	@echo Done
