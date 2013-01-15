/* File:      FloraSession.java
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

package org.semwebcentral.flora2.API;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Vector;
import java.io.File;

import org.semwebcentral.flora2.API.util.FlrException;

import com.declarativa.interprolog.PrologEngine;
import com.declarativa.interprolog.TermModel;

/** This class is a higher level wrapper to call the 
   lower level functions of the PrologFlora class
*/
public class FloraSession extends FloraConstants
{
    public PrologFlora flora;

    /* Constructor function. */
    public FloraSession()
    {
	flora = new PrologFlora();	
	if(debug)
	    System.out.println("FLORA-2 session started");
    }
	

    /* Execute a command at the FLORA-2 session
    ** True, if the command succeeds
    **
    ** command : the command to be executed
    */
    public boolean ExecuteCommand(String command)
    {
	boolean result = false;
	try {
	    result = flora.simpleFloraCommand(doubleEachQuote(command));
	    if (debug)
		System.out.println("ExecuteCommand: "+command);
	}
	catch (FlrException e) {
	    throw e;
	}
	catch (Exception e) {
	    throw new FlrException("Executing FLORA command " + command, e);
	}
	return result;
    }
	
    /* Execute a command at the FLORA-2 session 
    ** The answer is a resultset that can be queried
    **
    ** query : Flora query to be executed 
    ** vars : Vector of variables to be bound
    */
    public Iterator<HashMap<String, FloraObject>> FindAllMatches(String query,Vector<String> vars)
    {
	Vector<HashMap<String,FloraObject>> retBindings = new Vector<HashMap<String,FloraObject>>();
	Object[] bindings = null;
		
	try {
	    if (debug) {
		System.out.println("FindAllMatches, before FloraCommand. Query = " + query);
		System.out.println("FindAllMatches, before FloraCommand. Vars = " + vars);
	    }
	    bindings = flora.FloraCommand(doubleEachQuote(query),vars);
	    if (debug) {
		System.out.println("FindAllMatches, after FloraCommand: " + bindings);
	    }
	 
	    for (int i=0; i<bindings.length; i++) {
				
		TermModel tm = (TermModel)bindings[i];
		HashMap<String,FloraObject> currBinding = new HashMap<String,FloraObject>();
		for (int j=0; j<vars.size(); j++) {
		    String varValue = vars.elementAt(j);

		    if (debug) {
			System.out.println("FindAllMatches, term model: " + tm);
			System.out.println("FindAllMatches, varValue="+varValue);
		    }

		    TermModel objName = PrologFlora.findValue(tm,varValue);
		    FloraObject obj = new FloraObject(objName,this);
		    currBinding.put(varValue,obj);		
		}		
		retBindings.add(currBinding);
	    }
	}
	catch (FlrException e) {
	    throw e;
	}
	catch (Exception e) {
	    throw new FlrException("Executing FLORA query " + query, e);
	}

	Iterator<HashMap<String, FloraObject>> iter = retBindings.iterator();
	return iter;
    }

    
    public void close()
    {
	flora.close();
    }

    
    /* Load a FLORA-2 file into a module
    ** fileName : file to be loaded 
    ** moduleName : module name to load the file into
    */
    public boolean loadFile(String fileName,String moduleName)
    {
	return flora.loadFile(fileName,moduleName);
    }
    
    
    /* Compile a FLORA-2 file for a module
    ** fileName : file to be compiled 
    ** moduleName : module name to compile the file for
    */
    public boolean compileFile(String fileName,String moduleName)
    {
	return flora.compileFile(fileName,moduleName);
    }


    /* Add a FLORA-2 file to an existing module
    ** fileName : file to be added 
    ** moduleName : module name to add the file to
    */
    public boolean addFile(String fileName,String moduleName)
    {
	return flora.addFile(fileName,moduleName);
    }


    /* Compile a FLORA-2 file for addition to a module
    ** fileName : file to be compiled 
    ** moduleName : module name to compile the file for
    */
    public boolean compileaddFile(String fileName,String moduleName)
    {
	return flora.compileaddFile(fileName,moduleName);
    }
    
    /** Delegates to same method in PrologFlora. 
    @see org.semwebcentral.flora2.API.PrologFlora#setLoadProgressHandler(String) */
    public void setLoadProgressHandler(String handler){
    	flora.setLoadProgressHandler(handler);
    }
    
    /** Delegates to same method in PrologFlora. 
    @see org.semwebcentral.flora2.API.PrologFlora#setLoadProgressHandler(String,double) */
    public void setLoadProgressHandler(String handler,double period){
    	flora.setLoadProgressHandler(handler,period);
    }
        
    /* Execute a query with variables
    **
    ** query : query to be executed
    ** vars : variables in the query
    */
    public Iterator<HashMap<String, FloraObject>> ExecuteQuery(String query,Vector<String> vars)
    {
	return FindAllMatches(query,vars);
    }

    
    /*
    ** Like ExecuteQuery/2 above, but is used only when a query has
    ** just one variable. This provides a simplified interface, since
    ** no variables need to be passed into ExecuteQuery/1 and the
    ** output is just an iterator, which contains just a list of
    ** bindings for that single variable.
    **
    ** query : query to be executed
    */
    public Iterator<FloraObject> ExecuteQuery(String query)
    {
	Vector<FloraObject> retBindings = new Vector<FloraObject>();
	Object[] bindings = null;
		
	Vector<String> vars = new Vector<String>();
	vars.add("?");
	try {
	    bindings = flora.FloraCommand(doubleEachQuote(query),vars);
			
	    for (int i=0; i<bindings.length; i++) {
		TermModel tm = (TermModel)bindings[i];
		TermModel objName = PrologFlora.findValue(tm,null);
		if (debug) {
		    System.out.println("ExecuteQuery/1, term model: " + tm);
		    System.out.println("ExecuteQuery/1, objName="+objName);
		}
		FloraObject obj = new FloraObject(objName,this);
		retBindings.add(obj);
	    }
	}
	catch(FlrException e) {
	    throw e;
	}
	catch(Exception e) {
	    throw new FlrException("Executing FLORA query " + query, e);
	}
	Iterator<FloraObject> iter = retBindings.iterator();
	return iter;
    }	
    
    public PrologEngine getEngine()
    {
    	return flora.engine;
    }

    /* Utility to double each quote */
    private String doubleEachQuote(String str)
    {
	String outstr = "";

	for (int i=0; i<str.length(); i++) {
	    char ch = str.charAt(i);
	    if (ch == '\'')
		outstr += "''";
	    else
		outstr += String.valueOf(ch);
	}
	return outstr;
    }
}
