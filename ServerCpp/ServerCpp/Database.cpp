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


int Database::loadTables() {
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Tables\\ListOfTables.txt";
	//string path = "C:\\Users\\stoli\\CLionProjects\\Cpp-Semestralka\\ServerCpp\\Tables\\ListOfTables.txt"; //Path pre teclast
	//string path = "C:\\Users\\Samuel\\source\\repos\\Cpp-Semestralka\\ServerCpp\\Tables\\ListOfTables.txt";

	FILE* srcFile = fopen(path.c_str(), "r");
	if (srcFile == NULL) { return -1; }
	int c = 0;
	string tmp;
	//get tableIDCounter from file
	char id[100];
	fgets(id, 100, srcFile);
	tli->setTableIDCounter(atoi(id));

	do {
		c = fgetc(srcFile);

		 if ((char)c == '\n' || (c == EOF && tmp != "")) {
			 loadTable(tmp);
			tmp = "";
		}
		else {
			tmp += c;
		}

	} while (c != EOF);

	fclose(srcFile);
}

int Database::loadTable(string fileName) {
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Tables\\";
	//string path = "C:\\Users\\stoli\\CLionProjects\\Cpp-Semestralka\\ServerCpp\\Tables\\"; //Path pre teclast
	//string path = "C:\\Users\\Samuel\\source\\repos\\Cpp-Semestralka\\ServerCpp\\Tables\\";
	path += fileName + ".txt";
	FILE* srcFile = fopen(path.c_str(), "r");
	if (srcFile == NULL) { return -1; }
	int c = 0;
	string tmp;

	Table *t = tli->getTable(tli->getTableCount());
	int pomCounter = 0;
	do {
		c = fgetc(srcFile);

		if ((char)c == ' ') {
			if (pomCounter == 0) {
				t->tableName = tmp;
				tmp = "";
				pomCounter++;
			}
			else if (pomCounter == 1) {
				t->owner = uli->findUser(atoi(tmp.c_str()));
				tmp = "";
			}

		} else if ((char)c == '\n') {
			t->tableID = atoi(tmp.c_str());
			tmp = "";
		}
		else {
			tmp += c;
		}

	} while (c != '\n');

	do {
		c = fgetc(srcFile);
		

		if ((char)c == ' ') {
			t->col[t->colCount++].type = tmp;
			printf("%s\n", tmp.c_str());
			tmp = "";

		} else if ((char)c == ':') {
			t->col[t->colCount].name = tmp;
			tmp = "";
		} else { tmp += c; }

	} while (c != '\n');

	int i = 0;
	tmp = "";

	do {
		c = fgetc(srcFile);


		if ((char)c == '\n' || (c == EOF && tmp != "")) {
			t->col[i].row[t->rowCount++].value = tmp;
			i = 0;
			tmp = "";

		} else if ((char)c == ' ') {
			t->col[i++].row[t->rowCount].value = tmp;
			tmp = "";

		}
		else {
			tmp += c;
		}

	} while (c != EOF);

	tli->addTableCount();
	printf("%d\n", t->tableID);

	if (fclose(srcFile) != 0) {
		perror("Closing dest file has failed");
	}
	fclose(srcFile);
}

void addUserParam(int *val, string tmp, UserList *uli) {
	User *u = uli->getUserAtPos(uli->getUserCount());

	switch (*val)
	{
	case 0:
		u->name = tmp;
		*val = *val + 1;
		break;
	case 1:
		u->password = tmp;
		*val = *val + 1;
		break;
	case 2:
		u->userID = atoi(tmp.c_str());
		uli->addUserCount();
		*val = 0;
		break;

	}
}

int Database::loadUsers() {
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Users\\ListOfUsers.txt";
	//string path = "C:\\Users\\stoli\\CLionProjects\\Cpp-Semestralka\\ServerCpp\\Users\\ListOfUsers.txt"; //Path pre teclast
	//string path = "C:\\Users\\Samuel\\source\\repos\\Cpp-Semestralka\\ServerCpp\\Users\\ListOfUsers.txt";

	FILE* srcFile = fopen(path.c_str(), "r");
	if (srcFile == NULL) { return -1; }
	int c = 0;
	string tmp = "";
	int i = 0;

	// load UserIDCounter from file
	do {
		c = fgetc(srcFile);
		if (c == '\n') {
			uli->setUserIDCounter(atoi(tmp.c_str()));
			tmp = "";
		} else {
			tmp += c;
		}

	} while (c != '\n');
	
	// load Users from file
	do {
		c = fgetc(srcFile);

		if (c == ' ') {
			addUserParam(&i, tmp, uli);
			tmp = "";
		}
		else if (c == '\n' || (c == EOF && tmp != "")) {
			addUserParam(&i, tmp, uli);
			tmp = "";
		} else {
			tmp += c;
		}

	} while (c != EOF);
	printf("%d\n", uli->getUserAtPos(3)->userID);
	fclose(srcFile);
}

int Database::saveTables() {
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Tables\\ListOfTables.txt";
	//string path = "C:\\Users\\stoli\\CLionProjects\\Cpp-Semestralka\\ServerCpp\\Tables\\ListOfTables.txt"; //Path pre teclast
	//string path = "C:\\Users\\Samuel\\source\\repos\\Cpp-Semestralka\\ServerCpp\\Tables\\ListOfTables.txt";
	FILE* destFile = fopen(path.c_str(), "w");
	if (destFile == NULL) { return -1; }
	string tmp;
	// add tableIDcounter to file
	tmp = to_string(tli->getTableIDCounter());
	tmp += "\n";
	fputs(tmp.c_str(), destFile);
	// add tables name to file
	for (int i = 0; i < tli->getTableCount(); i++) {
		tmp = tli->getTable(i)->tableName;
		tmp += "\n";
		fputs(tmp.c_str(), destFile);
	}

	fclose(destFile);
	return 1;
}

int Database::saveTable(int id) {
	Table *t = tli->findTable(id);
	if (t == NULL) { return -1; }
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Tables\\";
	//string path = "C:\\Users\\stoli\\CLionProjects\\Cpp-Semestralka\\ServerCpp\\Tables\\"; //Path pre teclast
	//string path = "C:\\Users\\Samuel\\source\\repos\\Cpp-Semestralka\\ServerCpp\\Tables\\";
	printf("%s\n", t->tableName.c_str());
	path +=  t->tableName+".txt";
	FILE* destFile = fopen(path.c_str(), "w");
	if (destFile == NULL) { return -1; }
	string tmp;


	// Writing in file the tableName and ID
	tmp = t->tableName;
	tmp += " ";
	tmp += to_string(t->owner->userID);
	tmp += " ";
	tmp +=	to_string(t->tableID);
	tmp += "\n";
	fputs(tmp.c_str(), destFile);							// writing string tmp to file

	// Writing in file all the name of column and its type
	for (int i = 0; i < t->colCount; i++) {
		tmp = t->col[i].name;
		tmp += ":";
		tmp += t->col[i].type;
		tmp += " ";
		fputs(tmp.c_str(), destFile);						// writing string tmp to file
	}
	fputc('\n', destFile);


	// Writing in file all the data in rows
	for (int i = 0; i < t->rowCount; i++) {
		tmp = "";
		for (int j = 0; j < t->colCount; j++)
		{
			tmp += t->col[j].row[i].value;
			tmp += " ";

		}
		tmp.pop_back();	//erasing last space in string
		tmp += '\n';
		fputs(tmp.c_str(), destFile);							// writing string tmp to file
	}
	
	fclose(destFile);
	return 1;
}


void Database::registerUser(string nam, string passwd) {
	uli->getUserAtPos(uli->getUserCount())->~User();
	User* u = new User(nam, passwd, uli->getUserIDCounter());
	uli->setUser(u, uli->getUserCount());
	uli->addUserIDCounter();
	uli->addUserCount();
}

int Database::saveUsers() {
	string path = "C:\\Users\\LK\\Desktop\\Cpp semestr\\Cpp-Semestralka\\ServerCpp\\Users\\ListOfUsers.txt";
	//string path = "C:\\Users\\stoli\\CLionProjects\\Cpp-Semestralka\\ServerCpp\\Users\\ListOfUsers.txt"; //Path pre teclast
	//string path = "C:\\Users\\Samuel\\source\\repos\\Cpp-Semestralka\\ServerCpp\\Users\\";
	FILE* destFile = fopen(path.c_str(), "w");
	if (destFile == NULL) { return -1; }
	string tmp;

	tmp = to_string(uli->getUserIDCounter());
	tmp += '\n';
	fputs(tmp.c_str(), destFile);
	
	for (int i = 0; i < uli->getUserCount(); i++) {
		tmp = uli->getUserAtPos(i)->name;
		tmp += " ";
		tmp += uli->getUserAtPos(i)->password;
		tmp += " ";
		tmp += to_string(uli->getUserAtPos(i)->userID);
		tmp += "\n";
		fputs(tmp.c_str(), destFile);

	}
	fclose(destFile);
	return 1;

}