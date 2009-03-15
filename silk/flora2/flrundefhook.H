/* File:      flrundefhook.H
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



:- import flora_decode_predicate/6 from flrwrapper.

:- import '_isloaded'/1 from flora2.

:- import flora_error_line/2 from flrprint.

:- import flora_decode_goal_as_atom/2 from flrdecode.

:- export flora_undefined_predicate_hook/3.
