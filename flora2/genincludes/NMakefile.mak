## File:      flora2/genincludes/NMakefile.mak - Make file for Microsoft NMAKE
##
## Author(s): Michael Kifer
##            Guizhen Yang
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



ALLOBJS = flrpatch.flh flrpreddef.flh flrindex_P.flh flrindex_static_P.flh \
	  flrdyndeclare.flh \
	  flrdyna.flh flrdynz.flh \
	  flrexportcheck.flh \
	  flrtable.flh flrtable_always.flh flrhilogtable.flh \
	  flrdefeasible.flh \
	  flropposes.flh \
	  flropposes_data.flh \
	  flrdescriptor_metafacts.flh \
	  flrrefreshtable.flh

.SUFFIXES: .fli .flh

ALL: $(ALLOBJS)

CLEAN :
	-@if exist *~ erase *~
	-@if exist *.flh erase *.flh
	-@if exist *.bak erase *.bak
	-@if exist .#* erase .#*

flrpreddef.flh:
	"$(PROLOG)" -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. flWrapAround(flrpreddef). halt."

flrindex_P.flh:
	"$(PROLOG)" -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. flWrapAround(flrindex_P). halt."


.fli.flh:
	"$(PROLOG)" -e "asserta(library_directory('..')). ['..\\flora2']. import bootstrap_flora/0 from flora2. bootstrap_flora. [flrwraparound]. import flWrapAround/1 from flrwraparound. flWrapAround(%|fF). halt." 
