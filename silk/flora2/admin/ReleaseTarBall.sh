#!/bin/sh 

    # Create a FLORA-2 tarball 

    # RUN this in the ./admin/ directory!

files="./flora2/INSTALLATION \
        ./flora2/Makefile ./flora2/NMakefile.mak \
    	./flora2/makeflora ./flora2/makeflora.bat \
        ./flora2/*.sh ./flora2/*.P ./flora2/*.H ./flora2/*.flh\
    	./flora2/closure/Makefile ./flora2/closure/NMakefile.mak \
    	./flora2/closure/*.fli \
    	./flora2/closure/*.inc \
    	./flora2/datatypes/*.P ./flora2/datatypes/*.sh \
    	./flora2/datatypes/Makefile ./flora2/datatypes/NMakefile.mak \
    	./flora2/debugger/*.in ./flora2/debugger/*.P \
    	./flora2/debugger/Makefile ./flora2/debugger/NMakefile.mak \
    	./flora2/demos/*.flr ./flora2/demos/*.sh \
    	./flora2/demos/sgml/*.flr ./flora2/demos/sgml/expectedoutput \
    	./flora2/demos/xpath/*.flr ./flora2/demos/xpath/expectedoutput \
    	./flora2/demos/Makefile ./flora2/demos/NMakefile.mak \
    	./flora2/docs/*.pdf \
    	./flora2/docs/Makefile ./flora2/docs/NMakefile.mak \
    	./flora2/emacs/flora.el \
    	./flora2/emacs/README \
    	./flora2/emacs/Makefile \
    	./flora2/emacs/NMakefile.mak \
    	./flora2/flrincludes/*.flh \
    	./flora2/genincludes/Makefile ./flora2/genincludes/NMakefile.mak \
    	./flora2/genincludes/*.fli \
    	./flora2/genincludes/*.inc \
    	./flora2/headerinc/*.flh \
    	./flora2/includes/*.flh \
    	./flora2/includes/Makefile ./flora2/includes/NMakefile.mak \
    	./flora2/lib/*.flr ./flora2/lib/Makefile ./flora2/lib/NMakefile.mak \
	./flora2/lib/include/*flh \
    	./flora2/libinc/*.flh \
    	./flora2/p2h/prolog2hilog.* ./flora2/p2h/*.P \
    	./flora2/p2h/flora_ground.* \
        ./flora2/p2h/Makefile \
	./flora2/p2h/NMakefile.mak ./flora2/p2h/NMakefile64.mak \
        ./flora2/p2h/windows/*.dll ./flora2/p2h/windows/*.exp \
    	./flora2/p2h/windows/*.lib \
        ./flora2/p2h/windows64/*.dll ./flora2/p2h/windows64/*.exp \
    	./flora2/p2h/windows64/*.lib \
    	./flora2/pkgs/Makefile ./flora2/pkgs/NMakefile.mak \
        ./flora2/pkgs/*.flr ./flora2/pkgs/prolog/*.P \
	./flora2/pkgs/include/*.flh \
    	./flora2/syslib/*.P ./flora2/syslib/*.H ./flora2/syslib/*.sh \
    	./flora2/syslib/Makefile ./flora2/syslib/NMakefile.mak \
    	./flora2/syslibinc/*.flh  \
	./flora2/Misc/*.pl ./flora2/Misc/README \
    	./flora2/platforms/unix \
    	./flora2/platforms/windows \
    	./flora2/platforms/cygwin \
        ./flora2/java "

curdir=`pwd`
curdir=`basename $curdir`
if test ! $curdir = admin; then
    echo "+++ This script must be run out of flora2/admin/ directory"
    exit 1
fi

cd ../..

EXCLUDEFILE=flora2/admin/.excludedFiles

cat > $EXCLUDEFILE <<EOF
CVS
*.conf
*.log
.#*
.cvsignore
.svn
.excludedFiles
*.zip
*.tar
*.bz2
*.gz
*.Z
*~
*.bak
*-sv
*-old
platforms/unix/*
platforms/windows/*
platforms/cygwin/*
EOF

tar cvf flora2/flora2.tar --exclude-from=$EXCLUDEFILE $files

gzip -f flora2/flora2.tar
