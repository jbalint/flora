## File:      flora2/Makefile
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
PROLOGEXT=.P
PROLOGHEADEREXT=.H

FLORADIR = .

ALLOBJS = flrarguments${OBJEXT} \
	  flrcomposer${OBJEXT} \
	  flrcompiler${OBJEXT} \
	  flrcoder${OBJEXT} \
	  flrdependency${OBJEXT} \
	  flrlexer${OBJEXT} \
	  flrlibman${OBJEXT} \
	  flrnodefp${OBJEXT} \
	  flrnowsp${OBJEXT} \
	  flroperator${OBJEXT} \
          flrparser${OBJEXT} \
	  flrporting${OBJEXT} \
	  flrpretifydump${OBJEXT} \
	  flrprint${OBJEXT} \
	  flrprolog${OBJEXT} \
	  flrregistry${OBJEXT} \
	  flrshell${OBJEXT} \
	  flrundefined${OBJEXT} \
	  flrundefhook${OBJEXT} \
	  flrutils${OBJEXT} \
	  flrversion${OBJEXT} \
	  flrwraparound${OBJEXT} \
	  flrsynonym${OBJEXT} \
	  flrsimpleprimitive${OBJEXT} \
	  flrwrapper${OBJEXT}


FLORA_CHAR_DEFS = $(FLORADIR)/flrincludes/flora_characters.flh

FLORA_INCLUDES_DIR = flrincludes

FLORA_TERMS = $(FLORA_INCLUDES_DIR)/flora_terms.flh
FLORA_TABLING_METHODS = $(FLORA_INCLUDES_DIR)/flora_tabling_methods.flh
FLORA_DEFAULT_TABLING = $(FLORA_INCLUDES_DIR)/.flora_default_tabling
FLORA_ERRORS = $(FLORA_INCLUDES_DIR)/flora_errors.flh
FLORA_PORTING = $(FLORA_INCLUDES_DIR)/flora_porting.flh
FLORA_EXTENSIONS = $(FLORA_INCLUDES_DIR)/flora_extensions.flh
FLORA_WRAP = $(FLORA_INCLUDES_DIR)/flora_wrap.flh

OPTION = [optimize,ti_all,spec_repr]
#OPTION = [optimize]

# PROLOG is passed as an argument to make. Default is none, to trigger an error
PROLOG=none
PROLOG_COMMAND = $(PROLOG) -s -m 60000 -c 10000 -e 'segfault_handler(warn).'

# Make sure warnings are saved in a file.
SVFILE = '$(FLORADIR)/.flora_top_warn.tmp'
STDWARN = 3
STDERR = 2
HDRMSG = "While compiling  .../flora2:"

.SUFFIXES: $(PROLOGEXT) $(PROLOGHEADEREXT) $(OBJEXT)


# acceptable targets are all (default), system, base, top
all: core_internal libs pkgs misc showerrors

system: core libs showerrors

base: core showerrors

showerrors:
	@cat $(FLORADIR)/.flora*.tmp
	@rm $(FLORADIR)/.flora*.tmp

top: cleantemp init $(ALLOBJS) finish
	./CompileChangedFiles.sh $(PROLOG_COMMAND)
	cd datatypes && $(MAKE) PROLOG=$(PROLOG)
	@cat $(SVFILE)

core_internal: top
	cd closure && $(MAKE) PROLOG=$(PROLOG)
	cd genincludes && $(MAKE) PROLOG=$(PROLOG)
	cd syslib && $(MAKE) PROLOG=$(PROLOG)
	cd debugger && $(MAKE) PROLOG=$(PROLOG)

core: top
	cd closure && $(MAKE) PROLOG=$(PROLOG)
	cd genincludes && $(MAKE) PROLOG=$(PROLOG)
	cd syslib && $(MAKE) PROLOG=$(PROLOG)
	cd debugger && $(MAKE) PROLOG=$(PROLOG)
	@cat $(FLORADIR)/.flora*.tmp
	@rm $(FLORADIR)/.flora*.tmp

libs:
	cd lib && $(MAKE) PROLOG=$(PROLOG)
	cd AT && $(MAKE) PROLOG=$(PROLOG)

misc:
	cd pkgs && $(MAKE) PROLOG=$(PROLOG)
	cd demos && $(MAKE) PROLOG=$(PROLOG)
	-cd docs && $(MAKE) PROLOG=$(PROLOG)


${FLORA_TABLING_METHODS} : ${FLORA_DEFAULT_TABLING}
	./touch.sh  $(FLORA_TABLING_METHODS)


%$(OBJEXT) : %$(PROLOGEXT) $(FLORA_TERMS) $(FLORA_PORTING) $(FLORA_EXTENSIONS) $(FLORA_WRAP)
	@echo 'mc($*,$(OPTION)).' >> cmd...

%$(PROLOGEXT) : %$(PROLOGHEADEREXT)
	./touch.sh $@

flrversion${OBJEXT}: flrversion${PROLOGEXT} version.flh
	@echo 'mc(flrversion,$(OPTION)).' >> cmd...

flrporting${OBJEXT}: flrporting${PROLOGEXT} version.flh
	@echo 'mc(flrporting,$(OPTION)).' >> cmd...

flrlexer${OBJEXT} : flrlexer${PROLOGEXT} flrlexer.H $(FLORA_CHAR_DEFS) $(FLORA_TERMS) $(FLORA_ERRORS) $(FLORA_PORTING)
	@echo 'mc(flrlexer,$(OPTION)).' >> cmd...


flrcomposer${OBJEXT} : flrcomposer${PROLOGEXT} flrcomposer.H $(FLORA_CHAR_DEFS) $(FLORA_TERMS) $(FLORA_ERRORS) $(FLORA_PORTING)
	@echo 'mc(flrcomposer,$(OPTION)).' >> cmd...


flrparser${OBJEXT} : flrparser${PROLOGEXT} flrparser.H $(FLORA_TERMS) $(FLORA_ERRORS) $(FLORA_PORTING)
	@echo 'mc(flrparser,$(OPTION)).' >> cmd...


flrcompiler${OBJEXT} : flrcompiler${PROLOGEXT} flrcompiler.H $(FLORA_TERMS) $(FLORA_ERRORS) $(FLORA_PORTING)
	@echo 'mc(flrcompiler,$(OPTION)).' >> cmd...


flrcoder${OBJEXT} : flrcoder${PROLOGEXT} flrcoder.H $(FLORA_CHAR_DEFS) $(FLORA_TERMS) $(FLORA_ERRORS) $(FLORA_PORTING)
	@echo 'mc(flrcoder,$(OPTION)).' >> cmd...


flrutils${OBJEXT} : flrutils${PROLOGEXT} flrutils.H $(FLORA_CHAR_DEFS) $(FLORA_TERMS) ${FLORA_TABLING_METHODS}  $(FLORA_PORTING)
	@echo 'mc(flrutils,$(OPTION)).' >> cmd...



init:
	@/bin/rm -f $(FLORADIR)/.*flora*.tmp
	@echo "write($(STDWARN),'-------------- Warnings/Errors --------------------'), nl($(STDWARN))." > cmd...
	@echo "write($(STDWARN),'$(HDRMSG)'), nl($(STDWARN))." >> cmd...
	@echo "file_flush($(STDWARN),_)." >> cmd...
	@echo "['./flora2']." >> cmd...hdr
	@echo "retractall(xpp_options(_))." >> cmd...hdr
	@echo "import bootstrap_flora/0 from flora2." >> cmd...hdr
	@echo "file_reopen($(SVFILE),a,$(STDWARN),_)." >> cmd...hdr
	@echo "file_clone($(STDWARN),$(STDERR),_)." >> cmd...hdr
	@echo "bootstrap_flora." >> cmd...hdr


finish:
	@echo "write($(STDWARN),'-------------------- End --------------------------'), nl($(STDWARN))." >> cmd...


clean: cleantemp
	/bin/rm -f core *~ .*~ *${OBJEXT} *.O *.bak ../flora2${OBJEXT} .#*
	/bin/rm -f .*.tmp .flora_path* .prolog_path*
	cd closure && $(MAKE) clean
	cd datatypes && $(MAKE) clean
	cd docs && $(MAKE) clean
	cd genincludes && $(MAKE) clean
	cd syslib && $(MAKE) clean
	cd lib && $(MAKE) clean
	cd AT && $(MAKE) clean
	cd debugger && $(MAKE) clean
	cd p2h && $(MAKE) clean
	cd pkgs && $(MAKE) clean
	cd demos && $(MAKE) clean
	/bin/rm -f headerinc/*~ headerinc/.*~
	/bin/rm -f syslibinc/*~ syslibinc/.*~
	/bin/rm -f libinc/*~ libinc/.*~
	/bin/rm -f includes/*~ includes/.*~
	/bin/rm -f flrincludes/*~ flrincludes/.*~

cleantemp:
	/bin/rm -f "$(HOME)"/.xsb/flora*/*${PROLOGEXT} "$(HOME)"/.xsb/flora*/*${OBJEXT}

veryclean: clean
	cd docs && $(MAKE)  veryclean
	cd emacs && $(MAKE) veryclean


.DONE:
	@echo Done
