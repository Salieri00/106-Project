/*  CS Project
    Beach Booking System
    Authors: Ahmed Badr, Shenawy, Nourhan Kamaly, Masa Tantawy
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Global Variables
const char FULL = '*';			//Seat taken
const char EMPTY = '#';         //Seat open
int LEAVE = 1;
const int rows = 15;			   //Number of rows
const int columns = 30;		   //Number of seats per row
char map[rows][columns];		 //Array to hold seating chart

class self_check {
public:
    bool fever;
    bool difficulity_breathing;
    bool cough;
    bool soar_throat;
    bool vomiting;
    bool loss_of_senses;
    bool covid_case;
};

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

void welcome()
{
    cout << "|\\     /|(  ____ \\( \\      ( \\      (  ____ \\(  ___  )(       )(  ____ \\\n"
        "| )   ( || (    \\/| (      | (      | (    \\/| (   ) || () () || (    \\/\n"
        "| | _ | || (__    | |      | |      | |      | |   | || || || || (__    \n"
        "| |( )| ||  __)   | |      | |      | |      | |   | || |(_)| ||  __)   \n"
        "| || || || (      | |      | |      | |      | |   | || |   | || (      \n"
        "| () () || (____/\\| (____/\\| (____/\\| (____/\\| (___) || )   ( || (____/\\\n"
        "(_______)(_______/(_______/(_______/(_______/(_______)|/     \\|(_______/\n"
        "                                                                        \n"
        "_________ _______    _______           _______ \n"
        "\\__   __/(  ___  )  (  ___  )|\\     /|(  ____ )\n"
        "   ) (   | (   ) |  | (   ) || )   ( || (    )|\n"
        "   | |   | |   | |  | |   | || |   | || (____)|\n"
        "   | |   | |   | |  | |   | || |   | ||     __)\n"
        "   | |   | |   | |  | |   | || |   | || (\\ (   \n"
        "   | |   | (___) |  | (___) || (___) || ) \\ \\__\n"
        "   )_(   (_______)  (_______)(_______)|/   \\__/\n"
        "                                               \n"
        " ______   _______  _______  _______          \n"
        "(  ___ \\ (  ____ \\(  ___  )(  ____ \\|\\     /|\n"
        "| (   ) )| (    \\/| (   ) || (    \\/| )   ( |\n"
        "| (__/ / | (__    | (___) || |      | (___) |\n"
        "|  __ (  |  __)   |  ___  || |      |  ___  |\n"
        "| (  \\ \\ | (      | (   ) || |      | (   ) |\n"
        "| )___) )| (____/\\| )   ( || (____/\\| )   ( |\n"
        "|/ \\___/ (_______/|/     \\|(_______/|/     \\|\n"
        "                                             \n"
        " _______  _______  _______  _______  _______  _______  _______ \n"
        "(  ____ )(  ____ )(  ___  )(  ____ \\(  ____ )(  ___  )(       )\n"
        "| (    )|| (    )|| (   ) || (    \\/| (    )|| (   ) || () () |\n"
        "| (____)|| (____)|| |   | || |      | (____)|| (___) || || || |\n"
        "|  _____)|     __)| |   | || | ____ |     __)|  ___  || |(_)| |\n"
        "| (      | (\\ (   | |   | || | \\_  )| (\\ (   | (   ) || |   | |\n"
        "| )      | ) \\ \\__| (___) || (___) || ) \\ \\__| )   ( || )   ( |\n"
        "|/       |/   \\__/(_______)(_______)|/   \\__/|/     \\||/     \\|\n"
        "                                                               ";

}

void time()
{
    // Declaring argument for time()
    time_t tt;

    // Declaring variable to store return value of
    // localtime()
    struct tm* ti;

    // Applying time()
    time(&tt);

    // Using localtime()
    ti = localtime(&tt);
    cout << endl << endl;
    cout << "Current Day, Date and Time is = "
        << asctime(ti);

}

//main menu function
int MainMenu() {
    int MenuChoice;
    cout << "\n\t\t\t\t Welcome Customer!";	 																					//Menu for the user
    cout << "\n\n\t\t\t\t <1> Reserve Seat";
    cout << "\n\t\t\t\t <2> Check Available Seats";
    cout << "\n\t\t\t\t <3> Return Ticket";
    cout << "\n\t\t\t\t <4> Exit \n";
    cout << "\t\t\t\t _____________________\n";
    cout << "\t\t\t\t Enter Your Choice :" << "\t";
    cin >> MenuChoice;
    return MenuChoice;
}

//funtion to show the seats
void Show_Map()
{
    cout << "Seats: ";
    cout << "\t  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30\n";

    for (int i = 0; i < 15; i++)
    {
        cout << endl << "Row " << (i + 1) << "\t";

        for (int j = 0; j < 30; j++)
        {
            cout << "  " << map[i][j];

        }
    }
    cout << endl;
}

//function to check the health status of the customer
string check_status(self_check A) {
    int symptoms = 0;
    //calculating how many symptoms the patient has
    if (A.fever) {
        symptoms++;
    }
    if (A.difficulity_breathing) {
        symptoms++;
    }
    if (A.cough) {
        symptoms++;
    }
    if (A.soar_throat) {
        symptoms++;
    }
    if (A.vomiting) {
        symptoms++;
    }
    if (A.loss_of_senses) {
        symptoms++;
    }
    if (A.covid_case) {
        symptoms++;
    }
    // the status of the customer
    if (symptoms > 3) {
        return "Highly Suspicious";
    }
    else if (symptoms > 0) {
        return "Suspicious";
    }
    else {
        return "Safe";
    }
}

//function to ask the customer for present symptoms
string health_check(self_check customer)
{
    string input;

    cout << "For each of the following itmes, choose whether you have recently experienced them or not.";
    cout << endl << endl;
    //Question 1
a:cout << " Fever, chills, or sweating." << setw(15) << "Yes/No" << endl;
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.fever = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.fever = false;
    }
    else {
        cout << "Invalid input"; goto a;
    }
    //Question 2
b:cout << "Difficulty breathing (e.g., struggling for each breath, speaking in single words)." << setw(15) << "Yes/No" << endl;
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.difficulity_breathing = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.difficulity_breathing = false;
    }
    else {
        cout << "Invalid input"; goto b;
    }
    //Question 3
c:cout << "New or worsening cough." << setw(15) << "Yes/No" << endl;
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.cough = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.cough = false;
    }
    else {
        cout << "Invalid input"; goto c;
    }
    //Question 4
d:cout << "Sore throat." << setw(15) << "Yes/No" << endl;
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.soar_throat = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.soar_throat = false;
    }
    else {
        cout << "Invalid input"; goto d;
    }
    //Question 5
e:cout << "Vomiting or Diarrhea" << setw(15) << "Yes/No" << endl;
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.vomiting = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.vomiting = false;
    }
    else {
        cout << "Invalid input"; goto e;
    }
    //Question 6
f:cout << "Sustained loss of smell, taste or appetite" << setw(15) << "Yes / No" << endl;
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.loss_of_senses = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.loss_of_senses = false;
    }
    else {
        cout << "Invalid input"; goto f;
    }
    //Question 7
g:cout << "Have you been within 6 feet (2 meters) of a COVID-19 case for 10 min or more in the last 2 weeks?" << setw(15) << "Yes / No" << endl;
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.covid_case = true;
    }
    else if (input == "No" || input == "no" || input == "N"|| input== "n") {
        customer.covid_case = false;
    }
    else {
        cout << "Invalid input"; goto g;
    }

    string status = check_status(customer);
    return status;
}

//Function that displays the type of seats
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
        perror("Error");
    }
}

//Function to store the client's details in a file
void putFiles(client person) {
    ofstream outfile;
    outfile.open("Client Data.txt");

    //writing the data to the file
    outfile << "Name: " << person.name << endl;
    outfile << "Age: " << person.age << endl;
    outfile << "Gender: " << person.gender << endl;
    outfile << "Phone Number: " << person.phone << endl;
    outfile << "Card Number: " << person.cardnumber << endl;
    outfile << "Expiry Date: " << person.expirydate << endl;
    outfile << "CVV: " << person.cvv << endl;

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



//-------------------------------------------MAIN FUNCTION-------------------------------
int main() {

    int UserRow, UserCol;
    welcome();
    time();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) { map[i][j] = EMPTY; }
    }
    int UserChoice;
    do {
        UserChoice = MainMenu();

        switch (UserChoice) {
        case 1:
            cout << "\n \n First, you will need to complete the self-check" << endl;
          
            do {
                //Self check part
                self_check Masa;
                Masa.fever = true;
                string status = health_check(Masa);

                if (status == "Highly Suspicious") {
                    cout << "COVID 19"; return 0;
                }
                else {
                    cout << endl<< endl<< "Your health status is: " << status << endl;
                }
                //Selecting the seat
                cout << "Reserving a seat...\n\n";

                cout << "Please select the row you would like to sit in: ";
                cin >> UserRow;
                cout << "Please select the column you would like to sit in: ";
                cin >> UserCol;

                if (map[UserRow - 1][UserCol - 1] == '*') {
                    cout << "Sorry that seat is sold-out, Please select a new seat.";
                    cout << endl;
                }
                else if (map[UserRow - 2][UserCol - 2] == '*' || map[UserRow][UserCol] == '*' ||
                    map[UserRow - 2][UserCol] == '*' || map[UserRow][UserCol - 2] == '*' || map[UserRow][UserCol - 1] == '*' || map[UserRow - 2][UserCol - 1] == '*' ||
                    map[UserRow - 1][UserCol - 2] == '*' || map[UserRow - 1][UserCol] == '*') {

                    cout << "We care about your health.\n";
                    cout << "A near by seat is reserved, and due to COVID-19, we cannot allow people to be sitting close.\n";
                    cout << "Please choose another seat\n\n";

                }
                else {
                     //displaying the types of seats
                    displaySeats();

                    int reserve;
                    cout << "please enter the seat you want to reserve: ";
                    cin >> reserve;
                    while (reserve < 1 || reserve > 8) {
                        cout << "please enter a valid number from 1 - 8: ";
                        cin >> reserve;
                    }


                    //the details of the client
                    client Nourhan;
                    string name;
                    char gender;
                    int card, cvvv, date, phone, age;

                    cout << "\n \n Now we will be taking your information to book the slot" << endl;
                    cout << "Please enter your first name :" << endl;
                    cin >> Nourhan.name;
                    cout << "Please enter your age :" << endl;
                    cin >> Nourhan.age;
                    cout << "Please enter your gender (M/F) :" << endl;
                    cin >> Nourhan.gender;

                    cout << "Now enter the Payment Details\n";

                    cout << "Please enter your credit card number (without spaces) :" << endl;
                    cin >> Nourhan.cardnumber;
                    cout << "Please enter the card's expiry date : " << endl;
                    cin >> Nourhan.expirydate;
                    cout << "Please enter the card's cvv :" << endl;
                    cin >> Nourhan.cvv;
                    cout << "Please enter your phone number :" << endl;
                    cin >> Nourhan.phone;

                    putFiles(Nourhan);

                    //confirming the reservation
                    cout << "\n\nAre you sure you want to reserve the seat at row no." << UserRow << " and column no." << UserCol << "?";
                    cout << "\t Yes <1>, No <0>\n"; cin >> LEAVE;
                    if (LEAVE == 0)
                        break;
                    cout << "Your seat reservation has been confirmed.\n\n" << endl;
                    map[UserRow - 1][UserCol - 1] = FULL;
                }

                cout << "Do you want to reserve another seat?   Yes <1>, No <0>";
                cin >> LEAVE;
            }                 while (LEAVE == 1);
            break;
        case 2:
            cout << "View Available Seats\n\n";
            Show_Map();
            break;
//cancelling the reservation
        case 3:
            int cancel;
        w:  cout << "Are you sure you want to cancel your reservation?\t" << "Yes <1> , No <0> \n";
            cin >> cancel;
            if (cancel == 1) {
                cout << "Please enter the row number the column number of you seat\n\n";
                cin >> UserRow >> UserCol;

                map[UserRow-1][UserCol-1] = EMPTY;
                cout << "Reservation cancelled successfully.\n";
            }
            else if (cancel == 0) {
                break;
            }
            else {
                cout << "Input Invalid.\n";
                goto w;
            }
            break;

        case 4:
            cout << "quitting\n";
            cout << "\nThank you for choosing our service!\n";
            break;

        default:
            cout << "Error input\n";
        }
    }         while (UserChoice != 4);

    return 0;
}
