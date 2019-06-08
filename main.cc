#include<iostream>
#include"query.h"

int main() {

	Resource *rsc = new Resource(1, "CPU", "This resource represent the cpu");
	//std::cout<<*rsc;
	Role *role = new Role(1, "Admin", "Admin access");
	Role *role1 = new Role(2, "DELETE_Role", "delete access");
	
	std::set<Actions> action_set;
	action_set.insert(READ);
	action_set.insert(WRITE);

	std::set<Actions> action_set2;
	action_set2.insert(DELETE);
	role1->add_resource_to_role(1, action_set2);

	role->add_resource_to_role(1, action_set);

	std::set<Actions> action_set1;

	action_set1.insert(UPDATE);

	role->add_resource_to_role(1, action_set1);

	User *usr = new User(1, "Rajesh");

	//3
	usr->add_role(role);
	usr->add_role(role1);

	std::vector<Query *> q_vec;

	
	Query *q1 = new Query(usr, rsc, UPDATE);
	Query *q2 = new Query(usr, rsc, DELETE);
	Query *q3 = new Query(usr, rsc, READ);

	q_vec.push_back(q1);
	q_vec.push_back(q2);
	q_vec.push_back(q3);

	for(auto q: q_vec) {
		q->execute();
	}

	return 0;

}