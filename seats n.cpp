#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*class seat {
public:
	string type;
	double price;
};*/

void displaySeats()
{
	char getcontent;
	ifstream datafile("t and p.txt");
	if (datafile.is_open()) {
		while (!datafile.eof()) {
			datafile.get(getcontent);
			cout << getcontent;
		}
	}
	else {
		cout << "file unvalid";
	}
}


int main() {

	displaySeats();

	int reserve;
	cout << "please enter the seat you want to reserve: ";
	cin >> reserve;
	while (reserve < 1 || reserve > 8) {
		cout << "please enter a valid number from 1 - 8: ";
		cin >> reserve;
	}


}