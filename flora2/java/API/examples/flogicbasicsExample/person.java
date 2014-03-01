/* File:      javaAPI.flh
**
** Author(s): Michael Kifer
**
** Template included with every high-level Java object in the FLORA-2 Java API.
**
*/


import java.util.*;
import com.declarativa.interprolog.TermModel;
import net.sf.flora2.API.util.*;
import net.sf.flora2.API.*;
public class person extends FloraConstants {

    static TermModel floraClassName = new TermModel("person");
    FloraObject sourceFloraObject;
    String moduleName;

    public person(FloraObject sourceFloraObject,String moduleName) {
	this.sourceFloraObject = sourceFloraObject;
	if (sourceFloraObject == null)
	    throw new FlrException("Cannot create Java class " + floraClassName
				   + ". Null FloraObject passed to "
				   + floraClassName
				   + "(sourceFloraObject,moduleName)");
	    this.moduleName = moduleName;
    }

    public person(String floraOID,String moduleName,FloraSession session) {
	this.sourceFloraObject = new FloraObject(floraOID,session);
	this.moduleName = moduleName;
    }

    public String toString() {
        return sourceFloraObject.toString();
    }


    // Sub/Superclass methods
    public Iterator<FloraObject> getDirectInstances() {
	return sourceFloraObject.getDirectInstances(moduleName);
    }

    public Iterator<FloraObject> getInstances() {
	return sourceFloraObject.getInstances(moduleName);
    }

    public Iterator<FloraObject> getDirectSubClasses() {
	return sourceFloraObject.getDirectSubClasses(moduleName);
    }

    public Iterator<FloraObject> getSubClasses() {
	return sourceFloraObject.getSubClasses(moduleName);
    }

    public Iterator<FloraObject> getDirectSuperClasses() {
	return sourceFloraObject.getDirectSuperClasses(moduleName);
    }

    public Iterator<FloraObject> getSuperClasses() {
	return sourceFloraObject.getSuperClasses(moduleName);
    }


    // Java proxy methods for FLORA-2 methods
    public boolean getBDI_married(Object year)
    {
      Vector<Object> pars = new Vector<Object>();
      pars.add(year);
      return sourceFloraObject.getboolean(moduleName,"married",INHERITABLE,DATA,pars);
    }

    public Iterator<HashMap<String,FloraObject>> getBDIall_married(Object year)
    {
      Vector<Object> pars = new Vector<Object>();
      pars.add(year);
      return sourceFloraObject.getbooleanAll(moduleName,"married",INHERITABLE,DATA,pars);
    }

    public boolean setBDI_married(Object year)
    {
      Vector<Object> pars = new Vector<Object>();
      pars.add(year);
      return sourceFloraObject.setboolean(moduleName,"married",INHERITABLE,DATA,pars);
    }

    public boolean deleteBDI_married(Object year)
    {
      Vector<Object> pars = new Vector<Object>();
      pars.add(year);
      return sourceFloraObject.deleteboolean(moduleName,"married",INHERITABLE,DATA,pars);
    }

