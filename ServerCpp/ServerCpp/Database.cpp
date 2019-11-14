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
	do {
		c = fgetc(srcFile);
		tmp += c;

		if ((char)c == ' ') {
			t->tableName = tmp;
			tmp = "";

		}

		if ((char)c == '\n') {
			t->tableID = atoi(tmp.c_str());
			tmp = "";
		}

	} while (c != '\n');

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

	int i = 0;

	do {
		c = fgetc(srcFile);
		tmp += c;

		if ((char)c == '\n') {
			t->col[i].row[t->rowCount++].value = tmp;
			i = 0;
			tmp = "";

		}

		if ((char)c == ' ') {
			t->col[i++].row[t->rowCount].value = tmp;
			tmp = "";

		}

	} while (c != EOF);

	tli->addTableCount();
	printf("%d\n", t->tableID);

	if (fclose(srcFile) != 0) {
		perror("Closing dest file has failed");
	}

}


int Database::saveTable(int id) {
	Table *t = tli->getTable(1);
	if (t == NULL) { return -1; }
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Tables\\";
	printf("%s\n", t->tableName.c_str());
	path +=  t->tableName+".txt";
	FILE* destFile = fopen(path.c_str(), "w");
	if (destFile == NULL) { return -1; }
	string tmp;
	/* TODO: nejde load tak ako má ukladá sa do premenných : " " a pravdepodobne aj \n
		saveTable nejde získa špecifickú tabu¾ku pravdepodobne sa nevytvorí pole 
		alebo aspoò nie je schopné by uložené v Table* tables v triede TableList


	*/

	// Writing in file the tableName and ID
	tmp = t->tableName;
	tmp += t->tableID;
	tmp += "\n";
	fputs(tmp.c_str(), destFile);							// writing string tmp to file

	// Writing in file all the name of column and its type
	for (int i = 0; i < t->colCount; i++) {
		tmp = t->col[i].name;
		tmp += ":";
		tmp += t->col[i].type;
		fputs(tmp.c_str(), destFile);						// writing string tmp to file
	}

	// Writing in file all the data in rows
	for (int i = 0; i < t->rowCount; i++) {
		tmp = "";
		for (int j = 0; j < t->colCount; j++)
		{
			tmp += t->col[j].row[i].value;

		}
		tmp.pop_back();	//erasing last space in string
		tmp += '\n';
		fputs(tmp.c_str(), destFile);							// writing string tmp to file
	}
	

}



