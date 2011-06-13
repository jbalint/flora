/* File:      flrcompiler.H
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
	flora_increment_counter/4,
	flora_set_counter/2,
	flora_get_counter/2,
	flora_concat_atoms/2,
        flora_match_substring/3
    from flrporting.

:- import
	member/2,
	subset/2,
	append/3,
	flatten/2,
	length/2
   from basics.

:- import
        concat_atom/2
    from string.

:- import sort/2, keysort/2, findall/3 from setof.

:- import flora_define_operator/3 from flroperator.

:- import
	flora_define_prolog/1,
	flora_define_prolog/2,
	flora_prlgdef/4,
	flora_prlgdef/2
   from flrprolog.

:- import
	flora_clear_compiletime_uriprefixes/0,
	FLLIBPREFIXDEF/2
   from flrprefixdef.

:- import
	flora_token_text/6
    from flrlexer.

:- import
	flora_nth_token/2
   from flrcomposer.

:- import
	flora_compiler_environment/2,
	flora_retractall_substitute/1,
	flora_token_index_to_line/2
   from flrutils.

:- import
	is_prologterm/4,
	is_prologterm/5,
        is_prvariable/1,
        is_prvariable/3,
        is_prtransactionalvariable/3,
        is_pratom/2,
        is_pratom/3,
        is_prnumber/1,
	is_prbuiltin_identifier/2,
	is_prbuiltin_identifier/3,
        is_prdatatype/4,
	is_prdatatypelist/2,
        is_prtransactionalnumber/3,
        is_prstring/1,
        is_prfact/2
   from flrcoder.

:- import flora_delayed_literal/2 from FLDELAYSUPPORTMOD.
        
:- import flora_error_line/2 from flrprint.

:- dynamic compile_with_var_module(_).

:- dynamic dynrule_warnings(_).

:- export 
	flora_clear_compilation_permaoptions/0,
        flora_reset_newvar/0,
        flora_new_varobj/3,
	flora_reset_compiler/0, 
	flora_compile_pathexp/3,
	flora_compile_add/5,
	flora_compile/5.
