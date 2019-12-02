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
	

	int strToEnum(string str);

	enum Cmds { LOAD=1, SAVE, ADDCOLUMN, REMOVECOLUMN };

	Database* dt;

private:
};








#endif