#ifndef USERLIST_H
#define USERLIST_H

#include "User.h"

class UserList
{
public:
	UserList();
	~UserList();

private:
	int userCount;
	User* users;

};


#endif
