#!/bin/sh
appname=`basename $0 | sed s,\.sh$,,`

dirname=`dirname $0`
tmp="${dirname#?}"

if [ "${dirname%$tmp}" != "/" ]; then
  dirname=$PWD/$dirname
fi
LD_LIBRARY_PATH=$dirname:$ORACLE_HOME:$ORACLE_HOME/lib
QTDIR=$dirname
export LD_LIBRARY_PATH
export QTDIR
cd $dirname
$dirname/$appname $*
