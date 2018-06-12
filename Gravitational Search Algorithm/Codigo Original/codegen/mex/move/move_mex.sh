MATLAB="/usr/local/MATLAB/R2015a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/eloy/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for move" > move_mex.mki
echo "CC=$CC" >> move_mex.mki
echo "CFLAGS=$CFLAGS" >> move_mex.mki
echo "CLIBS=$CLIBS" >> move_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> move_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> move_mex.mki
echo "CXX=$CXX" >> move_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> move_mex.mki
echo "CXXLIBS=$CXXLIBS" >> move_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> move_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> move_mex.mki
echo "LD=$LD" >> move_mex.mki
echo "LDFLAGS=$LDFLAGS" >> move_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> move_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> move_mex.mki
echo "Arch=$Arch" >> move_mex.mki
echo OMPFLAGS= >> move_mex.mki
echo OMPLINKFLAGS= >> move_mex.mki
echo "EMC_COMPILER=gcc" >> move_mex.mki
echo "EMC_CONFIG=optim" >> move_mex.mki
"/usr/local/MATLAB/R2015a/bin/glnxa64/gmake" -B -f move_mex.mk
