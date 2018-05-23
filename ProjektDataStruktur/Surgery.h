#pragma once
#include <string.h>
using namespace std;

class Surgery
{
public:
	Surgery(int id = 0, string type = "", int time= 0);
	~Surgery();
	int getTime()const;
	int getId()const;
	string getType()const;
	bool operator==(const Surgery& other);
private:
	int time;
	string type;
	int id;
};

Surgery::Surgery(int id, string type, int time)
{
	this->id = id;
	this->type = type;
	this->time = time;
}

Surgery::~Surgery()
{
}

int Surgery::getTime() const
{
	return this->time;
}

int Surgery::getId() const
{
	return this->id;
}

string Surgery::getType() const
{
	return this->type;
}

bool Surgery::operator==(const Surgery & other)
{
	return (this->time == other.time && this->id == other.id && this->type == other.type);
}
