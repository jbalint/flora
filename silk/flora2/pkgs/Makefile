## File:      flora2/pkgs/Makefile
## Author(s): kifer
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

FLORADIR=..

ALL = 	flrxml_aux${PROLOGEXT} javaAPI${PROLOGEXT} \
	gclpe${PROLOGEXT} \
	ogclp${PROLOGEXT} \
	sgclp${PROLOGEXT} \
	ogclpe${PROLOGEXT} \
	atck2${PROLOGEXT} \
	atck3${PROLOGEXT} \
	atck1alt${PROLOGEXT} \
	persistentmodules${PROLOGEXT} \
	prettyprint${PROLOGEXT}

Option = [optimize]

#-----------------------------------------------------------------------#
#
# Self-make: Version 1.4.1
#
PROLOG = none
PROLOG_COMMAND = $(PROLOG) -i -s -m 80000 -c 10000 -e 'segfault_handler(warn).'
#
#-----------------------------------------------------------------------#

# Make sure warnings are saved in a file.
SVFILE = '$(FLORADIR)/.flora_pkg_warn.tmp'
STDWARN = 3
STDERR = 2
HDRMSG = "While compiling .../flora2/pkgs:"


# suffix rules
.SUFFIXES: $(PROLOGEXT) .flr

# We should have touch *.flr here when there will be packages
all: clean init recompile

recompile: $(ALL) finish
	@touch cmd...
	$(PROLOG_COMMAND) < cmd...
	@rm cmd...
	@cat $(SVFILE)

flrxml_aux$(PROLOGEXT):
	echo "import ('_compile')/1 from flora2. '_compile'($* >> flrxml)." >> cmd...

.flr${PROLOGEXT}:
	echo "import ('_compile')/1 from flora2. '_compile'($*)." >> cmd...

init:
	/bin/rm -f $(SVFILE)
	@echo "asserta(library_directory('..'))." >> cmd...
	@echo "['../flora2']." >> cmd...
	@echo "import bootstrap_flora/0 from flora2." >> cmd...
	@echo "bootstrap_flora." >> cmd...
	@echo "file_reopen($(SVFILE),w,$(STDWARN),_)." >> cmd...
	@echo "file_clone($(STDWARN), $(STDERR),_)." >> cmd...
	@echo "write($(STDWARN),'-------------- Warnings/Errors --------------------'), nl($(STDWARN))." >> cmd...
	@echo "write($(STDWARN),'$(HDRMSG)'), nl($(STDWARN))." >> cmd...
	@echo "file_flush($(STDWARN), _)." >> cmd...

finish:
	@echo "write($(STDWARN),'-------------------- End --------------------------'), nl($(STDWARN))." >> cmd...


.DONE:
	echo Done

clean:
	/bin/rm -f core *$(PROLOGEXT) *${OBJEXT} *.O *.fdb *.fld *.flt *.fls *.bak *~ .*~ .#*
