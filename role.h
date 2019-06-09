#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

enum Actions
{
	READ,
	WRITE,
	UPDATE,
	DELETE
};

class Role {

	public:
		Role(int id, std::string name, std::string desc):
			id_(id),
			name_(name),
			desc_(desc)
		{

		}

		std::string get_name();
		
		int get_id();

		std::string get_desc();

			void print_role();

		friend std::ostream & operator << (std::ostream & out, Role& rsc);

		~Role() {

		}

	private:
		int id_;
		std::string name_;
		std::string desc_;
		//map stores roles and resource mappings
		std::map<int, std::set<Actions> > resc_map_;

};
