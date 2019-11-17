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

	string name;
	string password;
	int userID;

private:

};




#endif
