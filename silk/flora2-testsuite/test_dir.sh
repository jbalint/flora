#! /bin/sh

# Test files in one directory
#============================================================================
dir=`pwd`
dir=`basename $dir`
echo "-------------------------------------------------------"
echo "--- Running $dir/test_dir.sh                           "
echo "-------------------------------------------------------"

basedir=$1
FLORA=$2
options=$3

file_list=*.flr

# abp.flr does not work. Perhaps the program is wrong.
# trailer.flr is disabled: since there are no "SINGLE-valued" methods now,
#                          the related trailer is not used.
# btupdates.flr is loaded using btupdates_load.flr
# tabledupdates.flr is loaded using tabledupdates_load.flr
# add1.flr and add2.flr are loaded or added using add_load.flr
# ruleupdates.flr is loaded using ruleupdates_load.flr
# compile_control.flr is loaded using compiletst.flr
# depcheck_control.flr is loaded by depchecktest.flr
# error_invalidsym.flr, error_dynmod.flr, error_nonvar*.flr 
#                         are used in export_compile_test.flr
# encap_mod*.flr are used in export_test.flr and importmodule.flr
# encap_syntax_check.flr is used in export_compile_test.flr
#
exclude_list="abp.flr btupdates.flr compile_control.flr tabledupdates.flr \
    	      basetype_moo.flr basetype_foo.flr \
              add1.flr add2.flr \
              trailer.flr \
              sensortest_declarations.flr sensortest_usedecl.flr \
              ruleupdates.flr reif_foo.flr \
              callReified_foo.flr callReified_foo2.flr \
    	      module_foo.flr \
    	      depcheck_control.flr \
              encap_mod1.flr encap_mod2.flr encap_syntax_check.flr \
              error_invalidsym.flr error_dynmod.flr \
              error_nonvar.flr error_nonvar2.flr error_nonvar3.flr \
	      test_func_modulebar.flr test_func_facts_aux.flr \
	      test_builtin_err.flr \
    	      test_delays_errors1.flr test_delays_errors2.flr"


# Test if element is a member of exclude list
# $1 - element
# $2 - exclude list
member ()
{
    for elt in $2 ; do
	if test "$1" = "$elt" ; then
	    return 0
	fi
    done
    return 1
}

OBJEXT=.xwam

# Remove the Prolog and object files to make sure we are using the 
# latest compiled sources
rm -f *.P *${OBJEXT} *.fld *.fdb *.con *.flt *.fls*
rm -f programs/*.P programs/*${OBJEXT} programs/*.fld programs/*.fdb programs/*.fls* programs/*.flt
rm -f gpmanager/*.P gpmanager/*${OBJEXT} gpmanager/*.fld gpmanager/*.fdb
rm -f $basedir/datafiles/*.P    $basedir/datafiles/*${OBJEXT}  $basedir/datafiles/*.fld  $basedir/datafiles/*.fdb $basedir/datafiles/*.fls* $basedir/datafiles/*.flt
rm -f $basedir/exporttest/*.P    $basedir/exporttest/*${OBJEXT}  $basedir/exporttest/*.fld  $basedir/exporttest/*.fdb $basedir/exporttest/*.fls* $basedir/exporttest/*.flt
rm -f $basedir/general_tests/prolog/*${OBJEXT}
rm -f $basedir/functions/*${OBJEXT} $basedir/functions/*.P
rm -f $basedir/functions/equality/*${OBJEXT} $basedir/functions/equality/*.P $basedir/functions/equality/*.fls* $basedir/functions/equality/*.flt $basedir/functions/equality/*.fld $basedir/functions/equality/*.fdb
rm -f $basedir/functions/errors_warnings_tests/*${OBJEXT} $basedir/functions/errors_warnings_tests/*.P $basedir/functions/errors_warnings_tests/*.flt $basedir/functions/errors_warnings_tests/*.fls* $basedir/functions/errors_warnings_tests/*.fdb $basedir/functions/errors_warnings_tests/*.fld
rm -f $basedir/symbols/*${OBJEXT} $basedir/symbols/*.P
rm -f $basedir/symbols/tests/*${OBJEXT} $basedir/symbols/tests/*.P $basedir/symbols/tests/*.fdb $basedir/symbols/tests/*.fls* $basedir/symbols/tests/*.flt $basedir/symbols/tests/*.fld
rm -f $basedir/symbols/test_load/*${OBJEXT} $basedir/symbols/test_load/*.P $basedir/symbols/test_load/*.fdb $basedir/symbols/test_load/*.fld $basedir/symbols/test_load/*.fls* $basedir/symbols/test_load/*.flt


# run the tests
for file in $file_list ; do
    if member $file "$exclude_list"; then
	continue
    fi
    prog=`basename $file .flr`
    touch $file
    $basedir/test_one_file.sh "$FLORA" "$prog" 
done

