#include <iostream>
#include <string>
#include <fstream>
#include "PriorityQueue.h"
#include "SurgeryRoom.h"
# include <ctime>
using namespace std;
List<Surgery> readFromFile(string filename);
void printOperation(SurgeryRoom rooms[], int nrOfRooms);
void algoritm(List<Surgery> surgerys, SurgeryRoom rooms[], int nrOfRooms);
List<Surgery> sortMax(List<Surgery> surgerys);
List<Surgery> sortMin(List<Surgery> surgerys);


int main() {


	cout << "Welcome cunt! <3 " << endl;
	clock_t start;
	clock_t end;
	const int cap = 3;
	//TESTAR 1A
	List<Surgery> surgerys = readFromFile("Operationer_1a.txt");
	SurgeryRoom rooms1a[cap];	

	for (int i = 0; i < cap; i++) {
		rooms1a[i].setMinutesOpen(660);
	}

	cout << endl << endl << endl << endl << endl << "Run number 1" << endl << endl << endl << endl << endl;

	algoritm(surgerys, rooms1a,3 );
	printOperation(rooms1a, 3);

	cout << endl << endl << endl << endl << endl << "Run number 2" << endl << endl << endl << endl;
	for (int i = 0; i < cap; i++) {
		rooms1a[i].reset();

	}
	surgerys = sortMin(surgerys);
	algoritm(surgerys, rooms1a, 3);
	printOperation(rooms1a, 3);


	cout << endl << endl << endl << endl << endl << "Run number 3" << endl << endl << endl << endl << endl;

	for (int i = 0; i < cap; i++) {
		rooms1a[i].reset();
	}
	start = clock();
	surgerys = sortMax(surgerys);
	algoritm(surgerys, rooms1a, 3);
	printOperation(rooms1a, 3);
	end = clock();
	cout << endl << endl << endl << end - start << endl;


	//TESTAR 1B

	surgerys = readFromFile("Operationer_1b.txt");
	SurgeryRoom rooms1b[cap];

	for (int i = 0; i < cap; i++) {
		rooms1b[i].setMinutesOpen(660);
	}

	cout << endl << endl << endl << endl << endl << "Run number 1" << endl << endl << endl << endl << endl;

	algoritm(surgerys, rooms1b, 3);
	printOperation(rooms1b, 3);

	cout << endl << endl << endl << endl << endl << "Run number 2" << endl << endl << endl << endl;
	for (int i = 0; i < cap; i++) {
		rooms1b[i].reset();

	}
	surgerys = sortMin(surgerys);
	algoritm(surgerys, rooms1b, 3);
	printOperation(rooms1b, 3);


	cout << endl << endl << endl << endl << endl << "Run number 3" << endl << endl << endl << endl << endl;

	for (int i = 0; i < cap; i++) {
		rooms1b[i].reset();
	}
	start = clock();
	surgerys = sortMax(surgerys);
	algoritm(surgerys, rooms1b, 3);
	printOperation(rooms1b, 3);
	end = clock();
	cout << endl << endl << endl << end - start << endl;





	//TESTAR 2
/*
	surgerys = readFromFile("Operationer_2.txt");
	SurgeryRoom rooms2[cap] = { (2),(2),(2) };
	rooms2[0].setMinutesOpen(660);
	rooms2[1].setMinutesOpen(840);
	rooms2[2].setMinutesOpen(540);

	for (int i = 0; i < cap; i++) {
		result.insertAt(i, rooms2[i]);
	}

	surgerys = sortMax(surgerys);
	algoritm(surgerys, rooms2, 3);
	printOperation(rooms2, 3);

	cout << endl << endl << endl << end - start << endl;*/
	system("pause");
}

List<Surgery> readFromFile(string filename) {
	ifstream in;
	int id, time, currentPos;
	string type, line;
	List<Surgery> surgerys;
	int i = 0;
	in.open(filename);
	while (!in.eof())
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
		surgerys.insertAt(i, temp);
		line = "";
		i++;
	}
	in.close();
	return surgerys;
}

void printOperation(SurgeryRoom array[], int cap) {
	for (int i = 0; i < cap; i++) {
		cout << "Room number : " << i + 1 << " has operations: ";
		array[i].printSurgerys();
		cout << endl;
	}
}

void algoritm(List<Surgery> surgerys, SurgeryRoom rooms[],int cap)
{
	bool full = false;
	bool foundRoom = false;
	bool orientation = true;
	int i = 0;
	while(!surgerys.length() == 0){
		full = false;
			if (!rooms[i].addSurgery(surgerys.getAt(0)))
			{
				full = true;
				for (int j = 0; j < cap && foundRoom == false; j++) {
					if (rooms[j].addSurgery(surgerys.getAt(0))) {
						foundRoom = true;
					}
				}
				foundRoom = false;
			}
			surgerys.removeAt(0);
			if (i != 0 && i != cap-1) {
				if (orientation) {
					i++;
				}
				else {
					i--;
				}
			}
			else {
				if (i == 0) {
					if (orientation) {
						i++;
					}
					orientation = true;
				}
				else {
					if (!orientation) {
						i--;
					}
					orientation = false;
				}
			}


		}
}

List<Surgery> sortMax(List<Surgery> surgerys)
{
	List<Surgery> sorted;
	PriorityQueue sorter(surgerys.length()+1);
	for (int i = 0; i < surgerys.length(); i++) {
		sorter.enqueue(surgerys.getAt(i));
	}
	for (int i = 0; i < surgerys.length()-1; i++) {
		sorted.insertAt(0, sorter.dequeue());
	}
	return sorted;
}

List<Surgery> sortMin(List<Surgery> surgerys)
{
	List<Surgery> sorted;
	PriorityQueue sorter(surgerys.length(), 5, false);
	for (int i = 0; i < surgerys.length(); i++) {
		sorter.enqueue(surgerys.getAt(i));
	}
	for (int i = 0; i < surgerys.length() - 1; i++) {
		sorted.insertAt(0, sorter.dequeue());
	}
	return sorted;
}




