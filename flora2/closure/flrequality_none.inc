/*******************************************************************************
  file: closure/flrequality_none.inc - Equality axioms used everywhere

  Author(s): Guizhen Yang

  Contact:   flora-users@lists.sourceforge.net

  Copyright (C) by
       The Research Foundation of the State University of New York, 1999-2013.

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
/*
   These are the equality axioms used everywhere, even without equality
*/


/****************************************************************************
  WRAP_OBJEQL/3
  Primitive (common) equality maintenance
  Here we just treat :=: as an ordinary symmetric, transitive relation.
****************************************************************************/

/* First, make sure that data types are handled quickly and not tabled */

WRAP_OBJEQL(X,Y,_CallerInfo) :-
	%% when experimenting with subsumptive tabling, need to disable
	%% attibuted vars, since their combo has not been implemented yet
	%% Also replace equality with unification to simplify the tests
	flrutils:flora_experimenting_with(no_attr_vars),
	X=Y,
	!.
WRAP_OBJEQL(X,Y,_CallerInfo) :- (integer(X); integer(Y)), !, X=Y.
WRAP_OBJEQL(X,Y,_CallerInfo) :-
        (flora_datatype_name(X,FL_INTEGER); flora_datatype_name(Y,FL_INTEGER)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_CallerInfo) :-
        (flora_datatype_name(X,FL_LONG); flora_datatype_name(Y,FL_LONG)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_CallerInfo) :-
        (flora_datatype_name(X,FL_STRING); flora_datatype_name(Y,FL_STRING)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_CallerInfo) :-
        (flora_datatype_name(X,FL_IRI); flora_datatype_name(Y,FL_IRI)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_CallerInfo) :-
        (flora_datatype_name(X,FL_BOOL); flora_datatype_name(Y,FL_BOOL)),
	!,
	X=Y.

%% The rest of the axioms: transitivity, reflexivity, symmetry
WRAP_OBJEQL(X,Y,_CallerInfo) :- X=Y.
%%WRAP_OBJEQL(X,Y,_Caller) :- (nonvar(X); nonvar(Y)), X=Y.
WRAP_OBJEQL(X,Y,CallerInfo) :- WRAP_DIFFOBJEQL(X,Y,CallerInfo).

%% WRAP_DIFFOBJEQL means X,Y are equal, but not identical
WRAP_DIFFOBJEQL(X,Y,CallerInfo) :-
	FLTRAILERPREFIX(WRAP_OBJEQL)(X,Y,CallerInfo),
	X \= Y.

WRAP_DIFFOBJEQL(X,Y,CallerInfo) :-
	FLTRAILERPREFIX(WRAP_OBJEQL)(Y,X,CallerInfo),
	X \= Y.

%% transitivity of equality
WRAP_DIFFOBJEQL(X,Y,CallerInfo) :-
	WRAP_DIFFOBJEQL(X,Z,CallerInfo),
	WRAP_DIFFOBJEQL(Z,Y,CallerInfo),
	X \= Y.


/* neg WRAP_OBJEQL  */
FLNEGPREFIX(WRAP_OBJEQL)(X,Y,CallerInfo) :-
        FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,CallerInfo).

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,CallerInfo) :-
	FLNEGTRAILERPREFIX(WRAP_OBJEQL)(X,Y,CallerInfo),
	X \= Y.

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,CallerInfo) :-
	FLNEGPREFIX(WRAP_OBJEQL)(Y,X,CallerInfo),
	X \= Y.

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,CallerInfo) :-
	FLTRAILERPREFIX(WRAP_SUB)(X,Y,CallerInfo).

/* neg WRAP_DIFFOBJEQL  */
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


/*
   WRAP_DIFFOBJEQL_AUX/3 rule must be loaded exactly once. This is why we
   are checking clause(WRAP_DIFFOBJEQL_AUX(_,_,_),_). Reloading this rule
   is not possible when equality is on, since WRAP_DIFFOBJEQL_AUX/3 is
   essentially in the body of every rule (if unfolded).
*/
:- import FLLIBDELAYEDLITERAL/4 from flrdelaysupport.
?-  (
      clause(WRAP_DIFFOBJEQL_AUX(_,_,_),_) -> true
    ;
      assert((
	      WRAP_DIFFOBJEQL_AUX(X,Y,Caller) :-
	        (
	          X = Y
		/*
		; %% this delays WRAP_DIFFOBJEQL untol X or Y is bound
		  FLLIBDELAYEDLITERAL(WRAP_DIFFOBJEQL,
		                      NULL,NULL,
		                      [X,Y,WRAP_DIFFOBJEQL(X,Y,Caller)])
	        */
	        %% ;  when((nonvar(X); nonvar(Y)), WRAP_DIFFOBJEQL(X,Y,Caller))
	        ;  WRAP_DIFFOBJEQL(X,Y,Caller)
	        )
		/*
		  %%Using WRAP_OBJEQL/3 does not work here because when
   		  %%reloading the trailer XSB complains that WRAP_OBJEQL/3 is
   		  %%still being used (by WRAP_DIFFOBJEQL_AUX/3.

		  WRAP_OBJEQL(X,Y,Caller)
	        */
            ))
    ).
