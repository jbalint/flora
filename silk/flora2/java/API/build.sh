#! /bin/sh

# File:      build.sh
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

. ../unixVariables.sh
. ../flora_settings.sh

rm -f javaAPI/util/*.class
rm -f javaAPI/src/*.class

${JAVA_BIN}/javac -deprecation -Xlint:unchecked -Xlint -classpath ..:../interprolog.jar javaAPI/util/*.java javaAPI/src/*.java  

