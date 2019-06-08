#include"query.h"


void Validate_access_query::execute() {
	std::vector<Role * > rol_vec = usr_->get_roles();
	//std::cout<<"Size of Roles vec in query exec is: "<<rol_vec.size()<<std::endl;
	for (auto itr: rol_vec) {
		std::set<Actions> action_set;
		itr->get_resc_permissions(rsc_->get_id(), action_set);
		for(auto itr: action_set) {
			//std::cout<<"In execute: " <<"rsc: "<<rsc_->get_id()<<": "<<itr<<std::endl;
			if (itr == action_) {
				std::cout<<"Opearation: "<<action_<<": on resource: "<<rsc_->get_name()<<": by user: "<<usr_->get_name()<<" is allowed"<<std::endl;
				return;
			}
		}
	}
	std::cout<<"Opearation: "<<action_<<": on resource: "<<rsc_->get_name()<<": by user: "<<usr_->get_name()<<" is not allowed"<<std::endl;
	return;
}

void Add_resource_to_role::execute() {
	rol_->add_resource_to_role(rsc_id_, rsc_set_);
	return;
}

void Add_role_to_user::execute() {
	//std::cout<<"calling add role: "<<rol_->get_id() << " on user: "<<usr_->get_id()<<std::endl;
	usr_->add_role(rol_);
	return;
}

