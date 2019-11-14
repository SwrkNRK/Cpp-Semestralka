#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <sstream>
#include "TableStruct.h"
#include "User.h"

using std::string;
using std::cout;

class Table
{
public:
	Table(int tableID, User* userID);
	Table();
	~Table();


	COLUMN* col;								// A pointer to (what will be) an array of Columns for the users
	
	int rowCount;								// Count of how many rows are currently in the table
	int colCount;								// Count of how many Columns are currently in the table

	int tableID;								// ID of table

	User* owner;								// A pointer to user who created this table
private:

};





#endif
