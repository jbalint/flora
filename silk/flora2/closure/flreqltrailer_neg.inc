/*******************************************************************************
  file: closure/flreqltrailer_neg.inc - A template for generating trailers with
  				      	equality maintenance and NO behavioral
					inheritance.
  					Inheritance of signatures is supported.
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
  Note that all programs rules are translated with with FLNEGHEADPREFIX.
  These rules are bridged to the trailer using wrapper predicates with
  FLNEGTRAILERPREFIX.
***************************************************************************/


/***************************************************************************
  closure rules for neg X::Y
***************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_SUB_EQL)/3
FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_SUB)(X,Y,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,CallerInfo) :-
	WRAP_DIFFOBJEQL(X,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_SUB)(OX,Y,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,CallerInfo) :-
	WRAP_DIFFOBJEQL(Y,OY,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_SUB)(X,OY,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,CallerInfo) :-
	WRAP_DIFFOBJEQL(X,OX,CallerInfo),
	WRAP_DIFFOBJEQL(Y,OY,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_SUB)(OX,OY,CallerInfo).

%% FLNEGPREFIX(WRAP_SUB)/3
FLNEGPREFIX(WRAP_SUB)(X,Y,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,CallerInfo).

FLNEGPREFIX(WRAP_SUB)(Z,Y,CallerInfo) :-
	silent_sub(X,Z,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,CallerInfo).

FLNEGPREFIX(WRAP_SUB)(Z,Y,CallerInfo) :-
        WRAP_ISA(X,Z,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(X,Y,CallerInfo).



/***************************************************************************
  closure rules for  neg O:C
***************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_ISA_EQL)/3
FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_ISA)(O,C,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_ISA)(OX,C,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_ISA)(O,CX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_ISA)(OX,CX,CallerInfo).


%% FLNEGPREFIX(WRAP_ISA)/3
FLNEGPREFIX(WRAP_ISA)(O,C,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,CallerInfo).

FLNEGPREFIX(WRAP_ISA)(O,S,CallerInfo) :-
	silent_sub(S,C,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,CallerInfo).


/*****************************************************************************
  The following rules propogate the effects of equality.
*****************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)/4
FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVD)(C,M,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(CX,M,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(C,MX,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(C,M,VX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(C,MX,VX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(CX,M,VX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(CX,MX,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(CX,MX,VX,CallerInfo).


%% FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)/3
FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(C,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(CX,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(C,MX,CallerInfo).


/***************************************************************************
  closure for X[Y->Z], X[Y*->Z], X[]
/***************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_MVD_EQL)/4
FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVD)(O,M,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVD)(OX,M,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVD)(O,MX,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVD)(O,M,VX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVD)(O,MX,VX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVD)(OX,M,VX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVD)(OX,MX,V,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(V,VX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVD)(OX,MX,VX,CallerInfo).


%% FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)/3
FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVDDEF)(O,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDDEF)(OX,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDDEF)(O,MX,CallerInfo).

%% FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)/3
FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMETH)(C,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMETH)(CX,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMETH)(C,MX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMETH)(CX,MX,CallerInfo).


%% FLNEGTRAILERPREFIX(WRAP_METH_EQL)/3
FLNEGTRAILERPREFIX(WRAP_METH_EQL)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_METH)(O,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_METH_EQL)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_METH)(OX,M,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_METH_EQL)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_METH)(O,MX,CallerInfo).

FLNEGTRAILERPREFIX(WRAP_METH_EQL)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_METH)(OX,MX,CallerInfo).


/*****************************************************************************
  regular wrappers
*****************************************************************************/
FLNEGPREFIX(WRAP_IMVD)(C,M,V,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,CallerInfo).

FLNEGPREFIX(WRAP_IMVDDEF)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)(C,M,CallerInfo).

FLNEGPREFIX(WRAP_IMVDDEF)(C,M,CallerInfo) :-
	FLNEGPREFIX(WRAP_IMVD)(C,M,_V,CallerInfo).

FLNEGPREFIX(WRAP_MVD)(O,M,V,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,CallerInfo).

FLNEGPREFIX(WRAP_MVDDEF)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_MVDDEF)(O,M,CallerInfo) :-
	FLNEGPREFIX(WRAP_MVD)(O,M,_V,CallerInfo).


/*****************************************************************************
  binary attributes (tabled methods)
*****************************************************************************/
FLNEGPREFIX(WRAP_METH)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_METH_EQL)(O,M,CallerInfo).

%% imeth/3
FLNEGPREFIX(WRAP_IMETH)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)(C,M,CallerInfo).


/*****************************************************************************
  monotonic inheritance of signatures
*****************************************************************************/
%% FLNEGPREFIX(WRAP_MVDSIG)/4
FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(OX,M,R,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,MX,R,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,M,RX,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,MX,RX,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(OX,M,RX,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(OX,MX,R,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(OX,MX,RX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_ISA(O,C,CallerInfo),
	FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,CallerInfo).



%% FLNEGPREFIX(WRAP_MVDSIGDEF)/3
FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(OX,M,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(O,MX,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(OX,MX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	WRAP_ISA(O,C,CallerInfo),
	FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,CallerInfo) :-
	FLNEGPREFIX(WRAP_MVDSIG)(O,M,_V,CallerInfo).


%% FLNEGPREFIX(WRAP_IMVDSIG)/4
FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(CX,M,R,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(C,MX,R,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(C,M,RX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(C,MX,RX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(CX,M,RX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(CX,MX,R,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	WRAP_DIFFOBJEQL(R,RX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(CX,MX,RX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,CallerInfo) :-
	inheritance_sub(C,S,CallerInfo),
	FLNEGPREFIX(WRAP_IMVDSIG)(S,M,R,CallerInfo).



%% FLNEGPREFIX(WRAP_IMVDSIGDEF)/3
FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(CX,M,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(C,MX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(CX,MX,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(S,M,CallerInfo) :-
	inheritance_sub(C,S,CallerInfo),
	FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,CallerInfo) :-
	FLNEGPREFIX(WRAP_IMVDSIG)(C,M,_V,CallerInfo).


%% FLNEGPREFIX(WRAP_BOOLSIG)/3
FLNEGPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo).

FLNEGPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(OX,M,CallerInfo).

FLNEGPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(O,MX,CallerInfo).

FLNEGPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(O,OX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(OX,MX,CallerInfo).

FLNEGPREFIX(WRAP_BOOLSIG)(C,M,CallerInfo) :-
	WRAP_ISA(O,C,CallerInfo),
	FLNEGPREFIX(WRAP_IBOOLSIG)(O,M,CallerInfo).


%% FLNEGPREFIX(WRAP_IBOOLSIG)/3
FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo).

FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(CX,M,CallerInfo).

FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(C,MX,CallerInfo).

FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo) :-
	WRAP_DIFFOBJEQL(C,CX,CallerInfo),
	WRAP_DIFFOBJEQL(M,MX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(CX,MX,CallerInfo).

FLNEGPREFIX(WRAP_IBOOLSIG)(S,M,CallerInfo) :-
	inheritance_sub(C,S,CallerInfo),
	FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo).


/*****************************************************************************
  object existence
*****************************************************************************/
FLNEGPREFIX(WRAP_EXISTS)(X,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_EXISTS)(X,CallerInfo).

FLNEGPREFIX(WRAP_EXISTS)(X,CallerInfo) :-
	WRAP_DIFFOBJEQL(X,OX,CallerInfo),
	FLNEGTRAILERPREFIX(WRAP_EXISTS)(OX,CallerInfo).


/*****************************************************************************
  basic equality maintenance
  symmetry, transitivity are treated in flrcommon_neg.inc
*****************************************************************************/
%% WRAP_DIFFOBJEQL means X,Y are unequal and not identical
FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,CallerInfo) :-
	WRAP_DIFFOBJEQL(X,V,CallerInfo),
	WRAP_DIFFOBJEQL(Y,W,CallerInfo),
	X \= Y,
	FLNEGTRAILERPREFIX(WRAP_OBJEQL)(V,W,CallerInfo).

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,CallerInfo) :-
	WRAP_DIFFOBJEQL(X,V,CallerInfo),
	WRAP_DIFFOBJEQL(Y,W,CallerInfo),
	X \= Y,
	FLNEGTRAILERPREFIX(WRAP_OBJEQL)(W,V,CallerInfo).
