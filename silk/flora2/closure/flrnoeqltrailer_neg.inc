/*******************************************************************************
  file: closure/flrnoeqltrailer_neg.inc - A template for generating trailers
                                          for explicit negation. This mode
					  supports neither equality nor
  					  inheritance. 
  					  Inheritance of negative statements
					  does not seem to make sense.
					  At least, no obvious sense.
  Author(s): Michael Kifer
  Contact:   kifer@cs.stonybrook.edu

  Copyright (C) by
       The Research Foundation of the State University of New York, 1999-2008;
       and Vulcan, Inc., 2008.

  All rights reserved.

  For information about licensing terms, please see
  http://silk.projects.semwebcentral.org/flora2-license.html

*******************************************************************************/


/***************************************************************************
  Note that all programs rules are translated with with 'FLNEGHEAREDPREFIX'.
  These rules are bridged to the trailer using wrapper predicates with
  FLNEGTRAILERPREFIX.
***************************************************************************/


/***************************************************************************
  closure rules for neg X::Y
***************************************************************************/
FLNEGPREFIX(WRAP_SUB)(X,Y,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_SUB)(X,Y,CallerInfo).

FLNEGPREFIX(WRAP_SUB)(X,Y,CallerInfo) :-
	FLTRAILERPREFIX(WRAP_SUB)(Y,X,CallerInfo).

FLNEGPREFIX(WRAP_SUB)(Z,Y,CallerInfo) :-
	silent_sub(X,Z,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_SUB)(X,Y,CallerInfo).

FLNEGPREFIX(WRAP_SUB)(Z,Y,CallerInfo) :-
        WRAP_ISA(X,Z,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_ISA)(X,Y,CallerInfo).


/***************************************************************************
  closure rules for neg O:C
***************************************************************************/
%% WRAP_ISA/3
FLNEGPREFIX(WRAP_ISA)(O,C,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_ISA)(O,C,CallerInfo).

FLNEGPREFIX(WRAP_ISA)(O,S,CallerInfo) :-
	silent_sub(S,C,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_ISA)(O,C,CallerInfo).


/*****************************************************************************
  closure for neg X[Y->Z], neg X[Y*->Z], neg X[Y->{}]
*****************************************************************************/
FLNEGPREFIX(WRAP_IMVD)(C,M,V,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVD)(C,M,V,CallerInfo).

FLNEGPREFIX(WRAP_MVD)(O,M,V,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVD)(O,M,V,CallerInfo).

FLNEGPREFIX(WRAP_MVDDEF)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVDDEF)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_MVD)(O,M,_V,CallerInfo) :-
	FLNEGPREFIX(WRAP_MVDDEF)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_IMVDDEF)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(O,M,CallerInfo).

/* note: for neg WRAP_MVDDEF the implication goes in the opposite direction
   than for WRAP_MVDDEF */
FLNEGPREFIX(WRAP_IMVD)(O,M,_V,CallerInfo) :-
	FLNEGPREFIX(WRAP_IMVDDEF)(O,M,CallerInfo).


/*****************************************************************************
  binary attributes (tabled methods)
*****************************************************************************/
FLNEGPREFIX(WRAP_METH)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_METH)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_IMETH)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMETH)(C,M,CallerInfo).


/*****************************************************************************
  signatures
*****************************************************************************/
%% WRAP_MVDSIG/4
FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_ISA(O,C,CallerInfo),
	FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo).

%% WRAP_MVDSIGDEF/3
FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	WRAP_ISA(O,C,CallerInfo),
	FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,_V,CallerInfo) :-
	FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo).


%% WRAP_IMVDSIG/4
FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(S,M,R,CallerInfo) :-
	inheritance_sub(C,S,CallerInfo),
	FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo).


%% WRAP_IMVDSIGDEF/3
FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(S,M,CallerInfo) :-
	inheritance_sub(C,S,CallerInfo),
	FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo).

/* note: for neg WRAP_IMVDSIGDEF the implication goes in the opposite direction
   than for WRAP_IMVDDEF */
FLNEGPREFIX(WRAP_IMVDSIG)(C,M,_V,CallerInfo) :-
	FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo).


%% WRAP_BOOLSIG/3
FLNEGPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_BOOLSIG)(C,M,CallerInfo) :-
	WRAP_ISA(O,C,CallerInfo),
	FLNEGPREFIX(WRAP_IBOOLSIG)(O,M,CallerInfo).

%% WRAP_IBOOLSIG/3
FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo).

FLNEGPREFIX(WRAP_IBOOLSIG)(S,M,CallerInfo) :-
	inheritance_sub(C,S,CallerInfo),
	FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo).


/*****************************************************************************
  object existence
*****************************************************************************/
FLNEGPREFIX(WRAP_EXISTS)(X,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_EXISTS)(X,CallerInfo).

