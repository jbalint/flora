/*******************************************************************************
  file: closure/flrcommon_neg.inc - A common part of every trailer

  Author(s): Michael Kifer

  Contact:   kifer@cs.stonybrook.edu

  Copyright (C) by
       The Research Foundation of the State University of New York, 1999-2013
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
  inferred predicates for explicit negation, neg

  These wrapper predicates with the 'inferred_' prefix (FLNEGTRAILERPREFIX)
  are needed to make the trailer dynamically loadable. Note that the
  program rules use wrapper predicates with the 'derived_', prefix, i.e.,
  FLNEGHEADPREFIX.
***************************************************************************/
FLNEGTRAILERPREFIX(WRAP_SUB)(X,Y,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_SUB)(X,Y,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_ISA)(O,C,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_ISA)(O,C,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVD)(O,A,V,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_MVD)(O,A,V,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVD)(C,A,V,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_IMVD)(C,A,V,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVDDEF)(O,A,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_MVDDEF)(O,A,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVDDEF)(C,A,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_IMVDDEF)(C,A,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVDSIG)(O,MethodArgs,R,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_MVDSIG)(O,MethodArgs,R,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_MVDSIGDEF)(O,MethodArgs,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_MVDSIGDEF)(O,MethodArgs,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVDSIG)(O,MethodArgs,R,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_IMVDSIG)(O,MethodArgs,R,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMVDSIGDEF)(O,MethodArgs,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_IMVDSIGDEF)(O,MethodArgs,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_METH)(O,M,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_METH)(O,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IMETH)(C,M,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_IMETH)(C,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_BOOLSIG)(O,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_IBOOLSIG)(C,M,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_OBJEQL)(X,Y,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_OBJEQL)(X,Y,CallerInfo).
FLNEGTRAILERPREFIX(WRAP_EXISTS)(X,CallerInfo) :-
	FLNEGHEADPREFIX(WRAP_EXISTS)(X,CallerInfo).
