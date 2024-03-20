cd /sps/nemo/scratch/amendl/AI/falaise_module
source /sps/nemo/scratch/amendl/AI/physical_simulation/load_falaise5.sh
module add cmake
export LIBRARY_PATH=$LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib

cd build

make
# mv libmodule.so libFirstAIModule.so
