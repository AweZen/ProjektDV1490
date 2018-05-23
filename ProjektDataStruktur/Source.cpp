#include <iostream>
#include <string>
#include <fstream>

#include "SurgeryRoom.h"
using namespace std;
void readFromFile(Surgery array[], int cap,string filename);
void printOperation(List<SurgeryRoom> list);
void algoritm(SurgeryRoom arrayOfSurgeryRoom[], int numberOfRooms, Surgery arrayOfSurgerys[], int numberOfSurgerys, List<SurgeryRoom> result[]);


int main() {


	cout << "Welcome cunt! <3 " << endl;
	SurgeryRoom room(1,600);

	if (room.addSurgery(Surgery(1, "Sinus", 200))) {
		cout << "Works1" << endl;
	}
	if (!room.addSurgery(Surgery(1, "Sinus", 500))) {
		cout << "Works2" << endl;
	}
	if (room.addSurgery(Surgery(1, "Sinus", 100))) {
		cout << "Works3" << endl;
	}
	if (room.removeSurgery(Surgery(1, "Sinus", 100))) {
		cout << "Works4" << endl;
	}
	if (room.addSurgery(Surgery(1, "Sinus", 100))) {
		cout << "Works3" << endl;
	}
	//room.printSurgerys();
	const int CAP = 30;
	const int cap = 3;
	Surgery array[CAP];
	readFromFile(array, CAP, "Operationer_1a.txt");
	SurgeryRoom rooms[cap];
	for (int i = 0; i < cap; i++) {
		rooms[i].setMinutesOpen(500) ;
	}
	List<SurgeryRoom> result[cap];
	algoritm(rooms, cap, array, CAP, result);
	printOperation(result[0]);
	system("pause");
}

void readFromFile(Surgery array[], int cap,string filename) {
	ifstream in;
	int id, time, currentPos;
	string type, line;
	int i = 0;
	in.open(filename);
	while (!in.eof() || i > cap)
	{
		getline(in, line);
	//6	cout << line << endl;
		currentPos = line.find(",");
		id = stoi(line.substr(0, currentPos));
		line = line.substr(currentPos + 1);
		currentPos = line.find(",");
		type = line.substr(0, currentPos);
		line = line.substr(currentPos + 1);
		time = stoi(line);
		 
		Surgery temp(id, type, time);
		array[i] = temp;
		//cout << "ID: " << id << "    Type: " << type << "    Time: " << time << endl;
		line = "";
		i++;
	}
	in.close();
}

void printOperation(List<SurgeryRoom> list) {
	for (int i = 0; i < list.length(); i++) {
		cout << "Room number " << i + 1 << endl;
		list.getAt(i).printSurgerys();
	}
}

void algoritm(SurgeryRoom arrayOfSurgeryRoom[], int numberOfRooms, Surgery arrayOfSurgerys[], int numberOfSurgerys, List<SurgeryRoom> result[])
{
	//Börja med greedy? 	for (int i = 0; i < numberOfRooms; i++) {
	int numersOfResult = 3;
	bool full = false;
	bool done = false;
	int j = 0;
	for (int i = 0; i < numberOfRooms && !done; i++) {
		while (!full && !done) {
			if (!arrayOfSurgeryRoom[i].addSurgery(arrayOfSurgerys[j])) {
				full = true;
			}
			if (j == numberOfSurgerys) {
				done = true;
			}
			j++;
		}
		result[0].insertAt(0, arrayOfSurgeryRoom[i]);
	}
	
}
