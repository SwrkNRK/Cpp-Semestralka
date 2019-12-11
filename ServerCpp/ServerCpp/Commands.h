#ifndef COMMANDS_H
#define COMMANDS_H
#include "Database.h"


class Commands
{
public:
	Commands();
	~Commands();

	string processMsg(string str);
	string loadTableData(int tableID);
	string saveTableData(vector<string> str);
	string addColumn(vector<string> str);
	string removeColumn(vector<string> str);
	string connectUser(vector<string> str);
	string getUserTables(int userID);
	string addTable(vector<string> str);
	string removeTable(int tableID);
	string shutDown();

	int strToEnum(string str);

	enum Cmds { LOAD=1, SAVE, ADDCOLUMN, REMOVECOLUMN, LOGIN, GETUSERTABLES, NEWTABLE, SHUTDOWN, DELETETABLE};

	Database* dt;

private:
};








#endif