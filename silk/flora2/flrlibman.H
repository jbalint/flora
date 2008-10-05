/* File:      flrlibman.H
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




:- import flora_abort/0 from flrutils.

:- import flora_configuration/2 from flrregistry.

:- import flora_syslib_loaded/1 from usermod.
:- dynamic flora_syslib_loaded(_).
:- index flora_syslib_loaded/1-1.

:- import flora_sysmod_loaded/1 from usermod.
:- dynamic flora_sysmod_loaded(_).
:- index flora_sysmod_loaded/1-1.

:- import flora_slash/1,
	flora_concat_atoms/2
   from flrporting.

:- import bootstrap_flora/0 from flora2.

:- index flora_sysmod_file/3-1.
:- index flora_library_file/3-1.

:- import flora_error_line/1,
	flora_error_line/2
   from flrprint.

:- import flora_load_system_module_internal/1 from flrutils.

:- export
	flora_load_library/1,
	flora_include/2,
	flora_sysmod_file/3,
	flora_system_module/1,
	flora_load_system_module/1.
