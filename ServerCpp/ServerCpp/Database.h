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

	int loadTable(string fileName);
	int saveTable(int id);
	

private:
	TableList* tli;
	UserList* uli;





};




#endif