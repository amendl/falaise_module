cd /sps/nemo/scratch/amendl/AI/falaise_module
source /sps/nemo/scratch/amendl/AI/physical_simulation/load_falaise4.sh
module add cmake
rm -rf build
mkdir build
export LIBRARY_PATH=$LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib

cd build
cmake ../
make
mv libmodule.so libModule.so
