## File:      flora2/closure/NMakefile.mak - Make file for Microsoft NMAKE
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


ALLOBJS = flrcommon.flh \
	  flrcommon_inh.flh \
	  flrsigaxioms.flh \
          flrnoeqltrailer.flh \
          flrnoeqltrailer_inh.flh \
	  flreqltrailer.flh \
	  flreqltrailer_inh.flh \
          flrscalareql.flh \
          flrimportaxioms.flh \
	  flrpredeql.flh \
	  flrprednoeql.flh

.SUFFIXES: .flh .fli

ALL: $(ALLOBJS)

CLEAN :
	-@if exist *~ erase *~
	-@if exist *.flh erase *.flh
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*

.fli.flh:
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. import flWrapAround/1 from flrwraparound. flWrapAround(%|fF). halt."

