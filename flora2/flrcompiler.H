/* File:      flrcompiler.H
**
** Author(s): Guizhen Yang
**
** Contact:   flora-users@lists.sourceforge.net
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2013;
**      and Vulcan, Inc., 2008-2013.
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

#include "flora_porting.flh"
#include "flora_terms.flh"

:- index atomlit_struct/3-2.

:- import
	flora_increment_counter/4,
	flora_set_counter/2,
	flora_get_counter/2,
	flora_abort/2,
	%%flora_term_to_atom/2,
        %%flora_match_substring/3,
	flora_concat_atoms/2,
	flora_concat_items/2
    from flrporting.

:- import
	flrterm_vars_split/4,
	flratom_char_code/3
   from flora_ground.

:- import
	memberchk/2,
	member/2,
	subset/2,
	append/3,
	flatten/2,
	length/2
   from basics.

:- import
	put_attr/3,
	get_attr/3,
	del_attr/2,
	install_verify_attribute_handler/4,
	install_attribute_portray_hook/3
   from machine.

:- import
        %%concat_atom/2,
	substring/4
    from string.

:- import sort/2, keysort/2, findall/3 from setof.

:- import flora_define_operator/3 from flroperator.

:- import
	%%flora_define_prolog/1,
	flora_define_prolog/2,
	%%flora_define_prolog/3,
	flora_define_modular_prolog/2,
	flora_prlgdef_repl/4,
	flora_modular_prlgdef/2,
	flora_negatable_prlgdef/3,
	flora_prlgdef/3,
	flora_prlgdef/2
   from flrprolog.

:- import
	flora_clear_compiletime_uriprefixes/0,
	FLLIBPREFIXDEF/2
   from flrprefixdef.

:- import
	flora_current_compile_filename/1,
	flora_token_text/6
    from flrlexer.

:- import
	flora_token_rulenum/2,
	flora_nth_token/2
   from flrcomposer.

:- import
	flora_compiler_environment/2,
	flora_retractall_substitute/1,
	flora_token_index_to_line/2
   from flrutils.

:- import
	flora_intern_code/4,
	%%is_prscrambled_atom/3,
	%%is_prmodularized_atom/3,
	is_prologterm/4,
	is_prologterm/5,
        is_prvariable/1,
        is_prvariable/3,
        is_prtransactionalvariable/3,
        is_pratom/2,
        is_pratom/3,
        is_prnumber/1,
        is_prnumber/3,
	is_prbuiltin_identifier/2,
	is_prbuiltin_identifier/3,
        is_prdatatype/4,
	is_prdatatypelist/2,
        is_prtransactionalnumber/3,
        is_prstring/1,
        is_prstring/3,
        is_prfact/2,
	is_prfloralib/3,
	is_prterm/4
   from flrcoder.

:- import
	flora_modularize_atom/3,
	flora_scramble_atom/2
   from flrwrapper.

:- import
	flora_delayed_builtin_literal/2,
	flora_delayed_sensor_literal/3
   from FLDELAYSUPPORTMOD.
        
:- import flora_error_line/2 from flrprint.

:- import
	flora_get_flatomvar_name/2,
	flora_get_flatom_name/2,
	flatom_struct/3,
	flterm_struct/4,
	flconjunct_struct/3,
	flthismodule_struct/1
   from flrparser.

:- import
	flora_used_udf_registry/4
   from flrregistry.

:- import flora_nodefp/2 from flrnodefp.

:- import flora_simple_primitive/4 from flrsimpleprimitive.

:- dynamic compile_with_var_module(_).

:- dynamic dynrule_warnings(_).

:- dynamic symbol/7.
:- index(symbol/7,trie).

:- export 
	flora_clear_compilation_permaoptions/0,
	flora_compilation_context/1,
	flora_get_compilation_liboptions/1,
        flora_reset_newvar/0,
        flora_new_varobj/3,
	flora_reset_compiler/1, 
	flora_compile_pathexp/3,
	flora_compile_add/8,
	flora_compile/10,
	flora_clear_compilation_symbols/0,
	%%flora_compiler_permaoption/1,
	compiling_flrshell_command/0,
	symbol/7,
	nowarn_symbol/5,
	set_turnoff_symbol_warnings_flag/1,
	clear_turnoff_symbol_warnings_flag/0,
	make_symbol_context_status/12,
	symbol_warnings_flag/1,
	compiling_warning/3,
	compiling_error/3,
	set_production_mode/1,
	is_fltoken/3,
	is_fldirective/3,
	is_flvariable/3,
	no_errors_found/1.
