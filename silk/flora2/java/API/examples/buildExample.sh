#! /bin/sh
# File:      buildExample.sh
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



if test ! -d "${1}" -o "$1" = "" ; then
    echo
    echo "**** Argument 1 must be a directory containing the example to build"
    echo
    exit 1
fi
. ../../unixVariables.sh
. ../../flora_settings.sh

. ${1}/floraVariables.sh

touch ${1}/*.flr

../../../runflora -e "_load('${FLORA_FILE}'>>example),_load(javaAPI),%write(${FLORA_CLASS},example,'${JAVA_FILE}'),_halt." 
 
# add -Xlint after convertion to Java 1.5
${JAVA_BIN}/javac -deprecation -Xlint:unchecked -Xlint -classpath ..:../../interprolog.jar ${1}/*.java 
