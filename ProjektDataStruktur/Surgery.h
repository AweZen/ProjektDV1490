#include <String>
using namespace std;

class Surgery
{
public:
	Surgery(int id, string type, int time);
	~Surgery();
	int getTime()const;
	string getType()const;
	int getId()const;

private:
	int time;
	string type;
	int id;
};

Surgery::Surgery(int id = 0, string type = "", int time = 0)
{
	this->id = id;
	this->type = type;
	this->time = time;
}

Surgery::~Surgery()
{
}

inline int Surgery::getTime() const
{
	return this->time;
}
