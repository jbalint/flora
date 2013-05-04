/* File:      flogicbasicsExample.java
**
** Author(s): Aditi Pandit, Michael Kifer
**
** Contact:   kifer@cs.stonybrook.edu
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2013.
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




/***********************************************************************
     This file contains examples of the uses of low-level API followed
     by the examples of the uses of high-level API.
***********************************************************************/

import java.util.*;
import org.semwebcentral.flora2.API.*;
import org.semwebcentral.flora2.API.util.*;

public class flogicbasicsExample{
	
    public static void main(String[] args) {
		
    	FloraSession session = new FloraSession();
	System.out.println("FLORA-2 session started");	
		
	String fileName = System.getProperty("FLORA_FILE");
	if(fileName == null || fileName.trim().length() == 0) {
	    System.out.println("Invalid path to example file!");
	    System.exit(0);
	}
	if (session.loadFile(fileName,"example"))
	    System.out.println("Example loaded successfully!");
	else
	    System.out.println("Error loading the example file!");

	
	/* Examples of uses of the low-level Java-FLORA-2 API */
	
	// Querying persons
	String command = "?X:person@example.";
	System.out.println("Query:"+command);
	Iterator personObjs = session.ExecuteQuery(command);
	/* Printing out persons  */
    	while (personObjs.hasNext()) {
	    Object personObj = personObjs.next();
	    System.out.println("Person Id: "+personObj);
	}

		
	command = "person[instances -> ?X]@example.";
	System.out.println("Query:"+command);
	personObjs = session.ExecuteQuery(command);
		
	/* Printing out persons  */
    	while (personObjs.hasNext()) {
	    Object personObj = personObjs.next();
	    System.out.println("Person Id: "+personObj);
	}

	/* Example of query with two variables */
	Vector<String> vars = new Vector<String>();
	vars.add("?X");
	vars.add("?Y");
		
	Iterator allmatches =
	    session.ExecuteQuery("?X[believes_in -> ?Y]@example.",vars);
	System.out.println("Query:?X[believes_in -> ?Y]@example.");

	HashMap firstmatch;
	while (allmatches.hasNext()) {	
	    firstmatch = (HashMap)allmatches.next();
	    FloraObject Xobj = (FloraObject)firstmatch.get("?X");
	    FloraObject Yobj = (FloraObject)firstmatch.get("?Y");	
	    System.out.println(Xobj+" believes in: "+Yobj);	
	}

	FloraObject personObj = new FloraObject("person",session);
	Iterator methIter = personObj.getMethods("example");
	while (methIter.hasNext()) {
	    System.out.println(((FloraMethod)methIter.next()).methodDetails());
	}

	// instances of the person class
	Iterator instanceIter = personObj.getInstances("example");
	System.out.println("Person instances:");
	while (instanceIter.hasNext())
	    System.out.println("    " + (FloraObject)instanceIter.next());


	instanceIter = personObj.getDirectInstances("example");
	System.out.println("Person direct instances:");
	while (instanceIter.hasNext())
	    System.out.println("    " + (FloraObject)instanceIter.next());

	Iterator subIter = personObj.getSubClasses("example");
	System.out.println("Person subclasses:");
	while (subIter.hasNext())
	    System.out.println("    " + (FloraObject)subIter.next());

	subIter = personObj.getDirectSubClasses("example");
	System.out.println("Person direct subclasses:");
	while (subIter.hasNext())
	    System.out.println("    " + (FloraObject)subIter.next());

	Iterator supIter = personObj.getSuperClasses("example");
	System.out.println("Person superclasses:");
	while (supIter.hasNext())
	    System.out.println("    " + (FloraObject)supIter.next());

	supIter = personObj.getDirectSuperClasses("example");
	System.out.println("Person direct superclasses:");
	while (supIter.hasNext())
	    System.out.println("    " + (FloraObject)supIter.next());

	/*****************************************************************
	 ******** Examples of uses of the high-level Java-FLORA-2 API
	 *****************************************************************/

	/* Printing out people's names and information about their kids
	   using the high-level API. Note that the high-level person-object 
	   is obtained here out of the low-level FloraObject personObj
	*/
	person currPerson = null;
    	while (personObjs.hasNext()) {
	    personObj = (FloraObject)(personObjs.next());
	    System.out.println("Person name:"+personObj);

	    currPerson =new person(personObj,"example");
	    Iterator kidsItr = currPerson.getVDN_kids();

	    while(kidsItr.hasNext()) {
		FloraObject kidObj = (FloraObject)(kidsItr.next());
		System.out.println("Person Name: " + personObj
				   + " has kid: " + kidObj);
		    
		person kidPerson = null;
		kidPerson = new person(kidObj,"example");
		
		Iterator hobbiesItr = kidPerson.getVDN_hobbies();

		while(hobbiesItr.hasNext()) {
		    FloraObject hobbyObj = null;
		    hobbyObj = (FloraObject)(hobbiesItr.next());
		    System.out.println("Kid:"+kidObj
				       + " has hobby: " + hobbyObj);
		}
	    }
	}


	FloraObject age;
	currPerson = new person("father(mary)", "example", session);
	Iterator maryfatherItr = currPerson.getVDN_age();
	age = (FloraObject)maryfatherItr.next();
	System.out.println("Mary's father is " + age + " years old");

	currPerson = new person("mary", "example", session);
	Iterator maryItr = currPerson.getVDN_age();
	age = (FloraObject)maryItr.next();
	System.out.println("Mary is " + age + " years old");

	// person instances using high-level interface
	person personClass = new person("person", "example", session);
	instanceIter = personClass.getInstances();
	System.out.println("Person instances using high-level API:");
	while (instanceIter.hasNext())
	    System.out.println("    " + (FloraObject)instanceIter.next());


	Iterator subclassIter = personClass.getSubClasses();
	System.out.println("Person subclasses using high-level API:");
	while (subclassIter.hasNext())
	    System.out.println("    " + (FloraObject)subclassIter.next());


	// Close session and good bye
	session.close();
	System.exit(0);
    }
}
