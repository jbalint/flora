/*******************************************************************************
  file: closure/flrcommon_neg.inc - A common part of every trailer

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
  inferred predicates for explicit negation, neg

  These wrapper predicates with the 'inferred_' prefix (FLNEGTRAILERPREFIX)
  are needed to make the trailer dynamically loadable. Note that the
  program rules use wrapper predicates with the 'derived_', prefix, i.e.,
  FLNEGHEADPREFIX.
***************************************************************************/
FLNEGTRAILERPREFIX(WRAP_SUB)(X,Y,CallerInfo) :-
	%% checkCallerInfo is just for debugging
	checkCallerInfo(WRAP_SUB(X,Y),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_SUB)(X,Y,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_ISA)(O,C,CallerInfo) :-
	checkCallerInfo(WRAP_ISA(O,C),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_ISA)(O,C,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVD)(O,A,V,CallerInfo) :-
	checkCallerInfo(WRAP_MVD(O,A,V),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_MVD)(O,A,V,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVD)(C,A,V,CallerInfo) :-
	checkCallerInfo(WRAP_IMVD(C,A,V),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_IMVD)(C,A,V,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVDDEF)(O,A,CallerInfo) :-
	checkCallerInfo(WRAP_MVDDEF(O,A),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_MVDDEF)(O,A,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(C,A,CallerInfo) :-
	checkCallerInfo(WRAP_IMVDDEF(C,A),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_IMVDDEF)(C,A,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,MethodArgs,R,CallerInfo) :-
	checkCallerInfo(WRAP_MVDSIG(O,MethodArgs,R),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_MVDSIG)(O,MethodArgs,R,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(O,MethodArgs,CallerInfo) :-
	checkCallerInfo(WRAP_MVDSIGDEF(O,MethodArgs),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_MVDSIGDEF)(O,MethodArgs,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(O,MethodArgs,R,CallerInfo) :-
	checkCallerInfo(WRAP_IMVDSIG(O,MethodArgs,R),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_IMVDSIG)(O,MethodArgs,R,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(O,MethodArgs,CallerInfo) :-
	checkCallerInfo(WRAP_IMVDSIGDEF(O,MethodArgs),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_IMVDSIGDEF)(O,MethodArgs,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_METH)(O,M,CallerInfo) :-
	checkCallerInfo(WRAP_METH(O,M),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_METH)(O,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMETH)(C,M,CallerInfo) :-
	checkCallerInfo(WRAP_IMETH(C,M),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_IMETH)(C,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo) :-
	checkCallerInfo(WRAP_BOOLSIG(O,M),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo) :-
	checkCallerInfo(WRAP_IBOOLSIG(C,M),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_OBJEQL)(X,Y,CallerInfo) :-
	checkCallerInfo(WRAP_OBJEQL(X,Y),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_OBJEQL)(X,Y,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_EXISTS)(X,CallerInfo) :-
	checkCallerInfo(WRAP_EXISTS(X),'FLORA_THIS_MODULE_NAME',CallerInfo),
	FLNEGHEADPREFIX(WRAP_EXISTS)(X,CallerInfo).
