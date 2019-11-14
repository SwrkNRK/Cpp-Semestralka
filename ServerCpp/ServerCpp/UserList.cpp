#include "UserLIst.h"




UserList::UserList()
{
	userCount = 0;
	users = new User[20];
}

UserList::~UserList()
{
	delete users;

}


