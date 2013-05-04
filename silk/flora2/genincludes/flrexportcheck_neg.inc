/***************************************************************************
  file: genincludes/flrexportcheck_neg.inc - A template for generating include
  					     file for checking whether the call
					     to a particular explicitly negated
  					     predicate is authorized or not.
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

***************************************************************************/


FLNEGBodyPREFIX(WRAP_ISA)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME', FLNEGPREFIX(WRAP_ISA)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_SUB)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_SUB)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_METH)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_METH)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_IMETH)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_IMETH)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_BOOLSIG)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_BOOLSIG)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_IBOOLSIG)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_IBOOLSIG)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_MVD)(X,Y,Z,CallerInfo) :-
	CallerInfo = [Caller|_],
	flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_MVD)(X,Y,Z,CallerInfo)).

FLNEGBodyPREFIX(WRAP_IMVD)(X,Y,Z,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_IMVD)(X,Y,Z,CallerInfo)).

FLNEGBodyPREFIX(WRAP_MVDDEF)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_MVDDEF)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_IMVDDEF)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_IMVDDEF)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_MVDSIG)(X,Y,Z,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_MVDSIG)(X,Y,Z,CallerInfo)).

FLNEGBodyPREFIX(WRAP_MVDSIGDEF)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_MVDSIGDEF)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_IMVDSIG)(X,Y,Z,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_IMVDSIG)(X,Y,Z,CallerInfo)).

FLNEGBodyPREFIX(WRAP_IMVDSIGDEF)(X,Y,CallerInfo) :- 
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_IMVDSIGDEF)(X,Y,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,X19,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,X19,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,CallerInfo)).

FLNEGBodyPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,CallerInfo) :-
	CallerInfo = [Caller|_],
        flora_check_export_registry(Caller, 'FLORA_THIS_MODULE_NAME',  FLNEGPREFIX(WRAP_TABLED_HILOG)(X01,X02,X03,X04,X05,X06,X07,X08,X09,X10, X11,X12,X13,X14,X15,X16,X17,X18,X19,X20,X21,CallerInfo)).
