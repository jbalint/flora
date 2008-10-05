# File:      unixVariables.sh
#
# Author(s): Aditi Pandit
#
# Contact:   kifer@cs.stonybrook.edu
#
# Copyright (C) by
#      The Research Foundation of the State University of New York, 1999-2008.
#
# All rights reserved.
#
# For information about licensing terms, please see
# http://silk.projects.semwebcentral.org/flora2-license.html
#
#



# Change PROTEGE_DIR and ENGINE if necessary

PROTEGE_DIR="$HOME/Protege"
# Valid values: Native or Subprocess
# Native engine doesn't work well with Linux
ENGINE=Subprocess
#ENGINE=Native
# Normally doesn't need to be set: autodetected
JAVA_BIN=

# don't touch this
if [ -z "$JAVA_BIN" ]; then
    JAVA_PROG=`which java 2> /dev/null` 

    if [ -z "$JAVA_PROG" -o ! -x "$JAVA_PROG" ]; then
       echo "** Java executable could not be found on your system"
       echo "** Please set the variable JAVA_BIN to the Java binary directory"
    else
	JAVA_BIN=`dirname "$JAVA_PROG"`
	echo "** Using Java executable in $JAVA_BIN"
	$JAVA_BIN/java -version
	echo "** Please make sure that your Java version is 1.5 or newer"
    fi
fi

# Don't change this!
JARS=$PROTEGE_DIR/protege.jar:$PROTEGE_DIR/looks.jar:$PROTEGE_DIR/unicode_panel.jar:$PROTEGE_DIR/driver.jar:$PROTEGE_DIR/driver1.jar:$PROTEGE_DIR/driver2.jar
