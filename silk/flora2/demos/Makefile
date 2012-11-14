## File:      flora2/demos/Makefile
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



OBJEXT=.xwam
PROLOGEXT=.P

FLORADIR = ..

ALL = 	aggregate${PROLOGEXT} benchmark${PROLOGEXT} \
	clpdemo${PROLOGEXT} default${PROLOGEXT} family_obj${PROLOGEXT} \
	family_rel${PROLOGEXT} flogic_basics${PROLOGEXT}\
	metavar${PROLOGEXT} mix${PROLOGEXT} module1${PROLOGEXT}\
	mod1${PROLOGEXT} \
	mono_inherit${PROLOGEXT} rel_ops${PROLOGEXT}\
	tree_traversal${PROLOGEXT} diamond${PROLOGEXT}\
	btupdates${PROLOGEXT} pretty${PROLOGEXT}

Option = [optimize]


#-----------------------------------------------------------------------#
#
# Self-make: Version 1.4.1
#
PROLOG = none
PROLOG_COMMAND = $(PROLOG) -i -s -m 60000 -c 10000 -e 'segfault_handler(warn).'
#
#-----------------------------------------------------------------------#

# Make sure warnings are saved in a file.
SVFILE = '$(FLORADIR)/.flora_demos_warn.tmp'
STDWARN = 3
STDERR = 2
HDRMSG = "While compiling .../flora2/demos:"


# suffix rules
.SUFFIXES: ${PROLOGEXT} .flr

all: init recompile

recompile: $(ALL) finish
	./CompileChangedFiles.sh $(PROLOG_COMMAND)
	@cat $(SVFILE)

.flr${PROLOGEXT}:
	echo "import ('_compile')/1 from flora2. '_compile'($*)." >> cmd...

init:
	rm -f $(SVFILE)
	@echo Initializing...
	@echo "write($(STDWARN),'-------------- Warnings/Errors --------------------'), nl($(STDWARN))." >> cmd...
	@echo "write($(STDWARN),'$(HDRMSG)'), nl($(STDWARN))." >> cmd...
	@echo "file_flush($(STDWARN), _)." >> cmd...
	@echo "asserta(library_directory('..'))." >> cmd...hdr
	@echo "['../flora2']." >> cmd...hdr
	@echo "import bootstrap_flora/0 from flora2." >> cmd...hdr
	@echo "bootstrap_flora." >> cmd...hdr
	@echo "file_reopen($(SVFILE),a,$(STDWARN),_)." >> cmd...hdr
	@echo "file_clone($(STDWARN), $(STDERR),_)." >> cmd...hdr

finish:
	@echo "write($(STDWARN),'-------------------- End --------------------------'), nl($(STDWARN))." >> cmd...


.DONE:
	echo Done

clean:
	/bin/rm -f *${PROLOGEXT} *${PROLOGEXT}_gpp *${OBJEXT} *.O *.bak *.fdb *.fld *.flt *.fls *.fls *.flm *.con *~ .*~ .#* cmd*
