/* File:      flrcoder.H
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

#include "flora_terms.flh"

:- import format/2 from format.

:- import
	append/3
   from basics.

:- import term_to_atom/3 from string.

:- import
	flora_write_quoted_atom/1,
	flora_write_atom/1,
	flora_concat_atoms/2
   from flrporting.

:- import
	negate_wrapper/2,
	flora_module_predicate/4,
	flora_fdb_storage_name/2,
	flora_fdb_storage_name/2,
	%% Storage for skeletons of defined predicates
	flora_fld_storage_name/2
   from flrwrapper.

%% Undefinedness support
:- dynamic using_debug_prefix(_).

:- import flora_parse_datatype/4 from flrdatatype_parse.
:- import
	flora_canonical_type_name/2,
	flora_datatypelitlist/2,
	is_flora_datatypelitlist/1
   from flrdatatype.

:- import
	flora_runtime_uriprefix_expansion/3,
	flora_compiletime_uriprefix_expansion/2,
	flora_clear_compiletime_uriprefixes/0,
	FLLIBPREFIXDEF/2
   from flrprefixdef.

:- export
	flora_divide_program/3,
	flora_extern_code/2,
	flora_intern_code/4,
	flora_record_prefix_definition/2,
	flora_write_struct/3,
	flora_build_struct/7.

:- export
	is_prrule/3,
	is_prfact/2,
	is_prdirective/2,
	is_prlabeled_construct/3,
        is_prignoredep/2,
	is_prthismodule/1,
	is_prthisfdbstorage/1,
	is_pratom/3,
	is_prnumber/3,
	is_prtransactionalnumber/3,
	is_prvariable/3,
	is_prtransactionalvariable/3,
	is_prstring/3,
	is_prbuiltin_identifier/3,
	is_prdatatype/4,
	is_pruri/3,
	is_prurisq/3,
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
	is_prologliblit/4,
	is_prnewpred/4,
	is_prnewoid/3,
        is_prmvdcondef/6,
	is_primvdcondef/6,
	is_prreify/2,
	is_flogic/4,
	is_fllibdb/1.

