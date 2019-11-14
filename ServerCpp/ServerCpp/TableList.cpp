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
	return &tables[id];
}

int TableList::getTableCount() {
	return tableCount;
}

void TableList::addTableCount() {
	tableCount++;
}


