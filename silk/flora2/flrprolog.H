/* File:      flrprolog.H
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


%% NOTE: flora_dynprlg exists only because of the way import
%% is handled in foo@_prolog(mod). In this case, FLORA inserts
%% a dynamic declaration that foo is a prolog predicate.
:- dynamic flora_dynprlg(_,_).
:- dynamic flora_dynprlg(_,_,_).
:- dynamic modular_dynprlg(_,_).
:- dynamic modular_dynprlg(_,_,_).


/*
:- dynamic flora_shprlg(_,_).
:- index 
	flora_dynprlg/2-1,
	%%flora_shprlg/2-1,
	flora_prlg/2-1.
*/

:- import
	%%flora_compiler_permaoption/1,
	flora_compilation_context/1
   from flrcompiler.

:- export
	flora_reset_prolog/0,
	flora_define_prolog/1,
	flora_define_prolog/2,
	flora_define_prolog/3,
	flora_prlgdef_repl/4,
	flora_modular_prlgdef/2,
	flora_modular_prlgdef/3,
	flora_negatable_prlgdef/3,
	flora_define_modular_prolog/1,
	flora_define_modular_prolog/2,
	flora_define_modular_prolog/3,
	flora_prlgdef/3,
	flora_prlgdef/2.

