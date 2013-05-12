/*******************************************************************************
  file: genincludes/flrpreddef_neg.inc - A template for generating the include
  				       	 file for checking undefinedness.
  					 It is included by flrutils.P at the
					 END of every compiled FLORA-2 file
  Author(s): Michael Kifer

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

FLNEGBodyPREFIX(WRAP_ISA)(X,Y,_Caller) :- 
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_ISA)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_SUB)(X,Y,_Caller),
	flora_error_undefined(WRAP_ISA(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_ISA)(X,Y,[_CallerMod|_TracingInfo]) :- 
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_ISA)(_,Y,_)),
	FLNEGPREFIX(WRAP_ISA)(X,Y,[_CallerMod|_TracingInfo]).
	    
FLNEGBodyPREFIX(WRAP_SUB)(X,Y,_Caller) :- 
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_SUB)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_SUB)(X,Y,_Caller),
	flora_error_undefined(WRAP_SUB(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_SUB)(X,Y,[_CallerMod|_TracingInfo]) :- 
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_SUB)(_,Y,_)),
	FLNEGPREFIX(WRAP_SUB)(X,Y,[_CallerMod|_TracingInfo]).

FLNEGBodyPREFIX(WRAP_METH)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_METH)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_METH)(X,Y,_Caller),
	FLUndefinedPREFIX(WRAP_IMETH)(X,Y,_Caller),
	flora_error_undefined(WRAP_METH(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_METH)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_METH)(_,Y,_)),
	FLNEGPREFIX(WRAP_METH)(X,Y,[_CallerMod|_TracingInfo]).

FLNEGBodyPREFIX(WRAP_IMETH)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_IMETH)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_IMETH)(X,Y,_Caller),
	flora_error_undefined(WRAP_IMETH(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_IMETH)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_METH)(_,Y,_)),
	FLNEGPREFIX(WRAP_IMETH)(X,Y,[_CallerMod|_TracingInfo]).

FLNEGBodyPREFIX(WRAP_BOOLSIG)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_BOOLSIG)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_BOOLSIG)(X,Y,_Caller),
	FLUndefinedPREFIX(WRAP_IBOOLSIG)(X,Y,_Caller),
	flora_error_undefined(WRAP_BOOLSIG(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_BOOLSIG)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_METH)(_,Y,_)),
	FLNEGPREFIX(WRAP_BOOLSIG)(X,Y,[_CallerMod|_TracingInfo]).

FLNEGBodyPREFIX(WRAP_IBOOLSIG)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_IBOOLSIG)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_IBOOLSIG)(X,Y,_Caller),
	flora_error_undefined(WRAP_IBOOLSIG(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_IBOOLSIG)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_METH)(_,Y,_)),
	FLNEGPREFIX(WRAP_IBOOLSIG)(X,Y,[_CallerMod|_TracingInfo]).

FLNEGBodyPREFIX(WRAP_MVD)(X,Y,Z,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_MVD)(X,Y,Z,_Caller)),
	FLUndefinedPREFIX(WRAP_MVD)(X,Y,Z,_Caller),
	FLUndefinedPREFIX(WRAP_IMVD)(X,Y,Z,_Caller),
	FLUndefinedPREFIX(WRAP_MVDDEF)(X,Y,_Caller),
	FLUndefinedPREFIX(WRAP_IMVDDEF)(X,Y,_Caller),
	flora_error_undefined(WRAP_MVD(X,Y,Z,_Caller)).

FLNEGBodyPREFIX(WRAP_MVD)(X,Y,Z,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_MVD)(X,Y,Z,[_CallerMod|_TracingInfo]).
	    
FLNEGBodyPREFIX(WRAP_IMVD)(X,Y,Z,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_IMVD)(X,Y,Z,_Caller)),
	FLUndefinedPREFIX(WRAP_IMVD)(X,Y,Z,_Caller),
	FLUndefinedPREFIX(WRAP_IMVDDEF)(X,Y,_Caller),
	flora_error_undefined(WRAP_IMVD(X,Y,Z,_Caller)).


FLNEGBodyPREFIX(WRAP_IMVD)(X,Y,Z,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_IMVD)(X,Y,Z,[_CallerMod|_TracingInfo]).
	    
FLNEGBodyPREFIX(WRAP_MVDDEF)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_MVDDEF)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_MVDDEF)(X,Y,_Caller),
	FLUndefinedPREFIX(WRAP_IMVDDEF)(X,Y,_Caller),
	FLUndefinedPREFIX(WRAP_MVD)(X,Y,Z,_Caller),
	FLUndefinedPREFIX(WRAP_IMVD)(X,Y,Z,_Caller),
	flora_error_undefined(WRAP_MVDDEF(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_MVDDEF)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_MVDDEF)(X,Y,[_CallerMod|_TracingInfo]).
	    
FLNEGBodyPREFIX(WRAP_IMVDDEF)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_IMVDDEF)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_IMVDDEF)(X,Y,_Caller),
	FLUndefinedPREFIX(WRAP_IMVD)(X,Y,Z,_Caller),
	flora_error_undefined(WRAP_IMVDDEF(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_IMVDDEF)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_IMVDDEF)(X,Y,[_CallerMod|_TracingInfo]).
	    
FLNEGBodyPREFIX(WRAP_MVDSIG)(X,Y,Z,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_MVDSIG)(X,Y,Z,_Caller)),
	FLUndefinedPREFIX(WRAP_MVDSIG)(X,Y,Z,_Caller),
	FLUndefinedPREFIX(WRAP_IMVDSIG)(X,Y,Z,_Caller),
	flora_error_undefined(WRAP_MVDSIG(X,Y,Z,_Caller)).

FLNEGBodyPREFIX(WRAP_MVDSIG)(X,Y,Z,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_MVDSIG)(X,Y,Z,[_CallerMod|_TracingInfo]).

FLNEGBodyPREFIX(WRAP_MVDSIGDEF)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_MVDSIGDEF)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_MVDSIGDEF)(X,Y,_Caller),
	FLUndefinedPREFIX(WRAP_IMVDSIGDEF)(X,Y,_Caller),
	flora_error_undefined(WRAP_MVDSIGDEF(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_MVDSIGDEF)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_MVDSIGDEF)(X,Y,[_CallerMod|_TracingInfo]).
	    
FLNEGBodyPREFIX(WRAP_IMVDSIG)(X,Y,Z,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_IMVDSIG)(X,Y,Z,_Caller)),
	FLUndefinedPREFIX(WRAP_IMVDSIG)(X,Y,Z,_Caller),
	flora_error_undefined(WRAP_IMVDSIG(X,Y,Z,_Caller)).

FLNEGBodyPREFIX(WRAP_IMVDSIG)(X,Y,Z,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_IMVDSIG)(X,Y,Z,[_CallerMod|_TracingInfo]).

FLNEGBodyPREFIX(WRAP_IMVDSIGDEF)(X,Y,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_IMVDSIGDEF)(X,Y,_Caller)),
	FLUndefinedPREFIX(WRAP_IMVDSIGDEF)(X,Y,_Caller),
	flora_error_undefined(WRAP_IMVDSIGDEF(X,Y,_Caller)).

FLNEGBodyPREFIX(WRAP_IMVDSIGDEF)(X,Y,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_MVD)(_,Y,_,_)),
	FLNEGPREFIX(WRAP_IMVDSIGDEF)(X,Y,[_CallerMod|_TracingInfo]).

%% For exists (a[]) it doesn't make sense to check for definedness
FLNEGBodyPREFIX(WRAP_EXISTS)(X,[_CallerMod|_TracingInfo]) :-
	FLNEGPREFIX(WRAP_EXISTS)(X,[_CallerMod|_TracingInfo]).
	    


/*
    Undefinedness checking for tabled HiLog
*/

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,_Caller) :-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,[_CallerMod|_TracingInfo]).
	

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,[_CallerMod|_TracingInfo]).


FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,_Caller)
	:-
	debugging,
        \+ FLORA_IGNORE_UNDEFCHECK(FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,_Caller)),
	FLUndefinedPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,_Caller),
	flora_error_undefined(WRAP_TABLED_HILOG(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,_Caller)).
FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,[_CallerMod|_TracingInfo]) :-
	flora_bind_to_export_registry(_CallerMod,'FLORA_THIS_MODULE_NAME',FLBodyPREFIX(WRAP_TABLED_HILOG)(X01,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)),
	FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,[_CallerMod|_TracingInfo]).

