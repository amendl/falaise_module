#include <iostream>

#include "falaise/snemo/processing/module.h"
// Data tools
#include <bayeux/mctools/simulated_data.h>
#include "falaise/snemo/datamodels/calibrated_data.h"
#include "falaise/snemo/datamodels/particle_track_data.h"

#include <cppflow/cppflow.h>


class Module {
 public:
  // Default constructor
  Module() = default;
  // User-defined Constructor
  Module(falaise::property_set const& /*ps*/,
           datatools::service_manager& /*services*/) {
					    // Create a tensor from a list, a = [1.0, 2.0, 3.0]
    auto a = cppflow::tensor({1.0, 2.0, 3.0});
    // Create a tensor of shape 3 filled with 1.0, b = [1.0, 1.0, 1.0]
    auto b = cppflow::fill({3}, 1.0);

    std::cout << a + b << std::endl;

  }
  // Process event
  falaise::processing::status process(datatools::things& workI) {
  	if(workI.has("CD")) 
	{
		// Get the CD data
			snemo::datamodel::calibrated_data CD = workI.get<snemo::datamodel::calibrated_data>("CD");
    double X, Y, Z, R;
		double side, row, layer;
		for(int ihit = 0;ihit < CD.tracker_hits().size();ihit++)
		{
			snemo::datamodel::calibrated_tracker_hit tracker_hit = CD.tracker_hits().at(ihit).get();
			
			X = CD.tracker_hits().at(ihit).get().get_x();
			Y = CD.tracker_hits().at(ihit).get().get_y();
			Z = CD.tracker_hits().at(ihit).get().get_z();
			R = CD.tracker_hits().at(ihit).get().get_r();
			side   = CD.tracker_hits().at(ihit).get().get_side();
			row    = CD.tracker_hits().at(ihit).get().get_row();
			layer  = CD.tracker_hits().at(ihit).get().get_layer();
		}
		return falaise::processing::status::PROCESS_OK;

  }
  else {
    
    std::cerr<<"FATAL ERROR from file "<<__FILE__<<" line"<<__LINE__<<": Cannot find CD bank"<<std::endl;
    return falaise::processing::status::PROCESS_FATAL;
  }
    // // Print most basic information
    // std::cout << "AccessThingsModule::process called!" << std::endl;
    // std::cout << "[name]        : " << event.get_name() << std::endl;
    // std::cout << "[description] : " << event.get_description() << std::endl;
    // // Extract list of keys stored by the object
    // std::vector<std::string> keys;
    // event.get_names(keys);
    // // Print each key and its concrete type
    // for (const auto& k : keys) {
    //   std::cout << "- [key, serial_tag] : "
    //       << k
    //       << ", "
    //       << event.get_entry_serial_tag(k)
    //       << std::endl;
    // }
    // // Grab simulated data bank
    // auto& simData = event.get<mctools::simulated_data>("SD");
    // simData.tree_dump();
    // return falaise::processing::status::PROCESS_OK;
  }

};
// Register module with Falaise's plugin system on load
FALAISE_REGISTER_MODULE(Module)

