#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

class client {                     //class client to save all the different components of clients
public:
	string name;
	int age;
	char gender;
	int phone;
	int cardnumber;
	int expirydate;
	int cvv;
};

void putFiles(client person) {                //function to put the client information in files
	ofstream outfile;                   //declare it as ofstream to write 
	outfile.open("Client Data.txt");

	outfile << "Name: "<<person.name << endl; 
	outfile << "Age: "<<person.age << endl;
	outfile << "Gender: "<<person.gender << endl;
	outfile << "Phone number: "<<person.phone << endl;
	outfile << "Credit card number: "<<person.cardnumber << endl;
	outfile << "Credit card expiry date: "<<person.expirydate << endl;
	outfile << "Credit card CVV: "<<person.cvv << endl;
	outfile << " Phone number :"<<person.phone<< endl;

	outfile.close();
	ifstream ifile; //to read 
	ifile.open("Client Data.txt");

	char ch;
	cout << endl << endl;
	while (!ifile.eof()) {           //read each character in the file and display it on the screen.
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
	cin >> Nourhan.name; //save it in the datatype Nourhan 
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

	putFiles(Nourhan);             //function call 


	return 0;
}
