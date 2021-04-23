#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

class client {
public:
	string name;
	int age;
	char gender;
	int phone;
	int cardnumber;
	int expirydate;
	int cvv;
};

void putFiles(client person) {
	ofstream outfile;
	outfile.open("Client Data.txt");

	outfile << "Name: "<<person.name << endl;
	outfile << "Age: "person.age << endl;
	outfile << person.gender << endl;
	outfile << person.phone << endl;
	outfile << person.cardnumber << endl;
	outfile << person.expirydate << endl;
	outfile << person.cvv << endl;
	outfile << person.phone<< endl;

	outfile.close();
	ifstream ifile;
	ifile.open("Client Data.txt");

	char ch;
	cout << endl << endl;
	//displaying the contents of the file
	while (!ifile.eof()) {
		ifile.get(ch);
		cout << ch;
	}

	outfile.close();
}

int main() {
	client Nourhan;
	string name;
	char gender;
	int card, cvvv, date, phone, age;

	cout << "Now we will be taking your information to book the slot" << endl;
		cout << "Please enter your first name :" << endl;
	cin >> Nourhan.name;
	cout << "Please enter your age :" << endl;
	cin >> Nourhan.age;
	cout << "Please enter your gender (M/F) :" << endl;
	cin >> Nourhan.gender;
	cout << "Please enter your credit card number (without spaces) :" << endl;
	cin >> Nourhan.cardnumber;
	cout << "Please enter the card's expiry date : " << endl;
	cin >> Nourhan.expirydate;
	cout << "Please enter the card's cvv :" << endl;
	cin >> Nourhan.cvv;
	cout << "Please enter your phone number :" << endl;
	cin >> Nourhan.phone;

	putFiles(Nourhan);

	cout << "Coutaya malhash lazma";


	return 0;
}
