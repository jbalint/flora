
/****************************************************************************
  WRAP_OBJEQL/3
  Primitive (common) equality maintenance
  Here we just treat :=: as an ordinary symmetric, transitive relation.
****************************************************************************/

/* First, make sure that data types are handled quickly and not tabled */

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