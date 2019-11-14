#ifndef TABLELIST_H
#define TABLELIST_H

#include "Table.h"

class TableList
{
public:
	TableList();
	~TableList();

	Table* getTable(int id);
	Table* findTable(int id);
	void addTableCount();
	int getTableCount();

private:
	int tableCount;
	Table* tables;
};




#endif