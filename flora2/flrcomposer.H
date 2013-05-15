/* File:      flrcomposer.H
**
** Author(s): Guizhen Yang
**
** Contact:   flora-users@lists.sourceforge.net
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2013.
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


:- dynamic indexed_token(_,_,_).
:- dynamic composing_error(_,_).
:- dynamic composing_error(_,_,_).

:- index(indexed_token/3,trie).
:- index(composing_error/2,trie).
:- index(composing_error/3,trie).

:- import eval/2 from eval.

:- import
	flora_retractall_substitute/1
   from flrutils.

:- import 
	flora_set_counter/2,
	flora_get_counter/2
   from flrporting.

:- import
	flora_parenthesized_op/1,
	flora_opdef/3
   from flroperator.

:- import flora_op_synonym/2 from flrsynonym.

:- import
	flratom_char_code/3
   from flora_ground.

:- export
	flora_reset_composer/0,
	flora_compose/3,
	flora_nth_token/2,
	flora_token_rulenum/2.
