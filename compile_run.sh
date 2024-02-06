cd /sps/nemo/scratch/amendl/AI/falaise_module
source /sps/nemo/scratch/amendl/AI/physical_simulation/load_falaise4.sh
module add cmake
rm -rf build
mkdir build
cd build
cmake ../
make
mv libmodule.so libModule.so
