/* File:      flrlexer.H
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


:- import get0/1 from standard.

:- import append/3,
	member/2
   from basics.

:- import parse_filename/4 from machine.

:- import
	flora_concat_atoms/2,
	flora_get_counter/2,
	flora_set_counter/2,
	flora_increment_counter/4
   from flrporting.

:- import flora_builtin_synonym/2 from flrsynonym.

:- dynamic flora_file_stack/2.
:- dynamic flora_file_list/2.
:- dynamic flora_file_first_token/2.
:- dynamic flora_file_last_token/2.

:- index(flora_file_stack/2,trie).
:- index(flora_file_list/2,trie).


:- export
	flora_reset_lexer/0,
	flora_reset_lexer/1,
	flora_reset_charpos/0,
	flora_tokens/2,
	flora_token_text/6,
	flora_symbol_token_struct/6,
	flora_rule_delimeter_struct/6,
	flora_blank_line/1,
	flora_begin_file/1,
	flora_end_file/1,
        flora_compile_filename_by_token/2,
	flora_current_compile_filename/1,
	is_alpha/1,
	is_alpha_or_underscore/1,
	is_digit/1,
	is_alphanum/1,
	is_alphanum_or_underscore/1.
