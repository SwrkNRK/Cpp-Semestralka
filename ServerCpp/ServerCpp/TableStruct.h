#ifndef TABLESTRUCT_H
#define TABLESTRUCT_H

#include <string>


using std::string;


typedef struct row
{
	string value;

	row() {
		value = "";
	}

	~row() {
		value = "";
	}


}ROW;

typedef struct column
{
	ROW* row;
	string type;
	string name;

	column(){

		row = new ROW[100];
		type = "";
		name = "";
	}

	~column() {

		delete[] row;
		type = "";
		name = "";
	}




}COLUMN;

#endif
