/* File:      flrimport.H
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


:- import
	append/3,
	copy_term/2
   from basics.
:- import flora_load_module_util/2 from flrutils.
:- import 
        flora_hilog_module_predicate_symbol/2,
        flora_tabled_hilog_module_predicate_symbol/2
    from flrwrapper.
:- import flora_error_line/1, flora_error_line/2 from flrprint.

:- export
	flora_import_predicate/4.



