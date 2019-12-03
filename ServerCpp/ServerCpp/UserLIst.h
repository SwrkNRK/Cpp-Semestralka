#ifndef USERLIST_H
#define USERLIST_H

#include "User.h"

class UserList
{
public:
	UserList();
	~UserList();

	void setUserIDCounter(int value);
	void addUserIDCounter();
	void addUserCount();

	int getUserCount();
	int getUserIDCounter();

	User* findUser(int id);
	User* getUserAtPos(int position);
	void setUser(User *user, int id);
	void delUser(int id);


private:
	int userCount;
	int userIDCounter;
	User* users[20];

};


#endif
