/* File:      FlrException.java
**
** Author(s): Aditi Pandit
**
** Contact:   flora-users@lists.sourceforge.net
** 
** Copyright (C) The Research Foundation of SUNY, 2005, 2006
** 
** FLORA-2 is free software; you can redistribute it and/or modify it under the
** terms of the GNU Library General Public License as published by the Free
** Software Foundation; either version 2 of the License, or (at your option)
** any later version.
** 
** FLORA-2 is distributed in the hope that it will be useful, but WITHOUT ANY
** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for
** more details.
** 
** 
** You should have received a copy of the GNU Library General Public License
** along with FLORA-2; if not, write to the Free Software Foundation,
** Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
**
**
** 
*/
// TODO:  move to org.semwebcentral.flora2.API package
// TODO:  make this a real Exception

package org.semwebcentral.flora2.API.util;

/** 
 * An Exception related to Flora processing in general.
 * This includes exceptions returned by Flora of the form error(Error, Message, Backtrace).
 */
public class FlrException extends RuntimeException{
    private static final long serialVersionUID = 1;

    /**
     * Flora error.
     */
    Object error;

    /**
     * Flora message.
     */
    Object floraMessage;

    /**
     * XSB backtrace (a list of list of large integers).
     */
    Object backtrace;
    
    public FlrException(String message){
	super(message);
    }

    public FlrException(String message, Throwable cause){
	super(message, cause);
    }

    /**
     * Constructs a FlrException from the components of an exception returned by Flora.
     * @param error
     * @param floraMessage
     * @param backtrace
     */
    public FlrException(Object error, Object floraMessage, Object backtrace)
    {
    	super(error + ": " + floraMessage);
    	this.error = error;
    	this.floraMessage = floraMessage;
    	this.backtrace = backtrace;
    }

    public Object getError()
    {
    	return error;
    }

    public Object getFloraMessage()
    {
    	return floraMessage;
    }
    
    public Object getBacktrace()
    {
    	return backtrace;
    }
}
