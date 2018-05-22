#pragma once
#include "Surgery.h"
#include "List.h"
class SurgeryRoom
{
public:
	SurgeryRoom(int days, int MinutesOpen);
	bool addSurgery(Surgery surgery);
	bool removeBiggest();
	~SurgeryRoom();

private:
	int Maxtime;
	int timeUsed;
	int days;
	List<Surgery> Sugery;
};

SurgeryRoom::SurgeryRoom(int days, int MinutesOpen)
{
	this->days = days;
	this->timeUsed = 0;
	this->Maxtime = MinutesOpen;
}

bool SurgeryRoom::addSurgery(Surgery surgery)
{
	bool test = false;
	this->timeUsed += surgery.getTime();
	if (this->timeUsed > this->Maxtime) {
		this->Sugery.insertAt(0, surgery);
		test = true;
	}
	else {
		this->timeUsed = this->timeUsed - surgery.getTime();

	}
	return test;
}

SurgeryRoom::~SurgeryRoom()
{
}