#! /bin/sh

# File:      jar-flora2java.sh
#
# Author(s): Daniel Winkler
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

. ./build.sh

${JAVA_BIN}/jar -cvf ../flora2java.jar net/sourceforge/flora/javaAPI/src/*.class net/sourceforge/flora/javaAPI/util/*.class
