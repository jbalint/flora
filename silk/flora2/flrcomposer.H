/* File:      flrcomposer.H
**
** Author(s): Guizhen Yang
**
** Contact:   kifer@cs.stonybrook.edu
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2011.
**
** All rights reserved.
**
** For information about licensing terms, please see
** http://silk.projects.semwebcentral.org/flora2-license.html
**
**
*/


:- dynamic indexed_token(_,_,_).
:- dynamic composing_error(_,_).
:- dynamic composing_error(_,_,_).

:- index(indexed_token/3,trie).
:- index(composing_error/2,trie).
:- index(composing_error/3,trie).

:- import eval/2 from eval.

:- import 
	flora_set_counter/2,
	flora_get_counter/2
   from flrporting.

:- import
	flora_parenthesized_op/1,
	flora_opdef/3
   from flroperator.

:- import flora_op_synonym/2 from flrsynonym.

:- export
	flora_reset_composer/0,
	flora_compose/3,
	flora_nth_token/2,
	flora_token_rulenum/2.
