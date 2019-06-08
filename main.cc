#include<iostream>
#include"query.h"

int main() {

	Resource *rsc = new Resource(1, "CPU", "This resource represent the cpu");
	Role *role = new Role(1, "Admin", "Admin access");
	Role *role1 = new Role(2, "DELETE_Role", "delete access");
	User *usr = new User(1, "Rajesh");
	
	std::set<Actions> action_set;
	action_set.insert(READ);
	action_set.insert(WRITE);

	std::set<Actions> action_set2;
	action_set2.insert(DELETE);

	std::set<Actions> action_set1;
	action_set1.insert(UPDATE);

	std::vector<Query *> q_vec;

	//Query* q1 = new Add_resource_to_role(role1, 1, action_set2);
	Query* q2 = new Add_resource_to_role(role, 1, action_set);
	Query* q3 = new Add_resource_to_role(role, 1, action_set1);
	Query* q4 = new Add_role_to_user(usr, role);
	Query* q5 = new Add_role_to_user(usr, role1);
	
	Query *q6 = new Validate_access_query(usr, rsc, UPDATE);
	Query *q7 = new Validate_access_query(usr, rsc, DELETE);
	Query *q8 = new Validate_access_query(usr, rsc, READ);

	//q_vec.push_back(q1);
	q_vec.push_back(q2);
	q_vec.push_back(q3);
	q_vec.push_back(q4);
	q_vec.push_back(q5);
	q_vec.push_back(q6);
	q_vec.push_back(q7);
	q_vec.push_back(q8);

	for(auto q: q_vec) {
		q->execute();
	}

	return 0;

}