#pragma once
#include "Surgery.h"
#include "List.h"
#include <iostream>
using namespace std;
class SurgeryRoom
{
public:
	SurgeryRoom(int days = 1, int MinutesOpen = 10);
	bool addSurgery(Surgery surgery);
	bool removeSurgery(Surgery surgery);
	void printSurgerys();
	void setMinutesOpen(int time);	
	bool operator==(const SurgeryRoom& other);
	int getAmountOfSurgerys()const;
	Surgery GetSurgery(int i)const;
	~SurgeryRoom();

private:
	int Maxtime;
	int timeUsed;
	int days;
	List<Surgery> surgerys;
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
	if (this->timeUsed <= this->Maxtime) {
		this->surgerys.insertAt(0, surgery);
		added = true;
	}
	else {
		this->timeUsed -= surgery.getTime();

	}
	return added;
}

bool SurgeryRoom::removeSurgery(Surgery surgery)
{
	bool removed = false;
	if (this->surgerys.removeElement(surgery)) {
		removed = true;
		this->timeUsed -= surgery.getTime();
	}
	return removed;
}

void SurgeryRoom::printSurgerys()
{
	Surgery temp;
	int currentHour = 8;
	int currentMinute = 0;
	cout << "This room is open from 8:00 to " << (this->Maxtime / 60)+8 << ":" << (this->Maxtime % 60) << endl;
	for (int i = 0; i < surgerys.length(); i++) {
		temp = surgerys.getAt(i);
		cout << "	Operation nummer " << i+1 <<": " << endl;
		cout << "		Start tid: " << currentHour << ":" << currentMinute;
		currentHour += temp.getTime() / 60;
		currentMinute += temp.getTime() % 60;
		if (currentMinute >= 60) {
			currentMinute -= 60;
			currentHour++;
		}
		if (currentHour >= 24) {
			currentHour -= 24;
		}
		cout << "		Slut tid: " << currentHour << ":" << currentMinute << endl;
		cout << "		ID:  " << temp.getId() << endl;
		cout << "		Type:  " << temp.getType() << endl; 

	}
}

void SurgeryRoom::setMinutesOpen(int time)
{
	this->Maxtime = time;
}

inline bool SurgeryRoom::operator==(const SurgeryRoom & other)
{
	bool result = true;
	if (this->surgerys.length() == other.surgerys.length()) {
		for (int i = 0; i < getAmountOfSurgerys(); i++) {
			if (!(this->surgerys.getAt(i) == other.surgerys.getAt(i))) {
				result = false;
			}
		}
	}
	else {
		result = false;
	}
	if (!(this->days == other.days && this->Maxtime == other.Maxtime)) {
		result = false;
	}
	return result;
}

int SurgeryRoom::getAmountOfSurgerys()const
{
	return this->surgerys.length();
}

inline Surgery SurgeryRoom::GetSurgery(int i)const
{
	return this->surgerys.getAt(i);
}

SurgeryRoom::~SurgeryRoom()
{
}