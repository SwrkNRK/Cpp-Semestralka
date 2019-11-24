#include "Commands.h"





Commands::Commands()
{
	dt = new Database();
	dt->loadUsers();
	dt->loadTables();
}

Commands::~Commands()
{
}

int Commands::strToEnum(string str) {

	if (str == "LOAD") {
		return LOAD;
	}

	if (str == "SAVE") {
		return SAVE;
	}

}

string Commands::processMsg(string str) {  //LOAD:111
	vector<string> s;
	stringstream ss(str);
	char delimiter = ':';
	string tok = "";
		
	while (getline(ss, tok, delimiter))  {
		s.push_back(tok);
	}

	switch (strToEnum(s[0]))
	{
	case 1:
		return loadTableData(atoi(s[1].c_str()));
		break;
	case 2:
		return saveTableData(s);
		break;
	}

}

string Commands::loadTableData(int tableID) {
	Table *t = dt->tli->findTable(tableID);
	string str = "";

	// Writing in file all the name of column and its type
	for (int i = 0; i < t->colCount; i++) {
		str += t->col[i].name;
		str += ":";
		str += t->col[i].type;
		str += " ";
	}

	str.pop_back();
	str += "*";

	// Writing in file all the data in rows
	for (int i = 0; i < t->rowCount; i++) {
		str += ":";
		for (int j = 0; j < t->colCount; j++)
		{
			str += t->col[j].row[i].value;
			str += ",";

		}
		
	}

	str.pop_back();
	str += "*";

	return str;
}

//Jurko,Dobrota,1:Lukyno,Cukyno,2:Samko,Pash,3:Robko,Bobko,4:gr,,7*

void addRowToTable(Table *t, string str, int id) {
	vector<string> s;
	char delimiter = ',';
	string tok = "";
	stringstream ss(str);
	int i = 0;
	while (getline(ss, tok, delimiter)) {
		t->col[i++].row[id].value = tok;
	}
	

}


string Commands::saveTableData(vector<string> str) {
	int i = 1;
	Table *t = dt->tli->findTable(atoi(str[i++].c_str()));			// after this i = 2
	t->rowCount = 0;
	do {

		addRowToTable(t, str[i], t->rowCount);
		t->rowCount++;
		i++;
	} while (str[i] != "*");


	return "SAVED";
}


