source /sps/nemo/scratch/amendl/AI/physical_simulation/load_falaise5.sh

export LIBRARY_PATH=$LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib
# flreconstruct -i /sps/nemo/scratch/amendl/AI/physical_simulation/MiModule/testing_products/test-reco.brio -p pipeline.conf
flreconstruct -i /sps/nemo/scratch/amendl/AI/physical_simulation/0nubb_simulation/reconstruction.brio -p pipeline.conf



