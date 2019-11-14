#include "TableList.h"


TableList::TableList()
{
	tableCount = 0;
	tables = new Table[10];

}

TableList::~TableList()
{
	delete tables;

}


Table* TableList::getTable(int id) {
	return tables;
}

Table* TableList::findTable(int id) {
	for (int i = 0; i < tableCount; i++) {
		if (tables[i].tableID == id) {
			return &tables[id];
		}
	}
	return NULL;
}


int TableList::getTableCount() {
	return tableCount;
}

void TableList::addTableCount() {
	tableCount++;
}




