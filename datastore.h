//Singleton class for datastore
//This class will store data that is mapping between <Role <resource, permissions> and vice versa

#pragma once
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include"role.h"
#include"user.h"
#include"resource.h"

class Datastore {
	private:
		static Datastore* datastore_;
		std::map<int, std::map<int, std::set<Actions>>> role_rsc_map_;
		Datastore();
		//static std::map<int, std::map<int>, std::set<Actions>> rsc_to_role_map_;

	public:
		
		
		static Datastore* get_datastore() {
	
			if (datastore_ == 0) {
				datastore_ = new Datastore;
			}

			return datastore_;
		}

		void Add_resource_to_role(Role * rol, Resource* rsc, std::set<Actions> action_set);
		void print_role_to_rsc_map();
		bool Validate_permission_on_rsc(Resource* rsc, User *usr,Actions action);
	
		//this may require in future when we may want to query on resource rather than role
		//static Add_role_to_resource(Resource* rsc, Role* rol, std::set<Actions> action_set);
		
};