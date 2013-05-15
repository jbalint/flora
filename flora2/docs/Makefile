## File:      flora2/docs/Makefile
##
## Author(s): Michael Kifer
##
## Contact:   flora-users@lists.sourceforge.net
##
## Copyright (C) by
##      The Research Foundation of the State University of New York, 1999-2013.
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
##
##


all:  flora2-manual.pdf flora-packages.pdf

flora2-manual.dvi: flora2-manual.tex
	@echo
	@echo Compiling flora2-manual.tex
	latex flora2-manual
	@echo
	@echo Making bibliography...
	bibtex flora2-manual
	@echo
	@echo Making index...
	makeindex flora2-manual
	@echo
	@echo Recompiling...
	latex flora2-manual
	latex flora2-manual

flora2-manual.pdf: flora2-manual.dvi
	@echo
	@echo Making pdf for flora2-manual
	dvipdf flora2-manual

flora-packages.dvi: flora-packages.tex flora-persistence.tex flora-flrxml.tex flora-protege.tex
	@echo
	@echo Compiling flora-packages.tex
	latex flora-packages
	latex flora-packages
	makeindex flora-packages

flora-packages.pdf: flora-packages.dvi
	@echo
	@echo Making pdf for flora-packages
	dvipdf flora-packages

clean:
	/bin/rm -f  *.bak *~ .*~ .#*

veryclean: clean
	/bin/rm -f  *.aux *.bbl *.blg *.dvi *.idx *.ilg *.ind *.log \
			*.out *.pdf *.ps *.toc
