/*******************************************************************************
  file: closure/flrimportaxioms_neg.inc - Axioms for the importmodule directive
  					  in support of explicit negation.
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

#define FLORA_IMPORT_NEG_WRAPPER(Wrap) FLORA_WORKSPACE(FLORA_IMPORTED_MODULE_UNQUOTED,FLNEGPREFIX_UNQ(Wrap))

/* Axioms for negated literals in imported module */

FLNEGBodyPREFIX(WRAP_SUB)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_SUB))(_,Y,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_SUB)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_ISA)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_ISA))(_,Y,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_ISA)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_IMVD)(X,Y,Z,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_IMVD)(X,Y,Z,[Caller|_]).

FLNEGBodyPREFIX(WRAP_IMVDDEF)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_IMVDDEF)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_MVD)(X,Y,Z,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_MVD)(X,Y,Z,[Caller|_]).

FLNEGBodyPREFIX(WRAP_MVDDEF)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_MVDDEF)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_METH)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_METH))(_,Y,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_METH)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_IMETH)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_METH))(_,Y,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_IMETH)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_BOOLSIG)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_METH))(_,Y,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_BOOLSIG)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_IBOOLSIG)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_METH))(_,Y,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_IBOOLSIG)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_MVDSIG)(X,Y,Z,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_MVDSIG)(X,Y,Z,[Caller|_]).

FLNEGBodyPREFIX(WRAP_MVDSIGDEF)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_MVDSIGDEF)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_IMVDSIG)(X,Y,Z,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_IMVDSIG)(X,Y,Z,[Caller|_]).

FLNEGBodyPREFIX(WRAP_IMVDSIGDEF)(X,Y,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_MVD))(_,Y,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_IMVDSIGDEF)(X,Y,[Caller|_]).

FLNEGBodyPREFIX(WRAP_EXISTS)(X,[Caller|_])
    	:-
	FLORA_IMPORT_WRAPPER(WRAP_EXISTS)(X,[Caller|_]).

FLNEGBodyPREFIX(WRAP_OBJEQL)(X,Y,[Caller|_])
    	:-
	FLORA_IMPNEG_WRAPPERORT_WRAPPER(WRAP_OBJEQL)(X,Y,[Caller|_]).



FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,[Caller|_])
	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
 	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,[Caller|_]).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,[Caller|_])
    	:-
	flora_bind_to_export_registry(Caller,'FLORA_IMPORTED_MODULE',FLORA_IMPORT_WRAPPER(FLNEGBodyPREFIX_UNQ(WRAP_TABLED_HILOG))(X1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLORA_IMPORT_NEG_WRAPPER(WRAP_TABLED_HILOG)(X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,[Caller|_]).

