/* File:      flora_ground.c
** Author(s): kifer
**
** Contact:   kifer@cs.stonybrook.edu
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2008.
**
** All rights reserved.
**
** For information about licensing terms, please see
** http://silk.projects.semwebcentral.org/flora2-license.html
**
**
*/


#if 0
#define FG_DEBUG
#endif

#include "xsb_config.h"

#include <stdio.h>
#include <string.h>

#ifdef WIN_NT
#define XSB_DLL
#endif

#include "auxlry.h"
#include "context.h"
#include "cell_xsb.h"
#include "error_xsb.h"
#include "cinterf.h"
#include "deref.h"


#define FLORA_META_PREFIX         "_$_$_flora'mod"
#define FLORA_META_PREFIX_LEN     14

#define FLORA_TNOT_PREDICATE      "flora_tnot"
#define FLORA_TNOT_LEN            10

#define FL_TRUTHVALUE_TABLED_CALL "truthvalue_tabled_call"
#define FL_TABLED_UNNUMBER_CALL   "tabled_unnumber_call"
#define FL_UNDEFEATED             "undefeated"

inline static int is_flora_form(prolog_term term);
inline static int is_flora_tnot_predicate(prolog_term pterm);
inline static int ground(CPtr term);
inline static prolog_term trim(CPtr pterm);
inline static prolog_term trim_compound(prolog_term pterm, int arity);
inline static prolog_term trim_list(prolog_term inList);
inline static void term_vars(CPtr pterm, CPtr* pvars, CPtr* pvarstail);
inline static void term_vars_split(CPtr pterm,
				   CPtr* pvars, CPtr* pvarstail,
				   CPtr* pattrvars, CPtr* pattrvarstail);

#ifdef FG_DEBUG
static char *pterm2string(CTXTdeclc prolog_term term);
#endif

DllExport xsbBool call_conv flratom_char_code (CTXTdecl)
{
  char *inatom = ptoc_string(CTXTc 1);
  Integer pos = ptoc_int(CTXTc 2);
  Integer charcode = inatom[pos];
  prolog_term pcode = p2p_new();
  prolog_term out = extern_reg_term(3);
  
  c2p_int(CTXTc charcode,pcode);
  return extern_p2p_unify(pcode,out);
}

DllExport xsbBool call_conv flrground (CTXTdecl)
{
  prolog_term pterm = extern_reg_term(1);

  return ground((CPtr) pterm);
}

DllExport xsbBool call_conv flrnonground (CTXTdecl)
{
  prolog_term pterm = extern_reg_term(1);

  return !ground((CPtr) pterm);
}


DllExport xsbBool call_conv flrterm_vars (CTXTdecl)
{
  prolog_term pterm = extern_reg_term(1);
  prolog_term outvars = extern_reg_term(2);
  prolog_term vars = extern_p2p_new();
  prolog_term tail = vars;

#ifdef FG_DEBUG
  fprintf(stderr,"term_vars: pterm=%s\n", pterm2string(CTXTc pterm));
#endif

  term_vars((CPtr) pterm, (CPtr *) &vars, (CPtr*) &tail);
  
#ifdef FG_DEBUG
  fprintf(stderr,"term_vars2: vars=%s\n", pterm2string(CTXTc vars));
  fprintf(stderr,"term_vars2: tail=%s\n", pterm2string(CTXTc tail));
#endif

  extern_c2p_nil(tail);
  return extern_p2p_unify(vars,outvars);
}


DllExport xsbBool call_conv flrterm_vars_split (CTXTdecl)
{
  prolog_term pterm = extern_reg_term(1);
  prolog_term outvars = extern_reg_term(2);
  prolog_term outattrvars = extern_reg_term(3);
  prolog_term vars = extern_p2p_new();
  prolog_term tail = vars;
  prolog_term attrvars = extern_p2p_new();
  prolog_term attrtail = attrvars;

#ifdef FG_DEBUG
  fprintf(stderr,"term_vars_split: pterm=%s\n", pterm2string(CTXTc pterm));
#endif

  term_vars_split((CPtr)pterm,
		  (CPtr *)&vars, (CPtr*)&tail,
		  (CPtr *)&attrvars, (CPtr*)&attrtail);
  
#ifdef FG_DEBUG
  fprintf(stderr,"term_vars_split2: vars=%s\n", pterm2string(CTXTc vars));
  fprintf(stderr,"term_vars_split2: tail=%s\n", pterm2string(CTXTc tail));
#endif

  extern_c2p_nil(tail);
  extern_c2p_nil(attrtail);
  return (extern_p2p_unify(vars,outvars) && extern_p2p_unify(attrvars,outattrvars));
}


int ground(CPtr pterm)
{
  int j, arity;

 groundBegin:
  XSB_CptrDeref(pterm);
  switch(cell_tag(pterm)) {
  case XSB_FREE:
  case XSB_REF1:
  case XSB_ATTV:
    return FALSE;

  case XSB_STRING:
  case XSB_INT:
  case XSB_FLOAT:
    return TRUE;

  case XSB_LIST:
    if (!ground(clref_val(pterm)))
      return FALSE;
    pterm = clref_val(pterm)+1;
    goto groundBegin;

  case XSB_STRUCT:
    arity = (int) get_arity(get_str_psc(pterm));
    if (arity == 0) return TRUE;
    for (j=1; j < arity ; j++)
      if (!ground(clref_val(pterm)+j))
	return FALSE;
    if (is_flora_form((prolog_term)pterm))
      return TRUE;

    pterm = clref_val(pterm)+arity;
    goto groundBegin;

  default:
    xsb_abort("[FLORA]: BUG in flrground/1: term with unknown tag (%d)",
	      (int)cell_tag(pterm));
    return FALSE;	/* so that g++ does not complain */
  }
}


DllExport xsbBool call_conv flrtrim_last(CTXTdecl)
{
  prolog_term pterm = extern_reg_term(1);
  prolog_term trimmedterm = extern_reg_term(2);

  return extern_p2p_unify(trimmedterm, trim((CPtr) pterm));
  return TRUE;
}

prolog_term trim(CPtr pterm)
{
  int arity;
  XSB_CptrDeref(pterm);
  switch(cell_tag(pterm)) {
  case XSB_FREE:
  case XSB_REF1:
  case XSB_ATTV:
  case XSB_STRING:
  case XSB_INT:
  case XSB_FLOAT:
    return (prolog_term)pterm;

  case XSB_LIST:
    return trim_list((prolog_term)pterm);

  case XSB_STRUCT:
    arity = (int) get_arity(get_str_psc(pterm));
    if (arity == 0) return (prolog_term)pterm;
    return trim_compound((prolog_term)pterm,arity);

  default:
    xsb_abort("[FLORA]: Internal bug (flrtrim_last/2): term with unknown tag (%d)",
	      (int)cell_tag(pterm));
    return FALSE;
  }
}


void term_vars(CPtr pterm, CPtr* pvars, CPtr* pvarstail)
{
  int j, arity;

 groundBegin:
  XSB_CptrDeref(pterm);
  switch(cell_tag(pterm)) {
  case XSB_FREE:
  case XSB_REF1:
  case XSB_ATTV:
#ifdef FG_DEBUG
    fprintf(stderr,"v1: Arg1=%s\n",pterm2string(CTXTc (prolog_term)pterm));
    fprintf(stderr,"v1: Arg2=%s\n",pterm2string(CTXTc (prolog_term)*pvars));
    fprintf(stderr,"v1: Arg3=%s\n",pterm2string(CTXTc (prolog_term)*pvarstail));
#endif

    extern_c2p_list((prolog_term) *pvarstail);
    extern_p2p_unify((prolog_term) pterm,
		     extern_p2p_car((prolog_term) *pvarstail));
    pvars = (CPtr *) pvarstail;
    *pvarstail = (CPtr) extern_p2p_cdr((prolog_term) *pvarstail);
#ifdef FG_DEBUG
    fprintf(stderr,"v2: Arg1=%s\n",pterm2string(CTXTc (prolog_term)pterm));
    fprintf(stderr,"v2: Arg2=%s\n",pterm2string(CTXTc (prolog_term)*pvars));
    fprintf(stderr,"v2: Arg3=%s\n",pterm2string(CTXTc (prolog_term)*pvarstail));
#endif
    return;

  case XSB_STRING:
  case XSB_INT:
  case XSB_FLOAT:
    return;

  case XSB_LIST:
    term_vars(clref_val(pterm),pvars,pvarstail);
    pterm = clref_val(pterm)+1;
    goto groundBegin;

  case XSB_STRUCT:
    arity = (int) get_arity(get_str_psc(pterm));
    // if it is FLORA_TNOT_PREDICATE(Call,File,Line), get vars from Call only
    if (is_flora_tnot_predicate((prolog_term) pterm) && arity == 3) {
      term_vars(clref_val(pterm)+1,pvars,pvarstail);
      return;
    }
    if (arity == 0)
      return;
    for (j=1; j < arity; j++) {
#ifdef FG_DEBUG
      fprintf(stderr,"strct: Arg1=%s\n",
              pterm2string(CTXTc (prolog_term) *(clref_val(pterm)+j)));
      fprintf(stderr,"strct: Arg2=%s\n",
              pterm2string(CTXTc (prolog_term) *pvars));
      fprintf(stderr,"strct: Arg3=%s\n",
              pterm2string(CTXTc (prolog_term) *pvarstail));
#endif

      term_vars(clref_val(pterm)+j,pvars,pvarstail);

#ifdef FG_DEBUG
      fprintf(stderr,"strct2: Arg1=%s\n",
              pterm2string(CTXTc (prolog_term) *(clref_val(pterm)+j)));
      fprintf(stderr,"strct2: Arg2=%s\n",
              pterm2string(CTXTc (prolog_term) *pvars));
      fprintf(stderr,"strct2: Arg3=%s\n",
              pterm2string(CTXTc (prolog_term) *pvarstail));
#endif
    }
    // if this is a flora formula, no need to check the last argument
    if (is_flora_form((prolog_term)pterm))
      return;

    pterm = clref_val(pterm)+arity;
    goto groundBegin;

  default:
    xsb_abort("[FLORA]: BUG in flrterm_vars/1: term with unknown tag (%d)",
	      (int)cell_tag(pterm));
    return;
  }
}



// this one splits attributed from regular vars
void term_vars_split(CPtr pterm,
		     CPtr* pvars, CPtr* pvarstail,
		     CPtr* pattrvars, CPtr* pattrvarstail)
{
  int j, arity;

 groundBegin:
  XSB_CptrDeref(pterm);
  switch(cell_tag(pterm)) {
  case XSB_FREE:
  case XSB_REF1:
    extern_c2p_list((prolog_term) *pvarstail);
    extern_p2p_unify((prolog_term) pterm,
		     extern_p2p_car((prolog_term) *pvarstail));
    pvars = (CPtr *) pvarstail;
    *pvarstail = (CPtr) extern_p2p_cdr((prolog_term) *pvarstail);
    return;

  case XSB_ATTV:
    extern_c2p_list((prolog_term) *pattrvarstail);
    extern_p2p_unify((prolog_term) pterm,
		     extern_p2p_car((prolog_term) *pattrvarstail));
    pattrvars = (CPtr *) pattrvarstail;
    *pattrvarstail = (CPtr) extern_p2p_cdr((prolog_term) *pattrvarstail);
    return;

  case XSB_STRING:
  case XSB_INT:
  case XSB_FLOAT:
    return;

  case XSB_LIST:
    term_vars_split(clref_val(pterm),pvars,pvarstail,pattrvars,pattrvarstail);
    pterm = clref_val(pterm)+1;
    goto groundBegin;

  case XSB_STRUCT:
    arity = (int) get_arity(get_str_psc(pterm));
    // if it is FLORA_TNOT_PREDICATE(Call,File,Line), get vars from Call only
    if (is_flora_tnot_predicate((prolog_term) pterm) && arity == 3) {
      term_vars_split(clref_val(pterm)+1,pvars,pvarstail,pattrvars,pattrvarstail);
      return;
    }
    if (arity == 0)
      return;
    for (j=1; j < arity; j++) {
      term_vars_split(clref_val(pterm)+j,pvars,pvarstail,pattrvars,pattrvarstail);
    }
    // if this is a flora formula, no need to check the last argument
    if (is_flora_form((prolog_term)pterm))
      return;

    pterm = clref_val(pterm)+arity;
    goto groundBegin;

  default:
    xsb_abort("[FLORA]: BUG in flrterm_vars_split/1: term with unknown tag (%d)",
	      (int)cell_tag(pterm));
    return;
  }
}



/***** auxiliary *******/

static inline xsbBool is_scalar(prolog_term pterm)
{
  if (is_atom(pterm) || is_int(pterm) || is_float(pterm))
    return TRUE;
  return FALSE;
}


/* Check if pterm represents a formula rather than a term */
static inline int is_flora_form(prolog_term pterm)
{
  char *functor;
  int has_flora_prefix;

  if (is_scalar(pterm) || is_list(pterm)) return FALSE;

  functor = extern_p2c_functor(pterm);
  has_flora_prefix =
    (strncmp(functor,FLORA_META_PREFIX,FLORA_META_PREFIX_LEN)==0);

  /*
  if (has_flora_prefix &&
      (strstr(functor,FL_TRUTHVALUE_TABLED_CALL)
       || strstr(functor,FL_TABLED_UNNUMBER_CALL)
       || strstr(functor,FL_UNDEFEATED)
       ))
    return FALSE;
  */
  if (has_flora_prefix && strstr(functor,FL_UNDEFEATED))
    return FALSE;

  return (has_flora_prefix);
}


/* Check if pterm represents a formula rather than a term */
static inline int is_flora_tnot_predicate(prolog_term pterm)
{
  char *functor;
  functor = extern_p2c_functor(pterm);
  return (strncmp(functor, FLORA_TNOT_PREDICATE, FLORA_TNOT_LEN)==0);
}


/* assumes compound arity > 0 */
static inline prolog_term trim_compound(prolog_term pterm, int arity)
{
  prolog_term trimmed=extern_p2p_new();
  int j;

  extern_c2p_functor(extern_p2c_functor(pterm), arity-1, trimmed);
  for (j=1; j < arity ; j++)
    extern_p2p_unify(extern_p2p_arg(pterm,j), extern_p2p_arg(trimmed,j));

  return trimmed;
}

/* assumes list is non-nil */
static inline prolog_term trim_list(prolog_term inList)
{
  prolog_term inListHead, inListTail;
  prolog_term trimmedList=extern_p2p_new(), trimmedHead, trimmedTail;


  inListTail = inList;
  trimmedTail = trimmedList;

  while (!is_nil(inListTail)) {
    if (is_list(inListTail)) {
      inListHead = extern_p2p_car(inListTail);
      inListTail = extern_p2p_cdr(inListTail);
      if (!is_nil(inListTail)) {
	extern_c2p_list(trimmedTail);
	trimmedHead = extern_p2p_car(trimmedTail);
	extern_p2p_unify(trimmedHead, inListHead);
	trimmedTail = extern_p2p_cdr(trimmedTail);
      }
    }
    else
      break;
  }

  extern_c2p_nil(trimmedTail); /* bind trimmed tail to nil */
  
  return trimmedList;
}

#ifdef FG_DEBUG
static char *pterm2string(CTXTdeclc prolog_term term)
{ 
  static VarString *StrArgBuf;
  prolog_term term2 = extern_p2p_deref(term);

  XSB_StrCreate(&StrArgBuf);
  XSB_StrSet(StrArgBuf,"");
  extern_print_pterm(term2, 1, StrArgBuf); 
  return StrArgBuf->string;
} 
#endif
