#include"query.h"
#include"datastore.h"

//helper funciton for converitng enum to string

const char* action_to_string(Actions action)
{
    switch (action)
    {
        case READ: 
        	return "READ";
        case WRITE: 
        	return "WRITE";
        case UPDATE: 
        	return "UPDATE";
        case DELETE: 
        	return "DELETE";
        default:
        	return "UNKNOWN_ACTION";
    }
}

void Validate_access_query::execute() {
	bool ret = Datastore::get_datastore()->Validate_permission_on_rsc(rsc_, usr_ , action_);
	if (ret) {
		std::cout<<"Opearation "<<action_to_string(action_)<<" on resource "<<rsc_->get_name()<<" by user: "<<usr_->get_name()<<" is allowed"<<std::endl;
	} else {
		std::cout<<"Opearation "<<action_to_string(action_)<<" on resource "<<rsc_->get_name()<<" by user: "<<usr_->get_name()<<" is NOT allowed"<<std::endl;
	}

	return;
}

void Add_resource_to_role_query::execute() {
	Datastore::get_datastore()->Add_resource_to_role(rol_,rsc_,rsc_set_);
	return;
}

//TODO: Point follwing query to Datastore class]
void Add_role_to_user_query::execute() {
	usr_->add_role(rol_);
	return;
}

