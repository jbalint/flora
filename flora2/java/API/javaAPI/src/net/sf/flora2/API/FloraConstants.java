/* File:      FloraSession.java
**
** Author(s): Michael Kifer
**
** Contact:   flora-users@lists.sourceforge.net
** 
** Copyright (C) The Research Foundation of SUNY, 2006-2013.
** 
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**      http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** 
*/

package net.sf.flora2.API;
import net.sf.flora2.API.util.FlrException;


/**
   Constants used in other places
*/
public class FloraConstants
{
    public final static boolean debug = false;

    public final static String ISA_SYMBOL       = ":";
    public final static String SUBCLASS_SYMBOL  = "::";
	
    public final static String INHERIT_DATA_ARROW    = "*->";
    public final static String NONINHERIT_DATA_ARROW = "->";
	
    public final static String INHERIT_SIGNATURE_ARROW    = "*=>";
    public final static String NONINHERIT_SIGNATURE_ARROW = "=>";

    public final static String PROCEDURAL_METHOD_SYMBOL = "%";
    public final static String INHERITABLE_METHOD_SYMBOL = "*";
    public final static String NONINHERITABLE_METHOD_SYMBOL = "";

    public final static String AT_MODULE_SYMBOL = "@";

    public final static boolean DATA       = true;
    public final static boolean SIGNATURE  = false;

    public final static int VALUE      = 1;
    public final static int BOOLEAN    = 2;
    public final static int PROCEDURAL = 3;

    public final static boolean INHERITABLE = true;
    public final static boolean NONINHERITABLE = false;

    public final static String WRAP_HILOG = "flapply";

	public static final String HEARTBEAT_STAGE_INIT = "init";
	public static final String HEARTBEAT_STAGE_BEGIN = "begin";
	public static final String HEARTBEAT_STAGE_RUN = "run";
	public static final String HEARTBEAT_STAGE_END = "end";

    public static String printableMethodType(int type) {
	if (type == VALUE) return "value";
	else if (type == BOOLEAN) return "boolean";
	else if (type == PROCEDURAL) return "procedural";
	else throw new FlrException("\n*** Java-FLORA-2 interface: Invalid method type, " + type + "\n");
    }

    public static void checkMethodType(int type) {
	if (type != VALUE &&
	    type != BOOLEAN &&
	    type != PROCEDURAL)
	    throw new FlrException("\n*** Java-FLORA-2 interface: Invalid method type, " + type + "\n");
    }

    public static String printableInheritability(boolean inherit) {
	if (inherit) return "inheritable";
	else return "noninheritable";
    }

    public static String printableAtomType(boolean atomtype) {
	if (atomtype==DATA) return "data";
	else return "signature";
    }
}