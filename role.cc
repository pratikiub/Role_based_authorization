#include<iostream>
#include"role.h"

std::string Role::get_name() {
	return name_;
}

std::string Role::get_desc() {
	return desc_;
}

int Role::get_id() {
	return id_;
}

void Role::add_resource_to_role(int rsc_id, std::set<Actions> rsc_set ) {
	auto itr = resc_map_.find(rsc_id);
	
	//rsc alreay exists
	if (itr != resc_map_.end()) {
		//std::cout<<"case where resource already exists"<<std::endl;
		auto& action_set = itr->second;
		for(auto action: rsc_set) {
			//std::cout<<"Lol"<<std::endl;
			action_set.insert(action);
		}
	} else {
		//std::cout<<"case where resource does not exists"<<std::endl;
		std::set<Actions> action_set;
		for(auto action:  rsc_set) {
			//std::cout<<"Bye"<<std::endl;
			action_set.insert(action);
		}

		resc_map_.emplace(rsc_id, action_set);
	}
}

void Role::print_role() {
	for (auto itr1: resc_map_) {
		auto action_set = itr1.second;
		for (auto itr2 : action_set) {
			std::cout<<"rsc is: "<<itr1.first << "action is: " <<itr2<<std::endl;
		} 
	}
}

void Role::get_resc_permissions(int rsc_id, std::set<Actions>& action_set) {
	auto itr = resc_map_.find(rsc_id);
	if(itr != resc_map_.end()) {
		action_set = itr->second;
	}

}

std::ostream& operator<<(std::ostream& out, Role& rol) {
	out<<"Role id is: "<<rol.get_id()<<std::endl;
	out<<"Role name: "<<rol.get_name()<<std::endl;
	out<<"Role desc:  "<<rol.get_desc()<<std::endl;
	
	return out;
}


