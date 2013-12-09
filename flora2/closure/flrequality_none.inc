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

WRAP_OBJEQL(X,Y,_FWContext) :-
	%% when experimenting with subsumptive tabling, need to disable
	%% attibuted vars, since their combo has not been implemented yet
	%% Also replace equality with unification to simplify the tests
	flrutils:flora_experimenting_with(no_attr_vars),
	X=Y,
	!.
WRAP_OBJEQL(X,Y,_FWContext) :- (integer(X); integer(Y)), !, X=Y.
WRAP_OBJEQL(X,Y,_FWContext) :-
        (flora_datatype_name(X,FL_INTEGER); flora_datatype_name(Y,FL_INTEGER)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_FWContext) :-
        (flora_datatype_name(X,FL_LONG); flora_datatype_name(Y,FL_LONG)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_FWContext) :-
        (flora_datatype_name(X,FL_STRING); flora_datatype_name(Y,FL_STRING)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_FWContext) :-
        (flora_datatype_name(X,FL_IRI); flora_datatype_name(Y,FL_IRI)),
	!,
	X=Y.
WRAP_OBJEQL(X,Y,_FWContext) :-
        (flora_datatype_name(X,FL_BOOL); flora_datatype_name(Y,FL_BOOL)),
	!,
	X=Y.

%% The rest of the axioms: transitivity, reflexivity, symmetry
WRAP_OBJEQL(X,Y,_FWContext) :- X=Y.
%%WRAP_OBJEQL(X,Y,_FWContext) :- (nonvar(X); nonvar(Y)), X=Y.
WRAP_OBJEQL(X,Y,FL_CONTEXT(Caller,_,_)) :- WRAP_DIFFOBJEQL(X,Y,FL_CONTEXT(Caller,_,_)).

%% WRAP_DIFFOBJEQL means X,Y are equal, but not identical
WRAP_DIFFOBJEQL(X,Y,FL_CONTEXT(Caller,_,_)) :-
	FLTRAILERPREFIX(WRAP_OBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)),
	X \= Y.

WRAP_DIFFOBJEQL(X,Y,FL_CONTEXT(Caller,_,_)) :-
	FLTRAILERPREFIX(WRAP_OBJEQL)(Y,X,FL_CONTEXT(Caller,_,_)),
	X \= Y.

%% transitivity of equality
WRAP_DIFFOBJEQL(X,Y,FL_CONTEXT(Caller,_,_)) :-
	WRAP_DIFFOBJEQL(X,Z,FL_CONTEXT(Caller,_,_)),
	WRAP_DIFFOBJEQL(Z,Y,FL_CONTEXT(Caller,_,_)),
	X \= Y.


/* neg WRAP_OBJEQL  */
FLNEGPREFIX(WRAP_OBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)) :-
        FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)) :-
	FLNEGTRAILERPREFIX(WRAP_OBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)),
	X \= Y.

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)) :-
	FLNEGPREFIX(WRAP_OBJEQL)(Y,X,FL_CONTEXT(Caller,_,_)),
	X \= Y.

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)) :-
	FLTRAILERPREFIX(WRAP_SUB)(X,Y,FL_CONTEXT(Caller,_,_)).

/* neg WRAP_DIFFOBJEQL  */
%% WRAP_DIFFOBJEQL means X,Y are unequal and not identical
FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)) :-
	WRAP_DIFFOBJEQL(X,V,FL_CONTEXT(Caller,_,_)),
	WRAP_DIFFOBJEQL(Y,W,FL_CONTEXT(Caller,_,_)),
	X \= Y,
	FLNEGTRAILERPREFIX(WRAP_OBJEQL)(V,W,FL_CONTEXT(Caller,_,_)).

FLNEGPREFIX(WRAP_DIFFOBJEQL)(X,Y,FL_CONTEXT(Caller,_,_)) :-
	WRAP_DIFFOBJEQL(X,V,FL_CONTEXT(Caller,_,_)),
	WRAP_DIFFOBJEQL(Y,W,FL_CONTEXT(Caller,_,_)),
	X \= Y,
	FLNEGTRAILERPREFIX(WRAP_OBJEQL)(W,V,FL_CONTEXT(Caller,_,_)).


/*
   WRAP_DIFFOBJEQL_AUX/3 rule must be loaded exactly once. This is why we
   are checking clause(WRAP_DIFFOBJEQL_AUX(_,_,_),_). Reloading this rule
   is not possible when equality is on, since WRAP_DIFFOBJEQL_AUX/3 is
   essentially in the body of every rule (if unfolded).
*/
:- import FLLIBDELAYEDLITERAL/4 from usermod.
?-  (
      clause(WRAP_DIFFOBJEQL_AUX(_,_,_),_) -> true
    ;
      assert((
	      WRAP_DIFFOBJEQL_AUX(X,Y,Caller) :-
	        (
	          X = Y
		/*
		; %% this delays WRAP_DIFFOBJEQL until X or Y is bound
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
