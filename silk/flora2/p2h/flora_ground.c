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

inline static int is_flora_form(prolog_term term);
inline static int ground(CPtr term);
inline static prolog_term trim(CPtr pterm);
inline static prolog_term trim_compound(prolog_term pterm, int arity);
static inline prolog_term trim_list(prolog_term inList);

DllExport xsbBool call_conv flrground (CTXTdecl)
{
  prolog_term pterm = extern_reg_term(1);

  return ground((CPtr) pterm);
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
    xsb_abort("[FLORA]: Internal bug flrground/1): term with unknown tag (%d)",
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
    return FALSE;	/* so that g++ does not complain */
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
static int is_flora_form(prolog_term pterm)
{
  char *functor;
  if (is_scalar(pterm) || is_list(pterm)) return FALSE;

  functor = extern_p2c_functor(pterm);
  return
  (strncmp(functor, FLORA_META_PREFIX, FLORA_META_PREFIX_LEN)==0);
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
