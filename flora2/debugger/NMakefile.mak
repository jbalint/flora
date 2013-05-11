## File:      flora2debugger/NMakefile.mak - Make file for Microsoft NMAKE
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

ALLOBJS=  flrdebugger$(OBJEXT) \
	flrtabledump$(OBJEXT) \
	flrterminyzer$(OBJEXT) \
	dynamic_data.dat \
	static_data.dat

OPTIONS=[optimize]

.SUFFIXES:  .in .dat $(PROLOGEXT) .H $(OBJEXT)

ALL:: $(ALLOBJS)

CLEAN :
	-@if exist *~ erase *~
	-@if exist *$(OBJEXT) erase *$(OBJEXT)
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*
	-@if exist *.dat erase *.dat

$(PROLOGEXT)$(OBJEXT):
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora,mc(%|fF,$(OPTIONS)). halt."

static_data.dat: static_data.in
	copy static_data.in static_data.dat

dynamic_data.dat: dynamic_data.in
	$(PROLOG) -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. import flrWrapAround/1 from flrwraparound. flWrapAround(%|fF). halt.


