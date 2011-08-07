#! /bin/sh

# test single file

# $1 is expected to have the FLORA-2 invocation script
FLORA=$1
FILE=$2

DIR=`pwd`
BASEDIR=`basename $DIR`

echo "--------------------------------------------------------------------"
echo "Testing $BASEDIR/$FILE"

$FLORA << EOF
[$FILE].
_nochatter.
%test.
_end.
EOF

# print out differences.
if test -f ${FILE}_new; then
	rm -f ${FILE}_new
fi
    
cp   temp ${FILE}_new
sort temp > temp_new
sort ${FILE}_old > temp_old

#-----------------------
# print out differences.
#-----------------------
status=0
# must use diff -w to ignore ^M^M under windows
diff -w temp_old temp_new || status=1
if test "$status" = 0 ; then 
	echo "$BASEDIR/$FILE tested"
	rm -f ${FILE}_new
else
	echo "$BASEDIR/$FILE differ!!!"
	diff -w ${FILE}_new ${FILE}_old
fi

rm -f temp temp_old temp_new
