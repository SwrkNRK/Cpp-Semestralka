#include "TableList.h"


TableList::TableList()
{
	tableCount = 0;

	for (int i = 0; i < 10; i++)
	{
		//Table* t = new Table();
		tables[i] = new Table();
	}
}

TableList::~TableList()
{
	for (int i = 0; i < 10; i++)
	{
		delete tables[i];
	}

}

int TableList::getTableIDCounter() {
	return tableIDCounter;
}

void TableList::setTableIDCounter(int value) {
	tableIDCounter = value;
}

Table* TableList::getTable(int id) {
	return tables[id];
}

Table* TableList::findTable(int id) {
	for (int i = 0; i < tableCount; i++) {
		if (tables[i]->tableID == id) {
			return tables[i];
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




