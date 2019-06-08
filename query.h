/** This implements query interface. All changes are done via this interface like creating user,
 *  creaitng role, adding resource to role and adding role to user will get handled by this interface
**/

#pragma once
#include<iostream>
#include"user.h"
#include"resource.h"
#include"role.h"

class Query {
	public:
		virtual void execute() = 0;
};

class Validate_access_query : public Query {
	public:
		Validate_access_query(User * usr, Resource* rsc, Actions action) :
			usr_(usr),
			rsc_(rsc),
			action_(action)
		{

	 	}

	 	void execute();

	private:
		Resource*  rsc_;
		User*  usr_;
		Actions action_;

};

// This query adds resource along with permissions to

class Add_resource_to_role : public Query {
	public:
		Add_resource_to_role(Role * rol, int rsc_id, std::set<Actions> rsc_set) :
			rol_(rol),
			rsc_set_(rsc_set),
			rsc_id_(rsc_id)
		{

		}

		void execute();

	private:
		Role* rol_;
		std::set<Actions> rsc_set_;
		int rsc_id_;
};

//This query adds roles to particular user

class Add_role_to_user : public Query {
	public:
		Add_role_to_user(User * usr, Role * rol):
			usr_(usr),
			rol_(rol)
		{

		}
		void execute();

	private:
		Role* rol_;
		User* usr_;
};	