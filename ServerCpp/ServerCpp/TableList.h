#ifndef TABLELIST_H
#define TABLELIST_H

#include "Table.h"
#include <vector>

using std::vector;

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
	//vector<Table*> tables;
	Table *tables[10];
};




#endif