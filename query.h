/** This implements query interface. All changes are done via this interface like creating user,
 *  creaitng role, adding resource to role and adding role to user will get handled by this interface
**/

#pragma once
#include<iostream>
#include"user.h"
#include"resource.h"
#include"role.h"
#include"datastore.h"

class Query {
	public:
		virtual void execute() = 0;
		virtual ~Query() {

		}
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

	 	~Validate_access_query() {

	 	}
	private:
		Resource*  rsc_;
		User*  usr_;
		Actions action_;
};

// This query adds resource along with permissions to
class Add_resource_to_role_query : public Query {
	public:
		Add_resource_to_role_query(Role * rol, Resource* rsc, std::set<Actions> rsc_set) :
			rol_(rol),
			rsc_set_(rsc_set),
			rsc_(rsc)
		{

		}

		void execute();
		~Add_resource_to_role_query() {

		}

	private:
		Role* rol_;
		std::set<Actions> rsc_set_;
		Resource* rsc_;
};

//This query adds roles to particular user

class Add_role_to_user_query : public Query {
	public:

		Add_role_to_user_query(User * usr, Role * rol):
			usr_(usr),
			rol_(rol)
		{

		}
		void execute();
		~Add_role_to_user_query() {

		}	
	private:
		Role* rol_;
		User* usr_;
};	