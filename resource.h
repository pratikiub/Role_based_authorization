#pragma once
#include<iostream>
#include<string>


class Resource {
	
	public:
		Resource(int id, std::string name, std::string desc):
			id_(id),
			name_(name),
			desc_(desc) 
		{

		}

	std::string get_name();
	
	int get_id();

	std::string get_desc();

	//set desc
	void set_desc(std::string);

	friend std::ostream & operator << (std::ostream & out, Resource& rsc);

	void change_name(std::string name);

	bool delete_resource(int id);

	~Resource();

	private:
		std::string name_;
		std::string desc_;
		int id_;
};