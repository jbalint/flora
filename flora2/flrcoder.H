/* File:      flrcoder.H
**
** Author(s): Guizhen Yang
**
** Contact:   kifer@cs.stonybrook.edu
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2013.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**      http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
**
*/

:- compiler_options([xpp_on]).

#include "flora_terms.flh"

:- import format/2 from format.

:- import
	length/2,
	append/3
   from basics.

:- import term_to_atom/3 from string.

:- import
	%%flora_abort/1,
	flora_abort/2,
	%%flora_term_to_atom_quote/2,
	flora_double_quotes/2,
	flora_write_quoted_atom/1,
	flora_write_atom/1,
	flora_concat_atoms/2
   from flrporting.

%%:- import flratom_char_code/3 from flora_ground.

:- import flora_error_line/2 from flrprint.

:- import
	negate_wrapper/2,
	flora_module_predicate/4,
	flora_fdb_storage_name/2,
	flora_fdb_storage_name/2,

	flora_modularize_atom/3,

	%% Storage for skeletons of defined predicates
	flora_fld_storage_name/2
   from flrwrapper.

%% making is_flogic/4 dynamic and indexing on 1+2 makes the coder a bit faster
:- dynamic is_flogic(_,_,_,_).
:- index(is_flogic/4,1+2).

:- index(is_pratomlit/5,2).
:- index(is_prtermlit/5,2).
:- index(is_prtransactionaltermlit/5,2).
:- index(is_prtransactionalatomlit/5,2).


:- import flora_parse_datatype/4 from flrdatatype_parse.
:- import
	flora_special_datatype_internal_representation/2,
	flora_canonical_type_name/2
   from flrdatatype.

:- export
	flora_divide_program/3,
	flora_extern_code/2,
	flora_intern_code/4,
	flora_record_prefix_definition/2,
	flora_write_struct/3,
	flora_build_struct/7.

:- export
	flora_coder_write_prolog_bridge_rule/3,
	flora_coder_write_conditional_prolog_bridge_rule/2,
	is_prrule/3,
	is_prfact/2,
	is_prdirective/2,
	%%is_prlabeled_construct/3,
        is_prignoredep/2,
	is_prthismodule/1,
	is_prthisfdbstorage/1,
	is_pratom/2,
	is_pratom/3,
	is_prnumber/1,
	is_prnumber/3,
	is_prtransactionalnumber/3,
	is_prvariable/1,
	is_prvariable/3,
	is_prtransactionalvariable/3,
	is_prstring/1,
	is_prstring/3,
	is_prbuiltin_identifier/2,
	is_prbuiltin_identifier/3,
	is_prdatatype/4,
	is_prdatatypelist/1,
	is_prdatatypelist/2,
	is_prlist/4,
	is_prfdbstorage/3,
	is_prterm/4,
	is_goallogic/4,
	is_prcall/2,
	is_pratomlit/5,
	is_prtransactionalatomlit/5,
	is_prtermlit/5,
	is_prtransactionaltermlit/5,
	is_prprefixdef/3,
	is_prworkspace/3,
	is_florasyslib/5,
	is_prologterm/4,
	is_prologterm/5,
	is_prologliblit/4,
	is_prologliblit/5,
	is_prnewpred/4,
	is_prnewoid/3,
        is_prmvdcondef/6,
	is_primvdcondef/6,
	is_prreify/2,
	is_flogic/4,
	is_fllibdb/1,
	is_prfloralib/3.
