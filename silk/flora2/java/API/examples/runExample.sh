#! /bin/sh
# File:      runExamples.sh
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


. ../../unixVariables.sh
. ../../flora_settings.sh

. ${1}/floraVariables.sh

${JAVA_BIN}/java -DPROLOGDIR=${PROLOGDIR} -DFLORA_FILE=${FLORA_FILE} -DFLORADIR=${FLORADIR} -Djava.library.path=${PROLOGDIR} -DENGINE=${ENGINE} -classpath ${CLASSPATH}:..:../../interprolog.jar:fooExample:flogicbasicsExample ${1}
