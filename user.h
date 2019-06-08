#pragma once
#include<iostream>
#include<vector>
#include"role.h"

class User {

	public:
		User(int id, std::string name):
			id_(id),
			name_(name)
		{

		}

		std::string get_name();
		
		int get_id();

		std::vector<Role *>& get_roles();
		
		void print_roles();

		void add_role(Role *rol);  

		friend std::ostream & operator << (std::ostream & out, User& usr);

		~User() {}

	private:
		int id_;
		std::string name_;
		std::vector<Role *> role_vect_;

};