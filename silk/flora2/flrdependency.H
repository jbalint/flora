/* File:      flrdependency.H  -- the dependency checker
**
** Author(s): Chang Zhao
**
** Contact:   kifer@cs.stonybrook.edu
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2010.
**
** All rights reserved.
**
** For information about licensing terms, please see
** http://silk.projects.semwebcentral.org/flora2-license.html
**
**
*/

:- import member/2,length/2 from basics.

:- import subsumes/2 from subsumes.

:- import flora_abolish_table_predicate/1 from flrtables.

:- import flora_decode_goal_as_atom_substitute_vars/2 from flrdecode.

:- import flora_get_maxwarnings/1 from flrutils.

:- import
	flora_get_counter/2,
	flora_set_counter/2
   from flrporting.

:- import
	flora_nth_token/2,
	flora_token_rulenum/2
   from flrcomposer.

:- import flora_token_text/6 from flrlexer.

:- import
	is_prrule/3,
        is_prdirective/2,
        is_prignoredep/2,
	%%is_prlabeled_construct/3,
	flora_build_struct/7
   from flrcoder.

:- import get_canonical_form/2 from flrcanon.

:- dynamic rule(_,_,_).
:- dynamic target(_,_,_).
:- dynamic tabled_head(_).
:- dynamic dependency(_,_,_,_).
:- dynamic ignored(_,_,_).
:- dynamic warning_seen(_,_,_,_,_).

:- index(rule/3,trie).
:- index(dependency/4,trie).

:- export
	is_control/3,
        depend/3,
	check_for_dependencies/2.
