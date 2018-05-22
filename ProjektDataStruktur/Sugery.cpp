#include <String>
using namespace std;


class Sugery
{
public:
	Sugery(int id, string type, int time);
	~Sugery();
	int getTime()const;
	string getType()const;
	int getId()const;	

private:
	int time;
	string type;
	int id;
};

Sugery::Sugery(int id, string type, int time)
{
	this->id = id;
	this->type = type;
	this->time = time;
}

Sugery::~Sugery()
{
}