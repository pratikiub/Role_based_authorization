#include<iostream>
#include"resource.h"

std::string Resource::get_name() {
	return name_;
}

std::string Resource::get_desc() {
	return desc_;
}

int Resource::get_id() {
	return id_;
}

void Resource::set_desc(std::string desc) {
	return;
}

void Resource::change_name(std::string name) {
	return;
}

bool Resource::delete_resource(int id) {
	return true;
}

//opeartor overloading
std::ostream& operator<<(std::ostream& out, Resource& rsc) {
	out<<"Resource id is: "<<rsc.get_id()<<std::endl;
	out<<"Resource name: "<<rsc.get_name()<<std::endl;
	out<<"Resource desc:  "<<rsc.get_desc()<<std::endl;
	return out;
}