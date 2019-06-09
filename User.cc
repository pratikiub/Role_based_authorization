#include<iostream>
#include"user.h"

std::vector<Role *>& User::get_roles() {
	return role_vect_;
}

std::string User::get_name() {
	return name_;
}

int User::get_id() {
	return id_;
}

void User::add_role(Role *rol) {
	role_vect_.push_back(rol);
}

void User::print_roles() {
	for(auto itr: role_vect_ ) {
		std::cout<<*itr;
	}

}

std::ostream& operator<<(std::ostream& out, User& usr) {
	out<<"User id is: "<<usr.get_id()<<std::endl;
	out<<"User name: "<<usr.get_name()<<std::endl;
	return out;
}