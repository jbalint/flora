/* File:      PrologFlora.java
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
*/


package org.semwebcentral.flora2.API;

import java.io.File;
import java.util.Vector;

import org.apache.log4j.Level;
import org.apache.log4j.Logger;

import org.semwebcentral.flora2.API.util.FlrException;

import com.declarativa.interprolog.PrologEngine;
import com.declarativa.interprolog.PrologOutputListener;
import com.declarativa.interprolog.TermModel;
import com.declarativa.interprolog.XSBSubprocessEngine;
import com.declarativa.interprolog.util.IPException;
import com.declarativa.interprolog.util.OutputListener;
import com.xsb.interprolog.NativeEngine;

/** This class is used to call FLORA-2 commands 
    at a low level from JAVA using Interprolog libraries */
public class PrologFlora extends FloraConstants
{
    public static String sFloraRootDir = null;
    PrologEngine engine;
    boolean isNative = false;
    String commands[];

    private static Logger logger = Logger.getLogger(PrologFlora.class);

    
    /* Function for setting Initialization commands */
    void initCommandStrings(String FloraRootDir)
    {
	commands = (new String[] {
		"(import bootstrap_flora/0 from flora2)",
		String.valueOf(String.valueOf((new StringBuffer("asserta(library_directory('")).append(FloraRootDir).append("'))"))),
		"consult(flora2)",
		"bootstrap_flora",
		"consult(flrimportedcalls)",
		"import ('_load')/1, ('_add')/1 from flora2",
		"import flora_query/4 from flora2",
		"import flora_decode_oid_as_atom/2 from flrdecode"
	    });
    }
    

    /* Function to execute the initialization commands */
    void executeInitCommands()
    {
        if(commands == null)
            throw new FlrException("\n*** Java-FLORA-2 interface: System bug, please report\n");

	for(int i = 0; i < commands.length; i++) {
	    boolean cmdsuccess = simplePrologCommand(commands[i]);
	    if(!cmdsuccess)
		throw new FlrException("\n*** Java-FLORA-2 interface: FLORA-2 startup failed\n");
	}
    }


    /* Function to use _load to load FLORA-2 file into moduleName
    ** fileName   : name of the file to load
    ** moduleName : name of FLORA module in which to load
    */
    public boolean loadFile(String fileName,String moduleName)
    {
	boolean cmdsuccess = false; 
	String cmd = "'_load'('"+fileName + "'>>" + moduleName+")";
	try {
	    cmdsuccess = engine.deterministicGoal(cmd);
	    // Don't use command: it is not error-sensitive
	    //cmdsuccess = engine.command(cmd);
	}
	catch(IPException e) {
	    e.printStackTrace();
	    throw new FlrException("\n*** Java-FLORA-2 interface: Command "+ cmd + " failed\n");
	}
        return cmdsuccess;
    }


    /* Function to use _compile to compile FLORA-2 file for moduleName
    ** fileName   : name of the file to compile
    ** moduleName : name of FLORA module for which to compile
    */
    public boolean compileFile(String fileName,String moduleName)
    {
	boolean cmdsuccess = false; 
	String cmd = "'_compile'('"+fileName + "'>>" + moduleName+")";
	try {
	    cmdsuccess = engine.deterministicGoal(cmd);
	    // command is not error-sensitive
	    //cmdsuccess = engine.command(cmd);
	}
	catch(IPException e) {
	    e.printStackTrace();
	    throw new FlrException("\n*** Java-FLORA-2 interface: Command "+ cmd + " failed\n");
	}
        return cmdsuccess;
    }


    /* Function to use _add to add FLORA-2 file to moduleName
    ** fileName   : name of the file to add
    ** moduleName : name of FLORA module to which to add
    */
    public boolean addFile(String fileName,String moduleName)
    {
    boolean cmdsuccess = false;
	String cmd = "'_add'('"+fileName + "'>>" + moduleName+")";
	try {
	    cmdsuccess = engine.deterministicGoal(cmd);
	    //cmdsuccess = engine.command(cmd);
	}
	catch(IPException e) {
	    e.printStackTrace();
	    throw new FlrException("\n*** Java-FLORA-2 interface: Command "+ cmd + " failed\n");
	}
        return cmdsuccess;
    }

    
    /* Function to use _compileadd to compile FLORA-2 file for adding to moduleName
    ** fileName   : name of the file to compile for addition
    ** moduleName : name of FLORA module for which to compile-add
    */
    public boolean compileaddFile(String fileName,String moduleName)
    {
	boolean cmdsuccess = false; 
	String cmd = "'_compileadd'('"+fileName + "'>>" + moduleName+")";
	try {
	    cmdsuccess = engine.deterministicGoal(cmd);
	    //cmdsuccess = engine.command(cmd);
	}
	catch(IPException e) {
	    e.printStackTrace();
	    throw new FlrException("\n*** Java-FLORA-2 interface: Command "+ cmd + " failed\n");
	}
        return cmdsuccess;
    }
    
    

    /* Call the flora_query/4 predicate of FLORA-2
    ** Binds FLORA-2 variables to the returned values
    ** and returns an array of answers. Each answer is an Interprolog
    ** term model from which variable bindings can be obtained.
    ** (See FindAllMatches and ExecuteQuery/1 for how to do this.)
    **
    ** cmd : Flora query to be executed 
    ** vars : Variables in the Flora query that need to be bound
    */
    public Object[] FloraCommand(String cmd,Vector<String> vars)
    {
        StringBuffer sb = new StringBuffer();
	String varsString = "";
	for (int i=0; i<vars.size(); i++) {
	    String floravar = vars.elementAt(i);
	    if (!floravar.startsWith("?"))
		throw new FlrException("\n*** Java-FLORA-2 interface: Illegal variable name "
				       + floravar
				       + ". Variables passed to ExecuteQuery "
				       + "must be FLORA-2 variables and "
				       + "start with a `?'\n");
	    if (i>0) varsString += ",";
	    varsString += "'" + vars.elementAt(i) + "'=__Var" + i;
	}
	varsString = "[" + varsString + "]";

	String listString = "L_rnd=" + varsString + ",";
	String queryString = "S_rnd='" + cmd + "',";
	String floraQueryString =
	    "findall(TM_rnd,(flora_query(S_rnd,L_rnd,_St,_Ex),buildTermModel(L_rnd,TM_rnd)),BL_rnd),ipObjectSpec('ArrayOfObject',BL_rnd,LM)";
   
	sb.append(queryString);
	sb.append(listString);
	sb.append(floraQueryString);
	
	if (debug)
	    System.out.println("FloraCommand: " + sb);

	try {
	    Object solutions[] =
		(Object[])engine.deterministicGoal(sb.toString(), "[LM]")[0];
	    return solutions;
	}
	catch(Exception e) {
	    e.printStackTrace();
	    throw new FlrException("\n*** Java-FLORA-2 interface: Error in query "+cmd+"\n");
	    //return null;
	}
    }


    /* A simpler way to call FLORA commands that are not queries
    **
    ** cmd : Command to be executed
    */
    public boolean simpleFloraCommand(String cmd)
    {
	String queryString = "S_rnd='"+cmd + "',";
	String listString = "L_rnd=[],";

        StringBuffer sb = new StringBuffer();
	sb.append(queryString);
	sb.append(listString);
        sb.append("flora_query(S_rnd,L_rnd,_St,_Ex)");

	if (debug)
	    System.out.println("simpleFloraCommand: " + sb);

	try {
	    return engine.deterministicGoal(sb.toString());
	}
	catch(IPException e) {
	    e.printStackTrace();
	    throw new FlrException("\n*** Java-FLORA-2 interface: Command " + cmd + " failed\n");
	}
    }


    public boolean simplePrologCommand(String cmd)
    {
        try {
	    return engine.deterministicGoal(cmd);
	    //return engine.command(cmd);
	}
        catch(IPException ipe) {
	    ipe.printStackTrace();
	    throw ipe;
	}
    }
    

    /* Query the term model structure 
    **
    ** tm : TermModel to be queried 
    ** name : binding variable name to be queried 
    */
    public static TermModel findValue(TermModel tm, String name)
    {
	if (debug)
	    System.out.println("in findValue, Term model: " + tm);

        for( ; tm.isList(); tm = (TermModel)tm.getChild(1)) {
	    TermModel item = (TermModel)tm.getChild(0);
	    
	    if(name == null
	       || (item.getChild(0).toString().compareTo(name) == 0)) {
		TermModel val = (TermModel)item.getChild(1);
		return val;
	    }

	    if (debug)
		System.out.println("name in findValue: " + name);

	}
	return new TermModel();
    }


    /* Initialise the PrologEngine */
    void initEngine()
    {
	String PrologRootDir = System.getProperty("PROLOGDIR");
	String CmdFloraRootDir = System.getProperty("FLORADIR");
	String PrologBinDir = PrologRootDir + File.separator + "xsb";

        if(PrologRootDir == null || PrologRootDir.trim().length() == 0)
            throw new FlrException("\n*** Java-FLORA-2 interface: Must define PROLOGDIR property\n");
        
        String FloraRootDir;	
	if (CmdFloraRootDir == null || CmdFloraRootDir.trim().length() == 0) {
	    throw new FlrException("\n*** Java-FLORA-2 interface: Must define FLORADIR property\n");
	    }
	else
	    FloraRootDir = CmdFloraRootDir;

	String engineType;

	engineType = System.getProperty("ENGINE"); 
	engineType = engineType.toUpperCase();
	if (engineType.equals("NATIVE")) {
	    try {
		engine = new NativeEngine(systemSpecificFilePath(PrologRootDir));
		isNative = true;
	    }
	    catch(Throwable e) {
	    	e.printStackTrace();
		throw new FlrException("\n*** Java-FLORA-2 interface: InterProlog failed to start its Native Engine\n");
	    }
	} else {
	    try {
		String args = "";
		if (! logger.isInfoEnabled())
		    args += " --quietload";

		engine = new XSBSubprocessEngine(systemSpecificFilePath(PrologBinDir) + args, debug);

		if (logger.isEnabledFor(Level.WARN)) // no logger.isWarnEnabled
		    {
			if (logger.isDebugEnabled())
			    {
				// forward all output
				((XSBSubprocessEngine) engine).addPrologOutputListener(new PrologOutputListener()
				    {
					public void print(String s)
					{
					    System.err.print(s);
					    System.err.flush();
					}
				    });
			    }
			else
			    {
				// forward stderr
				((XSBSubprocessEngine) engine).addPrologStderrListener(new OutputListener()
				    {
					public void analyseBytes(byte[] buffer, int nbytes)
					{
					    System.err.write(buffer, 0, nbytes);
					    System.err.flush();
					}
					
					public void streamEnded()
					{
					}
				    });
			    }
		    }
	    }
	    catch(Exception e2) {
	    	e2.printStackTrace();
		throw new FlrException("\n*** Java-FLORA-2 interface: InterProlog failed start its SubProcess Engine\n");
	    }
	}
	initCommandStrings(FloraRootDir);
	executeInitCommands();
    }


    /* Constructor function */
    public PrologFlora()
    {
        commands = null;
	initEngine();
	return;
    }
    

    /* Shut down the Prolog Engine */
    public void close()
    {
	// don't exit: let the Java program continue after the shutdown
	if(isNative) {
	    // shutdown isn't implemented in Native engine, but this is harmless
	    engine.shutdown();
	} else {
	    engine.shutdown();
	}
    }
    
    public String systemSpecificFilePath(String p){
    	char nonSeparatorChar = 'a';
    	if (File.separator.equals("\\"))
    		nonSeparatorChar = '/';
    	else
    		nonSeparatorChar = '\\';
    			
    	StringBuffer newPath = new
    	StringBuffer(p.length()+10);
    	for(int c=0;c<p.length();c++){
    		char ch = p.charAt(c);
    		if (ch==nonSeparatorChar)
    			newPath.append(File.separatorChar); 
    		//backslashes to forward
    		else newPath.append(ch);
    	}
    	return newPath.toString();
}
    
}
