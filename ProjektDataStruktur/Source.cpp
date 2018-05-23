#include <iostream>
#include <string>
#include "Surgery.h"
#include "SurgeryRoom.h"
using namespace std;
int main() {
	cout << "Welcome cunt! <3 " << endl;

	SurgeryRoom room(1,600);
	if (room.addSurgery(Surgery(1, "Sinus", 500))) {
		cout << "Works" << endl;
	}
	if (!room.addSurgery(Surgery(1, "Sinus", 500))) {
		cout << "Works" << endl;
	}
	if (room.addSurgery(Surgery(1, "Sinus", 100))) {
		cout << "Works" << endl;
	}
}

void readFromFile(int array[]) {

}




void printOperation() {

}