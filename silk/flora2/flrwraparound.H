/* File:      flrwraparound.P -- Workspace wrapper for .fli files
**
** Author(s): Michael Kifer
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

:- import
	parse_filename/4
   from machine.

:- import ','/2 from standard.

:- import
	flora_concat_items/2,
	flora_concat_atoms/2
   from flrporting.

:- import
	flora_set_xpp_options_for_read/0,
	flora_clear_xpp_options/0,
	flora_check_filename/2,
	flora_locate_file/3
   from flrutils.

:- import
	flora_stderr_nl/0,
	flora_error_line/2
   from flrprint.

:- import process_control/2 from shell.

:- import xpp_process_file/3 from parse.

:- import bootstrap_flora/0 from flora2.

:- export flWrapAround/1.

