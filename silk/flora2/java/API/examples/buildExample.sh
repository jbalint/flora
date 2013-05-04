#! /bin/sh
# File:      buildExample.sh
#
# Author(s): Aditi Pandit
#
# Contact:   kifer@cs.stonybrook.edu
#
# Copyright (C) by
#      The Research Foundation of the State University of New York, 1999-2013.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
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
${JAVA_BIN}/javac -deprecation -Xlint:unchecked -Xlint -classpath ../javaAPI/src:../javaAPI/util:../../interprolog.jar ${1}/*.java 
