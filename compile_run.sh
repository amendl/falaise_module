cd /sps/nemo/scratch/amendl/AI/falaise_module
source /sps/nemo/scratch/amendl/AI/physical_simulation/load_falaise4.sh
module add cmake
module add make
rm build
mkdir build
cd build

cmake -DCMAKE_PREFIX_PATH=/where/Falaise/is ../MyModule

make



