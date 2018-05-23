#pragma once
#include "Surgery.h"
#include "List.h"
#include <iostream>
using namespace std;
class SurgeryRoom
{
public:
	SurgeryRoom(int days, int MinutesOpen);
	bool addSurgery(Surgery surgery);
	bool removeBiggest();
	void printSurgerys();
	~SurgeryRoom();

private:
	int Maxtime;
	int timeUsed;
	int days;
	List<Surgery> Surgerys;
};

SurgeryRoom::SurgeryRoom(int days, int MinutesOpen)
{
	this->days = days;
	this->timeUsed = 0;
	this->Maxtime = MinutesOpen;
}

bool SurgeryRoom::addSurgery(Surgery surgery)
{
	bool added = false;
	this->timeUsed += surgery.getTime();
	if (this->timeUsed > this->Maxtime) {
		this->Surgerys.insertAt(0, surgery);
		added = true;
	}
	else {
		this->timeUsed -= surgery.getTime();

	}
	return added;
}

void SurgeryRoom::printSurgerys()
{
	Surgery temp;
	int currentHour = 8;
	int currentMinute = 0;
	cout << "This room is open from 8:00 to " << (this->Maxtime / 60) << ":" << (this->Maxtime % 60) << endl;
	for (int i = 0; i < Surgerys.length(); i++) {
		temp = Surgerys.getAt(i);
		cout << "	Operation nummer " << i <<": " << endl;
		cout << "Start tid: " << currentHour << ":" << currentMinute;
		currentHour += temp.getTime() / 60;
		currentMinute += temp.getTime() % 60;
		if (currentHour >= 24) {
			currentHour = 0;
		}
		if (currentMinute >= 60) {
			currentMinute -= 60;
			currentHour++;
		}
		cout << "			Slut tid: " << currentHour << ":" << currentMinute << endl;
	}
}

SurgeryRoom::~SurgeryRoom()
{
}