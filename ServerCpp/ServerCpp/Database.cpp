#define _CRT_SECURE_NO_WARNINGS 1

#include "Database.h"


Database::Database()
{
	tli = new TableList();
	uli = new UserList();

}

Database::~Database()
{
	delete tli;
	delete uli;

}



int Database::loadTable(string fileName) {
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Tables\\";
	path += fileName + ".txt";
	FILE* srcFile = fopen(path.c_str(), "r");
	if (srcFile == NULL) { return -1; }
	int c = 0;
	string tmp;

	Table *t = tli->getTable(tli->getTableCount());
	//Table *t = new Table();
	do {
		c = fgetc(srcFile);
		tmp += c;
			
		if ((char)c == ' ') {
			t->col[t->colCount++].type = tmp;
			printf("%s\n", tmp.c_str());
			tmp = "";
			
		}

		if ((char)c == ':') {
			t->col[t->colCount].name = tmp;
			tmp = "";
		}

	} while (c != '\n');





	if (fclose(srcFile) != 0) {
		perror("Closing dest file has failed");
	}

	

}




