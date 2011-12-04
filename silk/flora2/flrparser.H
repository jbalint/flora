/* File:      flrparser.H
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

:- import
	subset/2,
	length/2,
	append/3
   from basics.

:- import
	flora_concat_items/2,
	flora_concat_atoms/2
   from flrporting.

:- import
	flora_compiletime_uriprefix_expansion/2,
	flora_runtime_uriprefix_expansion/3
   from flrprefixdef.

:- import flora_error_line/2 from flrprint.

:- import
	%%flora_current_compile_filename/1,
	flora_begin_file/1,
	flora_end_file/1,
	flora_reset_charpos/0
   from flrlexer.

:- import flora_conflict_operator/3 from flroperator.

:- import flora_nodefp/2 from flrnodefp.

:- import flora_nowsp/2 from flrnowsp.

:- import
	flora_prlgdef/4,
	flora_prlgdef/2
   from flrprolog.

:- import
	flora_retractall_substitute/1
   from flrutils.

:- import flora_argdef/4 from flrarguments.

:- import
	flora_delayed_builtin_literal/2,
	flora_delayed_sensor_literal/2
   from FLDELAYSUPPORTMOD.

:- import flora_system_module/1 from flrlibman.

:- import flora_special_builtin_synonym/2 from flrsynonym.

:- import
	flora_synonymous_type_names/2
   from flrdatatype.
:- import
	flora_parse_datatype/4
   from flrdatatype_parse.

:- export
	flora_get_flatomvar_name/2,
	flora_get_module_from_spec/3,
	flora_parse_term_external/3,
	parsing_error/3,
	flora_parse/3,
	fldirective_struct/3,
	flatom_struct/3,
	flterm_struct/4,
	flconjunct_struct/3,
	is_delayquant/1.
