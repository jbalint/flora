## File:      flora2/pkgs/NMakefile.mak - Make file for Microsoft NMAKE
##
## Author(s): Michael Kifer
##
## Contact:   kifer@cs.stonybrook.edu
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



!IF EXISTS (..\.prolog_path_wind) 
!INCLUDE ..\.prolog_path_wind
!ENDIF

OBJEXT = .xwam
PROLOGEXT = .P

ALLOBJS = flrxml_aux$(PROLOGEXT) \
	  javaAPI$(PROLOGEXT) \
	  persistentmodules$(PROLOGEXT) \
	  prettyprint$(PROLOGEXT)

OPTIONS=[optimize]

.SUFFIXES: $(PROLOGEXT) .flr

ALL: $(ALLOBJS)


flrxml_aux$(PROLOGEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. import ('_compile')/1 from flora2. '_compile'(%|fF >> flrxml). halt."

.flr$(PROLOGEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. import ('_compile')/1 from flora2. '_compile'(%|fF). halt."


CLEAN:
	-@if exist *$(PROLOGEXT) erase *$(PROLOGEXT)
	-@if exist *$(OBJEXT) erase *$(OBJEXT)
	-@if exist *.flh erase *.fdb
	-@if exist *.fld erase *.fld
	-@if exist *.flt erase *.flt
	-@if exist *.fls erase *.fls
	-@if exist *.fls2 erase *.fls2
	-@if exist *.flm erase *.flm
	-@if exist *~ erase *~
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*