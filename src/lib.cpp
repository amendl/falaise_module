#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// #include <optional>

#include "falaise/snemo/processing/module.h"
// Data tools
#include <bayeux/mctools/simulated_data.h>
#include "falaise/snemo/datamodels/calibrated_data.h"
#include "falaise/snemo/datamodels/particle_track_data.h"


#include <bayeux/dpp/chain_module.h> // DPP chain module import

#include <cppflow/cppflow.h>


class FirstAIModule : public dpp::chain_module {

public:
	void 	initialize (const datatools::properties & module_properties, datatools::service_manager &, dpp::module_handle_dict_type &) override;
	dpp::chain_module::process_status process (datatools::things & event) override;
  void reset() override;
	
  FirstAIModule();
	~FirstAIModule();
private:
	float classification[4] = {0.,0.,0.,0.};

	std::string model_path;
  cppflow::model* model;




	DPP_MODULE_REGISTRATION_INTERFACE(FirstAIModule)


};



DPP_MODULE_REGISTRATION_IMPLEMENT(FirstAIModule, "FirstAIModule")
// Register module with Falaise's plugin system on load
// FALAISE_REGISTER_MODULE(Module)
void FirstAIModule::initialize(const datatools::properties & module_properties, datatools::service_manager &, dpp::module_handle_dict_type &)
{
	if(module_properties.has_key("model_path")) 
	  this->model_path=module_properties.fetch_path("model_path");
	else
		throw std::runtime_error(std::string("cannot get model path"));
	this->model = new cppflow::model(static_cast<std::string>(model_path));

	this->_set_initialized(true);
}
dpp::chain_module::process_status FirstAIModule::process (datatools::things & event) 
{
	return falaise::processing::status::PROCESS_OK;
}
void FirstAIModule::reset() 
{	
	this->_set_initialized(false);
	// Save all data
	std::ofstream myfile;
	myfile.open("results.txt",std::ios::out);
	myfile<<classification[0]<<","<<classification[1]<<","<<classification[2]<<","<<classification[3]<<","<<std::endl;
 myfile.close();

}


FirstAIModule::FirstAIModule() : dpp::chain_module() { }
FirstAIModule::~FirstAIModule()
{
	if (this->is_initialized()) {
		this->reset();
	}
}



  // Module(falaise::property_set const& ps, datatools::service_manager& services) {
    
		// this->model_path = ps.get<falaise::path>("model.path");

		// this->model = new cppflow::model(static_cast<std::string>(model_path));
		// std::cout<<"Loaded"<<std::endl;
  // }
	
 //  falaise::processing::status process(datatools::things& workI) {
 //  	if(workI.has("CD")) 
	// {
	// std::cout<<"processing"<<std::endl;
	// 	// Get the CD data
	// 		snemo::datamodel::calibrated_data CD = workI.get<snemo::datamodel::calibrated_data>("CD");
 //    double X, Y, Z, R;
	// 	double side, row, layer;
	// 	for(int ihit = 0;ihit < CD.tracker_hits().size();ihit++)
	// 	{
	// 		snemo::datamodel::calibrated_tracker_hit tracker_hit = CD.tracker_hits().at(ihit).get();
			
	// 		X = CD.tracker_hits().at(ihit).get().get_x();
	// 		Y = CD.tracker_hits().at(ihit).get().get_y();
	// 		Z = CD.tracker_hits().at(ihit).get().get_z();
	// 		R = CD.tracker_hits().at(ihit).get().get_r();
	// 		side   = CD.tracker_hits().at(ihit).get().get_side();
	// 		row    = CD.tracker_hits().at(ihit).get().get_row();
	// 		layer  = CD.tracker_hits().at(ihit).get().get_layer();

	// 		std::cout<<layer<<" "<<row<<std::endl;
	// 	}
	// 	return falaise::processing::status::PROCESS_OK;

 //  }
 //  else {
    
 //    std::cerr<<"FATAL ERROR from file "<<__FILE__<<" line"<<__LINE__<<": Cannot find CD bank"<<std::endl;
 //    return falaise::processing::status::PROCESS_FATAL;
 //  }
	// auto event = &workI;
 //    // Print most basic information
 //    std::cout << "AccessThingsModule::process called!" << std::endl;
 //    std::cout << "[name]        : " << workI.get_name() << std::endl;
 //    std::cout << "[description] : " << workI.get_description() << std::endl;
 //    // Extract list of keys stored by the object
 //    std::vector<std::string> keys;
 //    workI.get_names(keys);
 //    // Print each key and its concrete type
 //    for (const auto& k : keys) {
 //      std::cout << "- [key, serial_tag] : "
 //          << k
 //          << ", "
 //          << event.get_entry_serial_tag(k)
 //          << std::endl;
 //    }
 //    // Grab simulated data bank
 //    auto& simData = event.get<mctools::simulated_data>("SD");
 //    simData.tree_dump();
 //    return falaise::processing::status::PROCESS_OK;
 //  }
// private:

