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

:- import
	length/2,
	append/3
   from basics.

:- import
	flora_concat_atoms/2
   from flrporting.

:- import flora_error_line/2 from flrprint.

:- import
	flora_begin_file/1,
	flora_end_file/1,
	flora_reset_charpos/0
   from flrlexer.

:- import flora_conflict_operator/3 from flroperator.

:- import flora_nodefp/2 from flrnodefp.

:- import flora_nowsp/2 from flrnowsp.

:- import flora_prlgdef/2 from flrprolog.

:- import flora_argdef/4 from flrarguments.

:- import flora_system_module/1 from flrlibman.

:- import flora_special_builtin_synonym/2 from flrsynonym.

:- export
	get_atomvar_name/2,
	get_module_from_spec/3,
	flora_parse_term_external/3,
	parsing_error/3,
	flora_parse/3,
	fldirective_struct/3.
