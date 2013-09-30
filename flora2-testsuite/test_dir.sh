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
    	      terminyzer0.flr \
    	      terminyzer0_log.flr \
    	      terminyzer1.flr \
    	      terminyzer2.flr \
              trailer.flr \
              sensortest_declarations.flr sensortest_usedecl.flr \
              ruleupdates.flr reif_foo.flr \
              callReified_foo.flr callReified_foo2.flr \
    	      module_foo.flr \
    	      depcheck_control.flr \
              descriptors_moo.flr \
              encap_mod1.flr encap_mod2.flr encap_syntax_check.flr \
              error_invalidsym.flr error_dynmod.flr \
              error_nonvar.flr error_nonvar2.flr error_nonvar3.flr \
              symbol_context_syntax_nowarnings.flr \
              symbol_context_syntax_warnings.flr \
              atco_specific_aux.flr \
	      test_func_modulebar.flr test_func_facts_aux.flr \
	      test_builtin_err.flr \
    	      test_delays_errors1.flr test_delays_errors2.flr \
              test_delays_errors3.flr \
    	      justification_test_fl.flr \
    	      justification_test_prog.flr \
    	      justification_test_prog_aux.flr \
    	      justification_test_just.flr \
              justifier_ex.flr \
              atco_specific2.flr \
              atco_specific2_aux.flr"


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

# Remove Prolog, object, and other auxiliary files to make sure we are using
# the latest compiled sources
rm -f $basedir/apptests/.flora_aux_files/*
rm -f $basedir/apptests/gpmanager/.flora_aux_files/*
rm -f $basedir/apptests/programs/.flora_aux_files/*
rm -f $basedir/datafiles/.flora_aux_files/*
rm -f $basedir/defeasible/*/.flora_aux_files/*
rm -f $basedir/delaytests/.flora_aux_files/*
rm -f $basedir/exporttest/.flora_aux_files/*
rm -f $basedir/functions/.flora_aux_files/*
rm -f $basedir/functions/*/.flora_aux_files/*
rm -f $basedir/general_tests/.flora_aux_files/*
rm -f $basedir/symbols/.flora_aux_files/*
rm -f $basedir/symbols/*/.flora_aux_files/*
rm -f $basedir/general_tests/prolog/*${OBJEXT}


# run the tests
for file in $file_list ; do
    if member $file "$exclude_list"; then
	continue
    fi
    prog=`basename $file .flr`
    touch $file
    $basedir/test_one_file.sh "$FLORA" "$prog" 
done

