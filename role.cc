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

std::ostream& operator<<(std::ostream& out, Role& rol) {
	out<<"Role id is: "<<rol.get_id()<<std::endl;
	out<<"Role name: "<<rol.get_name()<<std::endl;
	out<<"Role desc:  "<<rol.get_desc()<<std::endl;
	
	return out;
}


