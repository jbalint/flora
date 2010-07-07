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

ALLOBJS = flrpatch.flh flrpreddef.flh flrindex_P.flh \
	  flrdyndeclare.flh \
	  flrdyna.flh flrdynz.flh \
	  flrexportcheck.flh \
	  flrtable.flh flrhilogtable.flh \
	  flrdefeasible.flh \
	  flropposes.flh \
	  flropposes_data.flh \
	  flrrefreshtable.flh

PROLOG = none

PROLOG_COMMAND = $(PROLOG) -s -m 60000 -c 10000 -e 'segfault_handler(warn).'

FLORA_INCLUDES_DIR = ../flrincludes

FLORA_TERMS = $(FLORA_INCLUDES_DIR)/flora_terms.flh
FLORA_WSPREDICATES = $(FLORA_INCLUDES_DIR)/flora_wspredicates.flh

# Make sure warnings are saved in a file.
SVFILE = '$(FLORADIR)/.flora_genincl_warn.tmp'
STDWARN = 3
STDERR = 2
HDRMSG = "While compiling .../flora2/genincludes:"

# suffix rules
.SUFFIXES: .fli .flh

all: clean init $(ALLOBJS) finish
	@$(FLORADIR)/touch.sh cmd...
	$(PROLOG_COMMAND) < cmd...
	@rm cmd...
	@cat $(SVFILE)


%.flh: %.fli $(FLORA_TERMS) $(FLORA_WSPREDICATES)
	echo 'flWrapAround($*).' >> cmd...


init:
	/bin/rm -f $(SVFILE)
	@echo "asserta(library_directory('..'))." >> cmd...
	@echo "['../flora2']." >> cmd...
	@echo "import bootstrap_flora/0 from flora2." >> cmd...
	@echo "bootstrap_flora." >> cmd...
	@echo "[flrutils]." >> cmd...
	@echo "[flrwraparound]." >> cmd...
	@echo "file_reopen($(SVFILE),w,$(STDWARN),_)." >> cmd...
	@echo "file_clone($(STDWARN),$(STDERR),_)." >> cmd...
	@echo "write($(STDWARN),'-------------- Warnings/Errors --------------------'), nl($(STDWARN))." >> cmd...
	@echo "write($(STDWARN),'$(HDRMSG)'), nl($(STDWARN))." >> cmd...
	@echo "file_flush($(STDWARN),_)." >> cmd...


finish:
	@echo "write($(STDWARN),'-------------------- End --------------------------'), nl($(STDWARN))." >> cmd...


clean:
	/bin/rm -f *~ .*~ *.flh *.bak .#* cmd...


.DONE:
	@echo Done
