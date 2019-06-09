#include<iostream>
#include"query.h"

int main() {

	//Move this calls to qurey interface
	Resource *rsc = new Resource(1, "CPU", "This resource represent the cpu");
	Resource *rsc_mem = new Resource(2, "memory", "This resource represent the main memory");
	Role *role = new Role(1, "Admin", "Admin access");
	Role *role1 = new Role(2, "Deleter", "delete access");
	User *usr = new User(1, "Rajesh");
	User *usr1 = new User(2, "Ankur");

	std::set<Actions> action_set;
	action_set.insert(READ);
	action_set.insert(WRITE);

	std::set<Actions> action_set2;
	action_set2.insert(DELETE);

	std::set<Actions> action_set1;
	action_set1.insert(UPDATE);

	std::vector<Query *> q_vec;

	Query* q1 = new Add_resource_to_role_query(role1, rsc_mem, action_set2);
	Query* q2 = new Add_resource_to_role_query(role, rsc, action_set);
	Query* q3 = new Add_resource_to_role_query(role, rsc, action_set1);
	Query* q4 = new Add_role_to_user_query(usr, role);
	Query* q5 = new Add_role_to_user_query(usr, role1);
	Query* q10 = new Add_role_to_user_query(usr1, role1);
	
	Query *q6 = new Validate_access_query(usr, rsc, UPDATE); //true
	Query *q7 = new Validate_access_query(usr, rsc, DELETE); //false
	Query *q8 = new Validate_access_query(usr, rsc, READ); //true
	Query *q9 = new Validate_access_query(usr, rsc_mem, READ);
	Query *q11 = new Validate_access_query(usr1, rsc_mem, DELETE); //true

	q_vec.push_back(q1);
	q_vec.push_back(q2);
	q_vec.push_back(q3);
	q_vec.push_back(q4);
	q_vec.push_back(q5);
	q_vec.push_back(q6);
	q_vec.push_back(q7);
	q_vec.push_back(q8);
	q_vec.push_back(q9);
	q_vec.push_back(q10);
	q_vec.push_back(q11);

	for (auto q: q_vec) {
		q->execute();
	}

	for(auto q:q_vec) {
		delete q;	
	}

	delete rsc;
	delete rsc_mem;
	delete usr;
	delete usr1;
	delete role;
	delete role1;
	//Datastore::get_datastore()->print_role_to_rsc_map();
	return 0;

}