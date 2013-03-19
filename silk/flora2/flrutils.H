/* File:      flrutils.H
**
** Author(s): Guizhen Yang
**
** Contact:   kifer@cs.stonybrook.edu
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2008.
**
** All rights reserved.
**
** For information about licensing terms, please see
** http://silk.projects.semwebcentral.org/flora2-license.html
**
**
*/


:- compiler_options([xpp_on]).

#include "flora_porting.flh"
#include "flora_terms.flh"


:- import
	put_attr/3,
	term_psc/2,
	term_new/2
   from machine.

:- import
	flora_abort/1,
	flora_abort/2,
	flora_user_floradir/1,
	flora_file_op/2,
	flora_file_op/3,
	flora_module_path_get/1,
	flora_slash/1,
	flora_cputime/1,
	flora_walltime/1,
	flora_set_counter/2,
	flora_get_counter/2,
	flora_increment_counter/4,
	flora_concat_atoms/2,
	flora_concat_items/2,
	flora_match_substring/3,
	flora_copy_input/2,
	flora_write_atom/1,
	flora_delete_from_list/3,
	flora_running_under/1
   from flrporting.

:- import
	length/2,
	memberchk/2,
	member/2,
	append/3
   from basics.

:- import
	file_open/3,
	copyIOport/2
   from file_io.

:- import current_loaded_file/1 from consult.

:- import xpp_options/1, xpp_process_file/3 from parse.

:- import
	parse_filename/4
   from machine.

:- import process_control/2 from shell.

:- import xpp_process_file/3 from parse.

:- import 
	flora_db_insert_base_fast/2,
	flora_db_commit/1,
	flora_db_reclaim_space/1,
	flora_db_delete_all/1,
	flora_storage_find_fact/2
   from flrstoragebase.

:- import
	storage_insert_fact/3
   from storage.

:- import incr_flora_update_counter/0 from flrnegation.

:- import flora_call_hooks/5 from flrhooks.

:- import
	bootstrap_flora/0,
	'_isloaded'/1
   from flora2.

:- import
	flora_reset_lexer/0,
	flora_reset_lexer/1,
	flora_tokens/2,
	flora_token_text/6,
	flora_symbol_token_struct/6,
	flora_rule_delimeter_struct/6,
	flora_blank_line/1,
	flora_current_compile_filename/1,
        flora_compile_filename_by_token/2
   from flrlexer.

:- import
	flora_reset_composer/0,
	flora_compose/3,
	flora_nth_token/2
   from flrcomposer.

:- import flora_reset_operator/0 from flroperator.

:- import
	flora_user_modular_prlgdefs/2,
	flora_reset_modular_prolog/0,
	flora_reset_prolog/0
   from flrprolog.

:- import
	flora_parse_term_external/3,
	flora_parse/3
   from flrparser.

:- import
	flora_clear_compilation_permaoptions/0,
	flora_reset_compiler/1,
	flora_compile_pathexp/3,
	flora_compile/6,
        flora_compile_add/5,
	flora_get_compilation_liboptions/1,
	symbol/7,
	nowarn_symbol/5,
	make_symbol_context_status/12,
	compiling_error/3,
	is_flvariable/3
   from flrcompiler.

:- import
	%%flora_divide_program/3,
	flora_coder_write_prolog_bridge_rule/3,
	flora_coder_write_conditional_prolog_bridge_rule/2,
	flora_extern_code/2,
	flora_build_struct/7,
	flora_intern_code/4
   from flrcoder.

%% support for undefinedness
:- import 
	flora_debug_code/3
   from flrundefined.

:- import
	flora_configuration/2,
	flora_storage_registry/1,
	flora_trailer_registry/2,
	flora_used_udf_registry/5,
	flora_defined_udf_registry/4,
	flora_modular_prolog_registry/3,
	flora_module_registry/1
   from flrregistry.

:- import
	flora_current_out_nl/0,
	flora_current_out_string/1,
	flora_current_out_string/2,
	flora_current_out_line/1,
	flora_current_out_line/2,

	flora_stderr_nl/0,
	flora_stderr_string/1,
	flora_stderr_string/2,

	flora_stdwarn_nl/0,
	flora_stdwarn_string/1,
	flora_stdwarn_string/2,
	
	flora_error_indentline/0,
	flora_warning_indentline/0,
	
	flora_error_line/1,
	flora_error_line/2,
	
	flora_warning_line/1,
	flora_warning_line/2,
	
	flora_loader_message/1,
	flora_loader_message/2,

	flora_loader_msg_nl/0,
	%%flora_stdmsg_nl/0,
	

	%%flora_message_line/1,
	flora_message_line/2
   from flrprint.

:- import
	flora_include/2,
	flora_sysmod_file/3
   from flrlibman.

:- import P2H_PREDICATE/4 from prolog2hilog.

:- import prettyprint_stdin/0 from flrpretifydump.

:- import
	flora_modularize_atom/3,
	flora_check_module_name/1,
	valid_flora_module_name/1,
	flora_is_system_module_name/1,
	flora_fdb_storage_name/2,
	flora_module_name_error/1,
	%% support for undefinedness
	flora_fld_storage_name/2,
	flora_fls_storage_name/1,
	flora_fls_storage_name/2
   from flrwrapper.

:- import      
	flora_decode_oid_as_atom/2,
	flora_write_fact/1,
	flora_write_rule_head/1,
	flora_write_oid/1,
	flora_write_rule_body/1
   from flrdecode.

:- import
        matching_rule_signature/6
   from flrcanon.

:- import check_for_dependencies/2 from flrdependency.

:- dynamic flora_xpp_extra_options/1.

:- dynamic flora_maxerr(_), flora_maxwarn(_).
:- index(flora_maxerr/1,0).
:- index(flora_maxwarn/1,0).

:- dynamic flora_compiler_environment(_,_).

:- dynamic flora_warnings_level(_).

:- export
	flora_set_maxerrors/1,
	flora_set_maxwarnings/1,
	flora_get_maxwarnings/1,
	flora_retractall_substitute/1,

	flora_compile_util/1,
	flora_compile_util/2,
	flora_compile_system_module/1,
	flora_load_module_util/1,
	flora_load_module_util/2,
        flora_save_module_util/1,
        flora_save_module_util/2,
	FL_DUMP/1,
	flora_locate_file/3,
	flloadtrailer/2,
	fltrailersemantics/2,
	flora_end_of_input/1,
	flora_not_end_of_input/1,
	flora_shell_command_line/3,
	flora_check_filename/2,
	flora_set_xpp_options_for_compile/0,
	flora_set_xpp_options_for_compile/1,
	flora_set_xpp_options_for_compile/2,
	flora_set_xpp_options_for_read/0,
	flora_set_xpp_options_for_read/1,
	flora_set_xpp_options_for_read/2,
	flora_set_xpp_options_for_prolog_compile/1,
	flora_clear_xpp_options/0,
        flora_add_xpp_options/1,
	flora_replace_xpp_options/1,

	flora_copy_and_preprocess/3,
	flora_list2conjunct/2,

	flora_reclaim_storage_space/0,
	flora_commit_storage/0,
	flora_loaddyn_data/3,

	flora_compiler_environment/2,
	flora_cleanup_udf/1,

	flora_put_attr/3,
	flora_disable_attributed_variables/0,
	flora_enable_attributed_variables/0,
	flora_when/2,
	flora_experimenting_with/1,

	flora_read_canonical_and_insert/2,
	flora_read_symbols_canonical_and_insert/3,
	flora_read_descriptor_metafacts_canonical_and_insert/0,
	flora_load_system_module_util/1,
	flora_measure_time/2,
	
	flora_add_module_dyn/1,
	flora_add_module_dyn/2, 
	flora_compile_add/2, 
	flora_compile_add/1,

	flora_read_then_parse/2,
	flora_read_then_parse/3,
	flora_read_then_parse_string/3,

	flora_read_parse_compile_build_term/3,
	flora_read_parse_compile_build_term/4,
	flora_read_parse_compile_build_term_list/3,
	flora_read_parse_compile_build_loop/3,

	flora_patch_full_filename/1,

	incremental_tabling_in_effect/1,
	flora_read_from_source/2,

	flora_token_index_to_line/2,

	flora_warnings_level/1,
        flora_coder_error/1.
