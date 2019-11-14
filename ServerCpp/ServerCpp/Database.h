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


private:
	TableList* tli;
	UserList* uli;





};




#endif