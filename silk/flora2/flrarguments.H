/* File:      flrarguments.H
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

:- dynamic flora_arguments_spec_dyn/4.

:- import
	get_module_from_spec/3,
	get_atomvar_name/2
   from flrparser.

:- export
	flora_set_argdef/4,
	flora_argdef/4.
