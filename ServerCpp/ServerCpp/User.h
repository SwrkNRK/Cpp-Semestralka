#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User
{
public:
	User();
	User(string name, string passwd, int id);
	~User();

private:
	string name;
	string password;
	int userID;

};




#endif
