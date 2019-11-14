#ifndef TABLESTRUCT_H
#define TABLESTRUCT_H

#include <string>


using std::string;


typedef struct row
{
	string value;

}ROW;

typedef struct column
{
	ROW* row;
	string type;
	string name;


}COLUMN;

#endif
