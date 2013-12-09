/***************************************************************************
  file: genincludes/flrdyna_defeasibles.inc - A template for generating
                                  the include file for dynamically inserted_A
  				  rules for defeasible reasoning
  Author(s): Michael Kifer

  Copyright (C) by
       The Research Foundation of the State University of New York, 2012-2013;
       and Vulcan, Inc., 2012-2013.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

***************************************************************************/

FL_OVERRIDES(X1,X2,FWContext) :-
	  FLDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,FWContext).
FL_OVERRIDES(X1,X2,X3,X4,FWContext) :-
	  FLDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,X3,X4,FWContext).
FL_OPPOSES(X1,X2,FWContext) :-
	  FLDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,FWContext).
FL_OPPOSES(X1,X2,X3,X4,FWContext) :-
	  FLDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,X3,X4,FWContext).
FL_CANCEL(X1,FWContext) :-
	  FLDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,FWContext).
FL_CANCEL(X1,X2,FWContext) :-
	  FLDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,X2,FWContext).

FLNEGPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,FWContext) :-
	  FLNEGDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,FWContext).
FLNEGPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,X3,X4,FWContext) :-
	  FLNEGDYNAPREFIX(FL_OVERRIDES_UNQUOTED)(X1,X2,X3,X4,FWContext).
FLNEGPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,FWContext) :-
	  FLNEGDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,FWContext).
FLNEGPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,X3,X4,FWContext) :-
	  FLNEGDYNAPREFIX(FL_OPPOSES_UNQUOTED)(X1,X2,X3,X4,FWContext).
FLNEGPREFIX(FL_CANCEL_UNQUOTED)(X1,FWContext) :-
	  FLNEGDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,FWContext).
FLNEGPREFIX(FL_CANCEL_UNQUOTED)(X1,X2,FWContext) :-
	  FLNEGDYNAPREFIX(FL_CANCEL_UNQUOTED)(X1,X2,FWContext).
