
# This assumes that XSB is sitting in ../XSB/ or in ./XSB

echo ""
echo "+++++ Installing the XSB/Flora-2 bundle"
echo ""
sleep 1

currdir=`pwd`

if [ -d ./flora2 -a -d ./XSB ]; then
    flrdir=$currdir/flora2
    xsbdir=$currdir/XSB
else
    echo "This script is to be run in a folder that contains ./XSB & ./flora2"
    exit -1
fi

cd $xsbdir/build

echo "+++++ Configuring XSB"
./configure > $currdir/flora2bundle-install.log 2>&1 || \
    (echo "Configuration of XSB failed: see ./flora2bundle-install.log"; exit -1)
echo "+++++ Compiling XSB"
./makexsb >> $currdir/flora2bundle-install.log 2>&1 || \
    (echo "Compilation of XSB failed: see ./flora2bundle-install.log"; exit -1)

cd $flrdir
echo "+++++ Configuring Flora-2"
./floraconfig $xsbdir/bin/xsb bundle >> $currdir/flora2bundle-install.log 2>&1 || \
    (echo "Configuration of Flora-2 failed: see ./flora2bundle-install.log"; exit -1)

echo "..... The build log is in ./flora2bundle-install.log"
echo ""
echo ""
echo "+++++ All is well: run Flora-2 using the script"
echo "+++++    ./flora2/runflora"
echo ""
