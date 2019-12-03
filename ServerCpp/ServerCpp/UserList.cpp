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

User* UserList::getUserAtPos(int pos) {
	return users[pos];
}

void UserList::delUser(int id) {
	users[id]->~User();
	delete users[id];
}

void UserList::setUser(User* user, int id) {
	users[id] = user;
}
