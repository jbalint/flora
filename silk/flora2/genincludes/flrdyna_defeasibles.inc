/***************************************************************************
  file: genincludes/flrdyna_defeasibles.inc - A template for generating
                                  the include file for dynamically inserted_A
  				  rules for defeasible reasoning
  Author(s): Michael Kifer

  Copyright (C) by
       The Research Foundation of the State University of New York, 2012
       and Vulcan, Inc., 2012.

  All rights reserved.

  For information about licensing terms, please see
  http://silk.projects.semwebcentral.org/flora2-license.html

***************************************************************************/

FL_OVERRIDES(X1,X2,Caller) :-
	  FLDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,Caller).
FL_OVERRIDES(X1,X2,X3,X4,Caller) :-
	  FLDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,X3,X4,Caller).
FL_OPPOSES(X1,X2,Caller) :-
	  FLDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,Caller).
FL_OPPOSES(X1,X2,X3,X4,Caller) :-
	  FLDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,X3,X4,Caller).
FL_CANCEL(X1,Caller) :-
	  FLDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,Caller).
FL_CANCEL(X1,X2,Caller) :-
	  FLDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,X2,Caller).

FLNEGPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,Caller) :-
	  FLNEGDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,Caller).
FLNEGPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,X3,X4,Caller) :-
	  FLNEGDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,X3,X4,Caller).
FLNEGPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,Caller) :-
	  FLNEGDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,Caller).
FLNEGPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,X3,X4,Caller) :-
	  FLNEGDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,X3,X4,Caller).
FLNEGPREFIX(FL_CANCEL_UNQUOTED)(X1,Caller) :-
	  FLNEGDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,Caller).
FLNEGPREFIX(FL_CANCEL_UNQUOTED)(X1,X2,Caller) :-
	  FLNEGDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,X2,Caller).
