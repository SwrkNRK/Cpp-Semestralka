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

	int strToEnum(string str);

	enum Cmds { LOAD=1 };

	Database* dt;

private:

};








#endif