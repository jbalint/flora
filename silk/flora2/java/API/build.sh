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

SILKLIB=../../../lib
LOG4J=${SILKLIB}/jena/*.jar
INTERPROLOG=${SILKLIB}/interprolog.jar

${JAVA_BIN}/javac -source 1.6 -deprecation -Xlint:unchecked -Xlint -classpath ${LOG4J}:..:${INTERPROLOG} javaAPI/util/org/semwebcentral/flora2/API/util/*.java javaAPI/src/org/semwebcentral/flora2/API/*.java  

