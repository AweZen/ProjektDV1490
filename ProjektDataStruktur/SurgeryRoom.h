#pragma once
#include "Surgery.h"
#include "List.h"
#include <iostream>
using namespace std;
class SurgeryRoom
{
public:
	SurgeryRoom(int days= 1, int MinutesOpen = 660);
	~SurgeryRoom();
	bool addSurgery(Surgery surgery);
	bool removeSurgery(Surgery surgery);
	void printSurgerys();
	void reset();
	void setMinutesOpen(int time);	
	bool operator==(const SurgeryRoom& other);
	int getAmountOfSurgerys()const;
	Surgery GetSurgery(int i, int day = 0)const;

private:
	int *timeUsed;
	int *maxTime;
	int days;
	List<Surgery> *surgerys;
};

SurgeryRoom::SurgeryRoom(int days, int MinutesOpen)
{
	this->days = days;
	this->maxTime = new int[this->days];
	this->timeUsed = new int[this->days];
	this->surgerys = new List<Surgery>[this->days];


	for (int i = 0; i < this->days; i++) {
		this->maxTime[i] = MinutesOpen;
		this->timeUsed[i] = 0;
	}
}

bool SurgeryRoom::addSurgery(Surgery surgery)
{
	bool added = false; 
	for (int i = 0; i < this->days && !added ; i++) {
		this->timeUsed[i] += surgery.getTime();
		if (this->timeUsed[i] <= this->maxTime[i]) {
			this->surgerys[i].insertAt(0, surgery);
			added = true;
		}	else {
			this->timeUsed[i] -= surgery.getTime();
		}
	}

	return added;
}

bool SurgeryRoom::removeSurgery(Surgery surgery)
{
	bool removed = false;
	for(int i = 0; i < this->days && !removed; i++){
	if (this->surgerys[i].removeElement(surgery)) {
		removed = true;
		this->timeUsed[0] -= surgery.getTime();
		}
	}
	return removed;
}

void SurgeryRoom::printSurgerys()
{
	Surgery temp;
	int currentHour = 8;
	int currentMinute = 0;
	cout << "This room is open from 8:00 to " << (this->maxTime[0] / 60)+8 << ":" << (this->maxTime[0] % 60) << " For " << this->days << " days " <<endl;
	cout << "And contains the following operation Ids " << endl;

	for (int i = 0; i < this->days; i++) {
		cout << "day  " << i + 1 << " Ids : " << endl;
		for (int j = 0; j < surgerys[i].length(); j++) {
			temp = surgerys[i].getAt(j);
			cout << temp.getId() << " "; 
		}
		cout << endl;
	}
	
/*
	for(int j = 0; j < this->days; j++)
	{
		for (int i = 0; i < surgerys[j].length(); i++) {
			temp = surgerys[j].getAt(i);
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
	}*/
}

void SurgeryRoom::reset()
{
	for(int i = 0; i < this->days; i++){
		while(this->surgerys[i].length() != 0){	
			surgerys[i].removeAt(0);
		}
		this->timeUsed[i] = 0;
	}
}

void SurgeryRoom::setMinutesOpen(int time)
{
	for (int i = 0; i < this->days; i++) {
		this->maxTime[i] = time;
	}
}

inline bool SurgeryRoom::operator==(const SurgeryRoom & other)
{
	bool result = true;
	if (this->days == other.days) {
		for (int i = 0; i < this->days; i++) {
			if (this->surgerys[i].length() == other.surgerys[i].length()) {
				for (int i = 0; i < getAmountOfSurgerys(); i++) {
					if (!(this->surgerys[i].getAt(i) == other.surgerys[i].getAt(i))) {
						result = false;
					}
				}
			}
			else {
				result = false;
			}
		}
	}
	if (!(this->days == other.days && this->maxTime[0] == other.maxTime[0])) {
		result = false;
	}
	return result;
}

int SurgeryRoom::getAmountOfSurgerys()const
{
	int amount = 0;
	for (int i = 0; i < this->days;i++) {
		amount += this->surgerys[i].length();
	}
	return amount;
}

inline Surgery SurgeryRoom::GetSurgery(int i, int day)const
{

	return this->surgerys[day].getAt(i);
}

SurgeryRoom::~SurgeryRoom()
{
}