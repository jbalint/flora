/*******************************************************************************
  file: closure/flreqltrailer_neg.inc - A template for generating trailers with
  				      	equality maintenance and NO behavioral
					inheritance.
  					Inheritance of signatures is supported.
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
  Note that all programs rules are translated with with FLNEGHEADPREFIX.
  These rules are bridged to the trailer using wrapper predicates with
  FLNEGTRAILERPREFIX.
***************************************************************************/


/***************************************************************************
  closure rules for neg X::Y
***************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_SUB_EQL)/3
FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(X,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(Y,OY,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_SUB)(OX,OY,[Caller|_]).

%% FLNEGPREFIX(WRAP_SUB)/3
FLNEGPREFIX(WRAP_SUB)(X,Y,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,[Caller|_]).

FLNEGPREFIX(WRAP_SUB)(Z,Y,[Caller|_]) :-
	silent_sub(X,Z,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_SUB_EQL)(X,Y,[Caller|_]).

FLNEGPREFIX(WRAP_SUB)(Z,Y,[Caller|_]) :-
        WRAP_ISA(X,Z,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(X,Y,[Caller|_]).



/***************************************************************************
  closure rules for  neg O:C
***************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_ISA_EQL)/3
FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(O,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(C,CX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_ISA)(OX,CX,[Caller|_]).


%% FLNEGPREFIX(WRAP_ISA)/3
FLNEGPREFIX(WRAP_ISA)(O,C,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,[Caller|_]).

FLNEGPREFIX(WRAP_ISA)(O,S,[Caller|_]) :-
	silent_sub(S,C,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_ISA_EQL)(O,C,[Caller|_]).


/*****************************************************************************
  The following rules propogate the effects of equality.
*****************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)/4
FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(C,CX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(V,VX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_IMVD)(CX,MX,VX,[Caller|_]).


%% FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)/3
FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)(C,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(C,CX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(CX,MX,[Caller|_]).


/***************************************************************************
  closure for X[Y->Z], X[Y*->Z], X[]
/***************************************************************************/
%% FLNEGTRAILERPREFIX(WRAP_MVD_EQL)/4
FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(O,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(V,VX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_MVD)(OX,MX,VX,[Caller|_]).


%% FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)/3

FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)(O,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(O,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_MVDDEF)(OX,MX,[Caller|_]).

%% FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)/3
FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)(C,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(C,CX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_IMETH)(CX,MX,[Caller|_]).


%% FLNEGTRAILERPREFIX(WRAP_METH_EQL)/3
FLNEGTRAILERPREFIX(WRAP_METH_EQL)(O,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(O,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_METH)(OX,MX,[Caller|_]).


/*****************************************************************************
  regular wrappers
*****************************************************************************/
FLNEGPREFIX(WRAP_IMVD)(C,M,V,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_IMVD_EQL)(C,M,V,[Caller|_]).

FLNEGPREFIX(WRAP_IMVDDEF)(C,M,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_IMVDDEF_EQL)(C,M,[Caller|_]).

FLNEGPREFIX(WRAP_IMVDDEF)(C,M,[Caller|_]) :-
	FLNEGPREFIX(WRAP_IMVD)(C,M,_V,[Caller|_]).

FLNEGPREFIX(WRAP_MVD)(O,M,V,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_MVD_EQL)(O,M,V,[Caller|_]).

FLNEGPREFIX(WRAP_MVDDEF)(O,M,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_MVDDEF_EQL)(O,M,[Caller|_]).

FLNEGPREFIX(WRAP_MVDDEF)(O,M,[Caller|_]) :-
	FLNEGPREFIX(WRAP_MVD)(O,M,_V,[Caller|_]).


/*****************************************************************************
  binary attributes (tabled methods)
*****************************************************************************/
FLNEGPREFIX(WRAP_METH)(O,M,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_METH_EQL)(O,M,[Caller|_]).

%% imeth/3
FLNEGPREFIX(WRAP_IMETH)(C,M,[Caller|_]) :-
	FLNEGTRAILERPREFIX(WRAP_IMETH_EQL)(C,M,[Caller|_]).


/*****************************************************************************
  monotonic inheritance of signatures
*****************************************************************************/
%% FLNEGPREFIX(WRAP_MVDSIG)/4
FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(O,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(R,RX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_MVDSIG)(OX,MX,RX,[Caller|_]).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,[Caller|_]) :-
	WRAP_ISA(O,C,[Caller|_]),
	FLNEGPREFIX(WRAP_MVDSIG)(O,M,R,[Caller|_]).



%% FLNEGPREFIX(WRAP_MVDSIGDEF)/3
FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(O,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(OX,MX,[Caller|_]).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,[Caller|_]) :-
	WRAP_ISA(O,C,[Caller|_]),
	FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,[Caller|_]).

FLNEGPREFIX(WRAP_MVDSIGDEF)(O,M,[Caller|_]) :-
	FLNEGPREFIX(WRAP_MVDSIG)(O,M,_V,[Caller|_]).


%% FLNEGPREFIX(WRAP_IMVDSIG)/4
FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(C,CX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(R,RX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(CX,MX,RX,[Caller|_]).

FLNEGPREFIX(WRAP_IMVDSIG)(C,M,R,[Caller|_]) :-
	FLINHERITANCEPREFIX(WRAP_SUB)(C,S,[Caller|_]),
	FLNEGPREFIX(WRAP_IMVDSIG)(S,M,R,[Caller|_]).



%% FLNEGPREFIX(WRAP_IMVDSIGDEF)/3
FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(C,CX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(CX,MX,[Caller|_]).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(S,M,[Caller|_]) :-
	FLINHERITANCEPREFIX(WRAP_SUB)(C,S,[Caller|_]),
	FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,[Caller|_]).

FLNEGPREFIX(WRAP_IMVDSIGDEF)(C,M,[Caller|_]) :-
	FLNEGPREFIX(WRAP_IMVDSIG)(C,M,_V,[Caller|_]).


%% FLNEGPREFIX(WRAP_BOOLSIG)/3
FLNEGPREFIX(WRAP_BOOLSIG)(O,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(O,OX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(OX,MX,[Caller|_]).

FLNEGPREFIX(WRAP_BOOLSIG)(C,M,[Caller|_]) :-
	WRAP_ISA(O,C,[Caller|_]),
	FLNEGPREFIX(WRAP_IBOOLSIG)(O,M,[Caller|_]).


%% FLNEGPREFIX(WRAP_IBOOLSIG)/3
FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(C,CX,[Caller|_]),
	WRAP_DIFFOBJEQL_AUX(M,MX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(CX,MX,[Caller|_]).

FLNEGPREFIX(WRAP_IBOOLSIG)(S,M,[Caller|_]) :-
	FLINHERITANCEPREFIX(WRAP_SUB)(C,S,[Caller|_]),
	FLNEGPREFIX(WRAP_IBOOLSIG)(C,M,[Caller|_]).


/*****************************************************************************
  object existence
*****************************************************************************/
FLNEGPREFIX(WRAP_EXISTS)(X,[Caller|_]) :-
	WRAP_DIFFOBJEQL_AUX(X,OX,[Caller|_]),
	FLNEGTRAILERPREFIX(WRAP_EXISTS)(OX,[Caller|_]).

