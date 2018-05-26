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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	cout << "Welcome cunt! <3 " << endl;
	clock_t startRun1,startRun2,startRun3;
	clock_t endRun1, endRun2, endRun3;
	const int cap = 3;
	//TESTAR 1A
	List<Surgery> surgerys = readFromFile("Operationer_1a.txt");
	
	SurgeryRoom rooms1aRun1[cap];	
	SurgeryRoom rooms1aRun2[cap];
	SurgeryRoom rooms1aRun3[cap];


	for (int i = 0; i < cap; i++) {
		rooms1aRun1[i].setMinutesOpen(660);	
		rooms1aRun2[i].setMinutesOpen(660);
		rooms1aRun3[i].setMinutesOpen(660);
	}

	startRun1 = clock();
	algoritm(surgerys, rooms1aRun1,3 );
	endRun1 = clock();

	startRun2 = clock();
	surgerys = sortMin(surgerys);
	algoritm(surgerys, rooms1aRun2, 3);
	endRun2 = clock();


	startRun3 = clock();
	surgerys = sortMax(surgerys);
	algoritm(surgerys, rooms1aRun3, 3);
	endRun3 = clock();
	cout << endl << "Run 1: " << endl << endl;
	printOperation(rooms1aRun1, 3);
	cout << endl << endl << "Run 2: " << endl << endl;
	printOperation(rooms1aRun2, 3);
	cout << endl <<endl << "Run 3: " << endl << endl;
	printOperation(rooms1aRun3, 3);
	cout << endl << endl << endl << "Time for the runs:" << endl;
	cout << "Run 1 : " << endRun1 - startRun1 << endl;
	cout << "Run 2 : " << endRun2 - startRun2 << endl;
	cout << "Run 3 : " << endRun3 - startRun3 << endl;

	
	//TESTAR 1B

	surgerys = readFromFile("Operationer_1b.txt");
	SurgeryRoom rooms1bRun1[cap];
	SurgeryRoom rooms1bRun2[cap];
	SurgeryRoom rooms1bRun3[cap];

	for (int i = 0; i < cap; i++) {
		rooms1bRun1[i].setMinutesOpen(660);
		rooms1bRun2[i].setMinutesOpen(660);
		rooms1bRun3[i].setMinutesOpen(660);

	}

	startRun1 = clock();
	algoritm(surgerys, rooms1bRun1, 3);
	endRun1 = clock();
	
	startRun2 = clock();
	surgerys = sortMin(surgerys);
	algoritm(surgerys, rooms1bRun2, 3);
	endRun2 = clock();


	startRun3 = clock();
	surgerys = sortMax(surgerys);
	algoritm(surgerys, rooms1bRun3, 3);
	endRun3 = clock();


	cout << endl << "Run 1: " << endl << endl;
	printOperation(rooms1bRun1, 3);
	cout << endl << endl << "Run 2: " << endl << endl;
	printOperation(rooms1bRun2, 3);
	cout << endl << endl << "Run 3: " << endl << endl;
	printOperation(rooms1bRun3, 3);
	 
	cout << endl << endl << endl << "Time for the runs:" << endl;
	cout << "Run 1 : " << endRun1 - startRun1 << endl;
	cout << "Run 2 : " << endRun2 - startRun2 << endl;
	cout << "Run 3 : " << endRun3 - startRun3 << endl;



	//TESTAR 2

	surgerys = readFromFile("Operationer_2.txt");
	SurgeryRoom rooms2Run1[cap] = { (2),(2),(2) };
	SurgeryRoom rooms2Run2[cap] = { (2),(2),(2) };
	SurgeryRoom rooms2Run3[cap] = { (2),(2),(2) };

	rooms2Run1[0].setMinutesOpen(660);
	rooms2Run1[1].setMinutesOpen(840);
	rooms2Run1[2].setMinutesOpen(540);

	rooms2Run2[0].setMinutesOpen(660);
	rooms2Run2[1].setMinutesOpen(840);
	rooms2Run2[2].setMinutesOpen(540);

	rooms2Run3[0].setMinutesOpen(660);
	rooms2Run3[1].setMinutesOpen(840);
	rooms2Run3[2].setMinutesOpen(540);

	startRun1 = clock();
	algoritm(surgerys, rooms2Run1, 3);
	endRun1 = clock();

	startRun2 = clock();
	surgerys = sortMin(surgerys);
	algoritm(surgerys, rooms2Run2, 3);
	endRun2 = clock();


	startRun3 = clock();
	surgerys = sortMax(surgerys);
	algoritm(surgerys, rooms2Run3, 3);
	endRun3 = clock();

	cout << endl << "Run 1: " << endl << endl;
	printOperation(rooms2Run1, 3);
	cout << endl << endl << "Run 2: " << endl << endl;
	printOperation(rooms2Run2, 3);
	cout << endl << endl << "Run 3: " << endl << endl;
	printOperation(rooms2Run3, 3);

	cout << endl << endl << endl << "Time for the runs:" << endl;
	cout << "Run 1 : " << endRun1 - startRun1 << endl;
	cout << "Run 2 : " << endRun2 - startRun2 << endl;
	cout << "Run 3 : " << endRun3 - startRun3 << endl;
	
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
	for (int i = 0; i < surgerys.length(); i++) {
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




