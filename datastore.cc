#include<iostream>
#include"datastore.h"

Datastore *Datastore::datastore_ = 0;

Datastore::Datastore() {

}

void Datastore::Add_resource_to_role(Role * rol, Resource* rsc, std::set<Actions> action_set) {
	auto rol_itr = role_rsc_map_.find(rol->get_id());
	if (rol_itr != role_rsc_map_.end()) {
		//std::cout<<"got the Resource: "<<std::endl;
		std::map<int, std::set<Actions>>& rsc_map= rol_itr->second;
		std::map<int, std::set<Actions>>::iterator rsc_itr = rsc_map.find(rsc->get_id());
		if(rsc_itr != rsc_map.end()) {
			std::set<Actions>& perm_set = rsc_itr->second;
			for(auto action: action_set) {
				perm_set.insert(action);
			}
		} else {
			std::set<Actions> action_set;
			for(auto action:  action_set) {
				action_set.insert(action);
			}
			rsc_map.emplace(rsc->get_id(), action_set);
		}
	} else {
		//std::cout<<"Construcnt everything: "<<std::endl;
		int rol_id = rol->get_id();
		int rsc_id = rsc->get_id();
		
		std::set<Actions> action_set1;
			for(auto action:  action_set) {
				action_set1.insert(action);
		}

		std::map<int, std::set<Actions>> rsc_map;
		rsc_map.emplace(rsc_id, action_set1);
		role_rsc_map_.emplace(rol_id, rsc_map);
	}

}

void Datastore::print_role_to_rsc_map() {
	std::cout<<"Printing role to rsc map: "<<std::endl;
	for(auto rol_itr: role_rsc_map_) {
		std::cout<<"	Printing mapping for Role: "<<rol_itr.first<<std::endl;
		auto rsc_map = rol_itr.second;
		for(auto rsc_itr: rsc_map) {
			std::cout<<"		Printing mapping for Resource: "<<rsc_itr.first<<std::endl;
			auto action_set = rsc_itr.second;
			for (auto action : action_set) {
				std::cout<<"		Printing action: "<<action<<std::endl;
			}
		}

	}
	return;
}

bool Datastore::Validate_permission_on_rsc(Resource* rsc, User *usr, Actions action) {
	std::vector<Role *> rol_vect = usr->get_roles();

	for (auto itr: rol_vect) {
		auto rol_itr = role_rsc_map_.find(itr->get_id());
		if (rol_itr != role_rsc_map_.end()) {
			auto rsc_map = rol_itr->second;
			auto rsc_itr = rsc_map.find(rsc->get_id());
			if(rsc_itr != rsc_map.end()) {
				std::set<Actions> action_set = rsc_itr->second;
				for(auto act: action_set) {
					if (act == action) {
						return true;
					}
				}
			}
		}
	}
	return false;		
}



/**
void Add_role_to_resource(Resource* rsc, Role* rol, std::set<Actions> action_set) {
	//not implemented
	return;
}
**/