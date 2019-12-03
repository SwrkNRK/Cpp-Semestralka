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

	if (str == "ADDCOLUMN") {
		return ADDCOLUMN;
	}

	if (str == "REMOVECOL") {
		return REMOVECOLUMN;
	}

	if (str == "LOGIN") {
		return LOGIN;
	}

	if (str == "GETUSERTABLES") {
		return GETUSERTABLES;
	}

}

string Commands::processMsg(string str) {  //LOAD:111
	vector<string> s;
	stringstream ss(str);
	char delimiter = ':';
	string tok = "";

	while (getline(ss, tok, delimiter)) {
		s.push_back(tok);
	}

	switch (strToEnum(s[0]))
	{
	case 1:
		return loadTableData(atoi(s[1].c_str()));

	case 2:
		return saveTableData(s);

	case 3:
		return addColumn(s);

	case 4:
		return removeColumn(s);

	case 5:
		return connectUser(s);

	case 6:
		return getUserTables(atoi(s[1].c_str()));

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
	if (t == NULL) { return "Failed"; }
	t->rowCount = 0;
	do {

		addRowToTable(t, str[i], t->rowCount);
		t->rowCount++;
		i++;
	} while (str[i] != "*");

	dt->saveTable(t->tableID);

	return "SAVED";
}

string Commands::addColumn(vector<string> str) {
	int i = 1;
	Table *t = dt->tli->findTable(atoi(str[i++].c_str()));			// after this i = 2
	if (t == NULL) { return "Failed"; }

	t->col[t->colCount].name = str[i++];
	t->col[t->colCount].type = str[i++];
	t->colCount++;

	return "ADDEDCOLUMN";
}

void removeColAtID(Table *t, const int ID) {

	for (int i = 0; i < t->rowCount; i++) {
		printf("Remove: %s\n", t->col[ID - 1].row[i].value.c_str());
		t->col[ID].row[i].value = "";
	}
	t->col[ID].name = "";
	t->col[ID].type = "";
	printf("Remove: %s\n", t->col[ID - 1].row[0].value.c_str());
}

string Commands::removeColumn(vector<string> str) {
	int i = 1;
	Table *t = dt->tli->findTable(atoi(str[i++].c_str()));			// after this i = 2
	if (t == NULL) { return "Failed"; }
	int colID = atoi(str[i].c_str());

	if (colID == t->colCount) {
		removeColAtID(t, colID);
		t->colCount--;
		return "COLREMOVED";
	}


	t->colCount--;
	for (int i = colID; i < t->colCount; i++) {
		for (int j = 0; j < t->rowCount; j++) {
			t->col[i].row[j].value = t->col[i + 1].row[j].value;
		}
		t->col[i].name = t->col[i+1].name;
		t->col[i].type = t->col[i+1].type;
		
	}
	removeColAtID(t, i);

	return "COLREMOVED";
}

string Commands::connectUser(vector<string> str) {
	int name = 1;
	int pass = 2;
	User *u;
	for (int i = 0; i < dt->uli->getUserCount(); i++) {
		u = dt->uli->getUserAtPos(i);
		if (u->name == str[name] && u->password == str[pass]) {
			return "CONNECTED:" + to_string(u->userID);
		}
	}
	return "INVALIDLOGIN";
}

string Commands::getUserTables(int userID) {
	User* u = dt->uli->findUser(userID);
	string str = "";

	for (int i = 0; i < dt->tli->getTableCount(); i++) {
		if (dt->tli->getTable(i)->owner->userID == u->userID) {
			str += dt->tli->getTable(i)->tableName;
			str += "," + to_string(dt->tli->getTable(i)->tableID) + ":";
		}
	}
	if (str == "") {
		return "NOTABLES";
	}
	else {
		str.pop_back();
		return str;
	}


}
