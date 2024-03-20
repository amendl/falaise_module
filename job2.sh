#!/bin/bash

#SBATCH --partition=htc                  # Partition choice (most generally we work with htc, but for quick debugging you can use flash
#SBATCH --output=stdout.log
#SBATCH -e stdout.log
										 #					 #SBATCH --partition=htc. This avoids waiting times, but is limited to 1hr)
#SBATCH --licenses=sps                   # When working on sps, must declare license!!

source /sps/nemo/scratch/amendl/AI/physical_simulation/load_falaise5.sh

export LIBRARY_PATH=$LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/lib
flreconstruct -i /sps/nemo/scratch/amendl/AI/physical_simulation/2nubb_simulation/reconstruction.brio -p energy_histogram_module.conf
