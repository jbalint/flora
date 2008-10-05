/* File:      flroperator.H
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


:- dynamic flora_dynop(_,_,_).
:- dynamic flora_shop(_,_,_).

:- index(flora_dynop/3,trie).
:- index(flora_shop/3,trie).

:- index flora_op/3-3.

:- import flora_get_counter/2 from flrporting.

:- export
	flora_opdef/3,
	flora_parenthesized_op/1,
	flora_conflict_operator/3,
	flora_reset_operator/0,
	flora_define_operator/3,
	flora_shreset_operator/0,
	flora_shdefine_operator/3.
