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