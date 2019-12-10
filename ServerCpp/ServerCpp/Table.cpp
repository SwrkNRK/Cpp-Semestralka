
#include "Table.h"

Table::Table() {
	col = new COLUMN[100];
	for (int i = 0; i < 100; i++) {
		col[i].row = new ROW[100];
	}

	colCount = 0;
	rowCount = 0;
}

Table::Table(int tbID ,User* usr) {
	col = new COLUMN[100];
	for (int i = 0; i < 100; i++) {
		col[i].row = new ROW[100];
	}
	tableID = tbID;
	owner = usr;

	colCount = 0;
	rowCount = 0;
}


Table::~Table() {
	for (int i = 0; i < colCount; i++) {
		delete[] col[i].row;
	}
	delete[] col;

}


