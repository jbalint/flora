/*******************************************************************************
  file: closure/flrnoeqltrailer_neg.inc - A template for generating trailers
                                          for explicit negation. This mode
					  supports neither equality nor
  					  inheritance. 
  					  Inheritance of negative statements
					  does not seem to make sense.
					  At least, no obvious sense.
  Author(s): Michael Kifer
  Contact:   flora-users@lists.sourceforge.net

  Copyright (C) by
       The Research Foundation of the State University of New York, 1999-2013;
       and Vulcan, Inc., 2008-2013.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

*******************************************************************************/


/***************************************************************************
  Note that all programs rules are translated with with 'FLNEGHEAREDPREFIX'.
  These rules are bridged to the trailer using wrapper predicates with
  FLNEGTRAILERPREFIX.
***************************************************************************/


/***************************************************************************
  closure rules for neg X::Y
***************************************************************************/
FLNEGPREFIX(WRAP_SUB)(X,Y,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_SUB)(X,Y,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_SUB)(X,Y,FL_CONTEXT(Caller,_,_)) :-
	FLTRAILERPREFIX(WRAP_SUB)(Y,X,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_SUB)(Z,Y,FL_CONTEXT(Caller,_,_)) :-
	silent_sub(X,Z,FL_CONTEXT(Caller,_,_)),
	FLNEGTRAILERPREFIX(WRAP_SUB)(X,Y,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_SUB)(Z,Y,FL_CONTEXT(Caller,_,_)) :-
        WRAP_ISA(X,Z,FL_CONTEXT(Caller,_,_)),
	FLNEGTRAILERPREFIX(WRAP_ISA)(X,Y,FL_CONTEXT(Caller,_,_)).


/***************************************************************************
  closure rules for neg O:C
***************************************************************************/
%% WRAP_ISA/3
FLNEGPREFIX(WRAP_ISA)(O,C,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_ISA)(O,C,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_ISA)(O,S,FL_CONTEXT(Caller,_,_)) :-
	silent_sub(S,C,FL_CONTEXT(Caller,_,_)),
	FLNEGTRAILERPREFIX(WRAP_ISA)(O,C,FL_CONTEXT(Caller,_,_)).


/*****************************************************************************
  closure for neg X[Y->Z], neg X[Y*->Z], neg X[Y->{}]
*****************************************************************************/
FLNEGPREFIX(WRAP_IMVD)(C,M,V,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_IMVD)(C,M,V,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_MVD)(O,M,V,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_MVD)(O,M,V,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_MVDDEF)(O,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_MVDDEF)(O,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_MVD)(O,M,_V,FL_CONTEXT(Caller,_,_)) :-
	FLNEGPREFIX(WRAP_MVDDEF)(O,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_IMVDDEF)(O,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(O,M,FL_CONTEXT(Caller,_,_)).

/* note: for neg WRAP_MVDDEF the implication goes in the opposite direction
   than for WRAP_MVDDEF */
FLNEGPREFIX(WRAP_IMVD)(O,M,_V,FL_CONTEXT(Caller,_,_)) :-
	FLNEGPREFIX(WRAP_IMVDDEF)(O,M,FL_CONTEXT(Caller,_,_)).


/*****************************************************************************
  binary attributes (tabled methods)
*****************************************************************************/
FLNEGPREFIX(WRAP_METH)(O,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_METH)(O,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_IMETH)(C,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_IMETH)(C,M,FL_CONTEXT(Caller,_,_)).


/*****************************************************************************
  signatures
*****************************************************************************/
%% WRAP_MVDSIG/4
FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,M,R,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,FL_CONTEXT(Caller,_,_)) :-
	WRAP_ISA(O,C,FL_CONTEXT(Caller,_,_)),
	FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,FL_CONTEXT(Caller,_,_)).

%% WRAP_MVDSIGDEF/3
FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(O,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,FL_CONTEXT(Caller,_,_)) :-
	WRAP_ISA(O,C,FL_CONTEXT(Caller,_,_)),
	FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,_V,FL_CONTEXT(Caller,_,_)) :-
	FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,FL_CONTEXT(Caller,_,_)).


%% WRAP_IMVDSIG/4
FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(C,M,R,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_IMVDSIG)(S,M,R,FL_CONTEXT(Caller,_,_)) :-
	FLINHERITANCEPREFIX(WRAP_SUB)(C,S,FL_CONTEXT(Caller,_,_)),
	FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,FL_CONTEXT(Caller,_,_)).


%% WRAP_IMVDSIGDEF/3
FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(C,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(S,M,FL_CONTEXT(Caller,_,_)) :-
	FLINHERITANCEPREFIX(WRAP_SUB)(C,S,FL_CONTEXT(Caller,_,_)),
	FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,FL_CONTEXT(Caller,_,_)).

/* note: for neg WRAP_IMVDSIGDEF the implication goes in the opposite direction
   than for WRAP_IMVDDEF */
FLNEGPREFIX(WRAP_IMVDSIG)(C,M,_V,FL_CONTEXT(Caller,_,_)) :-
	FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,FL_CONTEXT(Caller,_,_)).


%% WRAP_BOOLSIG/3
FLNEGPREFIX(WRAP_BOOLSIG)(O,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(O,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_BOOLSIG)(C,M,FL_CONTEXT(Caller,_,_)) :-
	WRAP_ISA(O,C,FL_CONTEXT(Caller,_,_)),
	FLNEGPREFIX(WRAP_IBOOLSIG)(O,M,FL_CONTEXT(Caller,_,_)).

%% WRAP_IBOOLSIG/3
FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(C,M,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_IBOOLSIG)(S,M,FL_CONTEXT(Caller,_,_)) :-
	FLINHERITANCEPREFIX(WRAP_SUB)(C,S,FL_CONTEXT(Caller,_,_)),
	FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,FL_CONTEXT(Caller,_,_)).


/*****************************************************************************
  object existence
*****************************************************************************/
FLNEGPREFIX(WRAP_EXISTS)(X,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_EXISTS)(X,FL_CONTEXT(Caller,_,_)).

