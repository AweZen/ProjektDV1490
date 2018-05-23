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

	const int CAP = 19;
	const int cap = 3;
	Surgery array[CAP];
	readFromFile(array, CAP, "Operationer_1b.txt");
	SurgeryRoom rooms[cap];
	for (int i = 0; i < cap; i++) {
		rooms[i].setMinutesOpen(660) ;	
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
	List<Surgery> surgerys;
	for (int i = 0; i < numberOfSurgerys; i++) {
		surgerys.insertAt(0, arrayOfSurgerys[i]);
	}

	//Börja med greedy? 	for (int i = 0; i < numberOfRooms; i++) {
	int numersOfResult = 3;
	bool full = false;
	bool done = false;
	int j = 0;
	for (int i = 0; i < numberOfRooms && !done; i++) {
		full = false;
		while (!full && !done) {
			if (!arrayOfSurgeryRoom[i].addSurgery(surgerys.getAt(j))) {
				full = true;
				j++;
			}


			if (j == numberOfSurgerys) {
				done = true;
			}
		}
		result[0].insertAt(i, arrayOfSurgeryRoom[i]);
	}
	if (!done) {
		for (int i = 0; i < numberOfRooms && !done; i++) {
			result[0].removeElement(arrayOfSurgeryRoom[i]);

			full = false;
			while (!full && !done) {
				if (!arrayOfSurgeryRoom[i].addSurgery(surgerys.getAt(j))) {
					full = true;
					j++;
				} 
	

				if (j == numberOfSurgerys) {
					done = true;
				}
			}
			result[0].insertAt(i, arrayOfSurgeryRoom[i]);
		}
	}
}




