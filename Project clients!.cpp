//files each client has their own file
//age, gender, name,phone number, card number,expiry date,CVV, 
//display the user's bill 
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
void putFiles(string x_name, int x_age, char x_gender, int p, int x_cardnumber, int x_expirydate, int x_cvv);
void putFiles(string x_name, int x_age, char x_gender, int p, int x_cardnumber, int x_expirydate, int x_cvv) {
	fstream outfile;
	client person;
	x_name = person.name;
	x_age = person.age;
	x_gender = person.gender;
	p = person.phone;
	x_cvv = person.cvv;
	x_cardnumber = person.cardnumber;
	x_expirydate = person.expirydate;
	outfile << person.name;
	outfile << person.age;
	outfile << person.gender;
	outfile << person.phone;
	outfile << person.cardnumber;
	outfile << person.expirydate;
	outfile << person.cvv;
	char ch;
	while (!outfile.eof()) {
		outfile.get(ch);
		cout << ch;
	}
	outfile.close();
}
int main() {
	string name;
	char gender;
	int card,cvvv,date,phone,age;
	cout << " Now we will be taking your information to book the slot" << endl;
	cout << "Please enter your first name :" << endl;
	cin >> name;
	cout << "Please enter your age :" << endl;
	cin >> age;
	cout << "Please enter your gender (M/F) :" << endl;
	cin >> gender;
	cout << "Please enter your credit card number (without spaces) :" << endl;
	cin >> card;
	cout << "Please enter the card's expiry date : " << endl;
	cin >> date;
	cout << "Please enter the card's cvv :" << endl;
	cin >> cvvv;
	cout << "Please enter your phone number :" << endl;
	cin >> phone;
	putFiles(name, age, gender, phone, card, date, cvvv);
}
