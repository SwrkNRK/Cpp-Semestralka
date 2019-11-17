#include "UserLIst.h"




UserList::UserList()
{
	userCount = 0;
	userIDCounter = 0;
	for (int i = 0; i < 20; i++) {
		users[i] = new User();
	}
}

UserList::~UserList()
{
	delete users;

}

void UserList::setUserIDCounter(int val) {
	userIDCounter = val;
}

void UserList::addUserIDCounter() {
	userIDCounter++;
}

void UserList::addUserCount() {
	userCount++;
}

int UserList::getUserCount() {
	return userCount;
}

int UserList::getUserIDCounter() {
	return userIDCounter;
}

User* UserList::getUser(int id) {
	return users[id];
}
