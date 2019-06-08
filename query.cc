#include"query.h"

bool Query::execute() {
	//get roles under the user
	bool ret = false;
	std::vector<Role * > rol_vec = usr_->get_roles();
	std::cout<<"Size of Roles vec in query exec is: "<<rol_vec.size()<<std::endl;
	for (auto itr: rol_vec) {
		std::set<Actions> action_set;
		itr->get_resc_permissions(rsc_->get_id(), action_set);
		for(auto itr: action_set) {
			//std::cout<<"In execute: " <<"rsc: "<<rsc_->get_id()<<": "<<itr<<std::endl;
			if (itr == action_) {
				std::cout<<"Opearation: "<<action_<<": on resource: "<<rsc_->get_name()<<": by user: "<<usr_->get_name()<<" is allowed"<<std::endl;
				return true;
			}
		}
	}
	std::cout<<"Opearation: "<<action_<<": on resource: "<<rsc_->get_name()<<": by user: "<<usr_->get_name()<<" is not allowed"<<std::endl;
	return false;
}
