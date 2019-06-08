//This implements command design pattern all commands(update , check , create is)
#pragma once
#include<iostream>
#include"user.h"
#include"resource.h"
#include"role.h"

class Query {
	public:
		Query(User * usr, Resource* rsc, Actions action):
			usr_(usr),
			rsc_(rsc),
			action_(action)

		{


		}

	bool execute();

	private:
		Resource*  rsc_;
		User*  usr_;
		Actions action_;
};