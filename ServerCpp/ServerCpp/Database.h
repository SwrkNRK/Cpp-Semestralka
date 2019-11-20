#ifndef DATABASE_H
#define DATABASE_H

#include "TableList.h"
#include "UserLIst.h"

using namespace std;

class Database
{
public:
	Database();
	~Database();

	int loadTables();
	int loadTable(string fileName);
	int loadUsers();
	int saveTables();
	int saveTable(int id);
	int saveUsers();
	void registerUser(string name, string password);

	void setUser(User *user);


	TableList* tli;
	UserList* uli;
private:




};




#endif