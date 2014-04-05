/* File:      flrparser.H
**
** Author(s): Guizhen Yang
**
** Contact:   flora-users@lists.sourceforge.net
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

:- dynamic FLORA_INCLUDE_DEPENDENCY/2.
:- table FLORA_INCLUDE_DEPENDENCY_CLOSURE/2.

:- import
	memberchk/2,
	member/2,
	subset/2,
	length/2,
	append/3
   from basics.

:- import
	flora_abort/2,
	flora_set_counter/2,
	flora_get_counter/2,
	flora_increment_counter/4,
	flora_concat_items/2,
	flora_concat_atoms/2
   from flrporting.

:- import
	flora_compiletime_uriprefix_expansion/2,
	flora_runtime_uriprefix_expansion/3
   from flrprefixdef.

:- import flora_error_line/2 from flrprint.

:- import
	flora_current_compile_filename/2,
	flora_begin_file/1,
	flora_end_file/1,
	flora_reset_charpos/0
   from flrlexer.

:- import flora_conflict_operator/3 from flroperator.

:- import
	flora_reserved_builtin/2,
	flora_nodefp_exception/2,
	flora_nodefp/2
   from flrnodefp.

:- import flora_nowsp/2 from flrnowsp.

:- import
	flora_prlgdef_repl/4,
	flora_prlgdef/3,
	flora_prlgdef/2
   from flrprolog.

/*
:- import
	flora_retractall_substitute/1
   from flrutils.
*/

:- import
	flora_prim_argdef/3,
	flora_set_argdef/4,
	flora_argdef/4
   from flrarguments.

:- import
	flora_delayed_builtin_literal/2
   from FLDELAYSUPPORTMOD.

:- import flora_system_module/1 from flrlibman.

:- import flora_special_builtin_synonym/2 from flrsynonym.

:- import
	flora_synonymous_type_names/2
   from flrdatatype.
:- import
	flora_parse_datatype/4
   from flrdatatype_parse.

:- import
	flora_simple_primitive/4
   from flrsimpleprimitive.

:- import
	flora_abolish_table_predicate/1
   from flrtables.

:- import
	flora_write_varnames/1
   from flrdecode.

:- import
	flrterm_vars_split/4
   from flora_ground.

:- import
	put_attr/3,
	get_attr/3,
	del_attr/2,
	install_verify_attribute_handler/4,
	install_attribute_portray_hook/3
   from machine.

:- export
	flora_reset_parser/0,
	FLORA_INCLUDE_DEPENDENCY_CLOSURE/2,

	flwrite/1,
	flwriteline/1,
	flwritelinelist/1,
	flwrite_stderr/1,
	flwriteline_stderr/1,
	flwritelinelist_stderr/1,
	to_Cranial_list/3,
	
	flora_get_flatomvar_name/2,
	flora_get_flatom_name/2,
	flora_get_module_from_spec/3,
	flora_parse_term_external/3,
	parsing_error/3,
	flora_parse/3,
	fldirective_struct/3,
	flatom_struct/3,
	flterm_struct/4,
	flconjunct_struct/3,
	fldisjunct_struct/3,
	flthismodule_struct/1,
	flnumber_struct/3.
