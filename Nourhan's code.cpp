#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include<cctype>
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

	client() {  //constructor initialize all to NULL
		name = "";
		gender = NULL;
		age = NULL;
		cardnumber = NULL;
		expirydate = NULL;
		cvv = NULL;
		phone = NULL;
	}
};

void putFiles(client person) {           //function to put the client information in files
	ofstream outfile;                   //declare it as ofstream to write 
	outfile.open("Client Data.txt");

	outfile << "Name: " << person.name << endl;
	outfile << "Age: " << person.age << endl;
	outfile << "Gender: " << person.gender << endl;
	outfile << "Phone number: " << person.phone << endl;
	outfile << "Credit card number: " << person.cardnumber << endl;
	outfile << "Credit card expiry date: " << person.expirydate << endl;
	outfile << "Credit card CVV: " << person.cvv << endl;

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
	cout << "Now we will be taking your information to book the slot" << endl;
	//Question 1
a: cout << "Please enter your first name :" << endl;
	cin >> Nourhan.name;
	string alpha;
	alpha = Nourhan.name;
	for (unsigned s = 0; s < alpha.length(); s++) { //loop over letters to find if all letters or not
		if (!isalpha(alpha[s])) {
			cin.clear();
			cout << "Invalid input" << endl;
			goto a;
		}
	}
	//Question 2
	string j;
b: cout << "Please enter your age" << endl;
	cin >> j;
	for (int i = 0; i < j.length(); i++) {  //isdigit works with string... loop over the string
		if (!isdigit(j[i])) {
			cin.clear();
			cout << "Invalid input" << endl;
			goto b;
		}
	}
	Nourhan.age = stoi(j); //redefine to store it in Nourhan.age from string to int 
	//Question 3
c:cout << "Please enter your gender (M/F) :" << endl;
	char gen = ' ';
	cin >> gen;
	Nourhan.gender = gen;
	if (!(gen == 'M' || gen == 'm' || gen == 'F' || gen == 'f')) {
		cin.clear();
		cout << "Invalid input" << endl;
		goto c;
	}
	//Question 4
d:cout << "Please enter your phone number :" << endl;
	string ph;
	cin >> ph;
	for (int i = 0; i < ph.length(); i++) {
		if (!isdigit(ph[i])) {
			cin.clear();
			cout << "Invalid input" << endl;
			goto d;
		}
	}
	Nourhan.phone = stoi(ph);
	//Question 5
e:cout << "Please enter your credit card number (without spaces) :" << endl;
	string num{}; {};
	cin >> num;
	for (int i = 0; i < num.length(); i++) {
		if (!isdigit(num[i])) {
			cin.clear();
			cout << "Invalid input" << endl;
			goto e;
		}
	}
	Nourhan.cardnumber = stoi(num);
	//Question 6
f: cout << "Please enter the card's expiry date : " << endl;
	string dat{};
	cin >> dat;
	for (int i = 0; i < dat.length(); i++) {
		if (!isdigit(dat[i])) {
			cin.clear();
			cout << "Invalid input" << endl;
			goto f;
		}
	}
	Nourhan.expirydate = stoi(dat);
	//Question 7
g:cout << "Please enter the card's cvv :" << endl;
	string cv;
	cin >> cv;
	for (int i = 0; i < cv.length(); i++) {
		if (!isdigit(cv[i])) {
			cin.clear();
			cout << "Invalid input" << endl;
			goto g;
		}
	}
	Nourhan.cvv = stoi(cv);

	putFiles(Nourhan);             //function call 

	return 0;
}
