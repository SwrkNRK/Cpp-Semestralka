
#include "User.h"


User::User()
{

}

User::User(string nm, string passwd, int id) {
	name = nm;
	password = passwd;
	userID = id;
}

User::~User()
{
	name = "";
	password = "";
}




