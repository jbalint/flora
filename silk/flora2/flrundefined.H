/* File:      flrundefined.H
**
** Author(s): Chang Zhao
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

:- dynamic term_seen(_).

:- import
	%%reverse/2,
	length/2
   from basics.

:- import
	flora_db_find_base/2,
	flora_db_insert_base/2
   from flrstoragebase.

:- import
	flora_concat_atoms/2,
	flora_concat_items/2
   from flrporting.

:- import 
        flora_abort/1,
        flora_coder_error/1
   from flrutils.

:- import flora_disabled_undefinedness_check_registry/3 from flrregistry.

:- import flora_prlgdef/2 from flrprolog.

:- import
	is_flogic/4,
	is_prrule/3,
	is_prfact/2,
	is_pratom/3,
	is_prvariable/3,
	is_prbuiltin_identifier/3,
	is_prtransactionalvariable/3,
	is_prterm/4,
	is_pratomlit/5,
	is_prtransactionalatomlit/5,
        is_prtermlit/5,
        is_prtransactionaltermlit/5,
        flora_write_struct/3
   from flrcoder.

:- import flora_current_out_line/1 from flrprint.

:- import
        flora_reset_newvar/0,
        flora_new_varobj/3
   from flrcompiler.

:- import 
        flora_decode_predicate/6,
        flora_module_predicate/4,
	flora_fdb_storage_name/2,
	flora_fld_storage_name/2,
        is_flora_callable_literal/1
   from flrwrapper.

:- import flora_decode_goal_as_atom/2 from flrdecode.

:- import 
        flora_add_last/3,
	flora_generalize_last/2,
        flora_trim_last/2
   from flrtrim.

:- import term_to_atom/2 from string.

:- export
	flora_debug_code/2,
	flora_temp_protect_call/2,
	flora_temp_unprotect_call/1,
	flora_define_predicate/1,
	flora_error_undefined/1,
	flora_error_notexported/1,
	flora_error_invalid_export/1.
