#! /bin/sh

# File:      build.sh
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

. ../unixVariables.sh
. ../flora_settings.sh

rm -f javaAPI/util/org/semwebcentral/flora2/API/util/*.class
rm -f javaAPI/src/org/semwebcentral/flora2/API/*.class
rm -f javaAPI/classes/org/semwebcentral/flora2/API/util/*.class
rm -f javaAPI/classes/org/semwebcentral/flora2/API/*.class

SILKLIB=../../../lib
LOG4J=${SILKLIB}/jena/log4j-1.2.12.jar
INTERPROLOG=${SILKLIB}/interprolog.jar

${JAVA_BIN}/javac -source 1.6 -deprecation -Xlint:unchecked -Xlint -classpath ${LOG4J}:..:${INTERPROLOG} javaAPI/util/org/semwebcentral/flora2/API/util/*.java javaAPI/src/org/semwebcentral/flora2/API/*.java  

