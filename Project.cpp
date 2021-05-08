/*  CS Project
    Beach Booking System
    Authors: Ahmed Badr, Shenawy, Nourhan Kamaly, Masa Tantawy
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
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

    self_check() { //constructor that declares all variables to NULL
        fever = NULL;
        difficulity_breathing = NULL;
        cough = NULL;
        soar_throat = NULL;
        vomiting = NULL;
        loss_of_senses = NULL;
        covid_case = NULL;
    }

    ~self_check() = default;
};

class client {
public:
    string name;
    int age;
    char gender;
    int phone;
    int cardnumber;
    string expirydate;
    int cvv;

    client() { //constructor
        name = "";
        age = NULL;
        gender = NULL;
        phone = NULL;
        cardnumber = NULL;
        expirydate = "";
        cvv = NULL;
    }
    ~client() = default;  //destructor 
};

class ticket {
public:
    int VIP;
    double sprice;
    string stype;
    double discount;
    double wallet;

    ticket() {
        VIP = NULL;
        sprice = 0;
        discount = 0;
        wallet = 0;
    }
    ~ticket() = default;
};
//----------------------------------------Functions----------------------------------------

//Function to display Welcome
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

//Function to display current time
void showtime()
{
    // current date and time on the current system
    time_t now = time(0);

    // convert now to string form
    char* date_time = ctime(&now);

    cout << "\n\n\t\t\t\tThe current date and time is: " << date_time << endl;
}

//Main menu function
int MainMenu() {
    int MenuChoice;
    cout << "\n\t\t\t\t Welcome On Board :)"; 																					
    cout << "\n\n\t\t\t\t <1> Reserve Seat";
    cout << "\n\t\t\t\t <2> Check Available Seats";
    cout << "\n\t\t\t\t <3> Return Ticket";
    cout << "\n\t\t\t\t <4> Self Check";
    cout << "\n\t\t\t\t <5> Exit \n";
    cout << "\t\t\t\t _____________________\n";
    cout << "\t\t\t\t Enter Your Choice :" << "\t";
    cin >> MenuChoice;
    return MenuChoice;
}

//Function to log in
bool LogIn() {
    string userName;
    string userPassword;
    int loginAttempt = 0;

    do {
        cout << "\n\n\t\t\t\t-------------------------Log in-------------------------";

        cout << "\n\n\t\t\t\tPlease enter the user name:\t";
        getline(cin, userName);
        cout << "\n\t\t\t\tPlease enter the password:\t";
        getline(cin, userPassword);

        if (userName == "Selim" && userPassword == "CS106") {
            cout << "\n\t\t\t\tWelcome Selim!\n\n";
            return true;
        }
        else if (userName == "Dr Aya" && userPassword == "CSCS") {
            cout << "\n\t\t\t\tWelcome Dr Aya!\n\n";
            return true;
        }
        else {
            cout << "\n\n\t\t\t\tInvalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }

    } while (loginAttempt < 5);

    if (loginAttempt == 5) {
        cout << "\n\n\t\t\t\tToo many login attempts! The program will now terminate.";
        return false;
    }
}

//Funtion to show the seats
void Show_Map()
{
    cout << "\n\n\t\t\t\t\n";
    cout << "# Indicates an empty seat while * indicates a reserved seat.\n\n";
    cout << "Seats: ";
    cout << "\t  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n";

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

void map_empty() {
    //Making the map empty
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) { map[i][j] = EMPTY; }
    }
    map[1][1] = FULL;
    map[4][8] = FULL;
    map[2][5] = '*';
    map[10][15] = '*';
}
//Function to check the health status of the customer based on number of symptoms
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

//Health Check Questionnaire
string health_check(self_check customer)
{
    string input;

    cout << "\n\n\t\t\t\tFor each of the following items, choose whether you have recently experienced them or not.";
    cout << endl << endl;
    //Question 1
a:cout << "\n\t\t\t\tFever, chills, or sweating." << setw(15) << "Yes/No\t";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.fever = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.fever = false;
    }
    else {
        cout << "\n\n\t\t\t\tPlease choose yes or no" << endl; goto a;
    }
    //Question 2
b:cout << "\n\t\t\t\tDifficulty breathing (e.g., struggling for each breath, speaking in single words)." << setw(15) << "Yes/No\t";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.difficulity_breathing = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.difficulity_breathing = false;
    }
    else {
        cout << "\n\n\t\t\t\tPlease choose yes or no" << endl; goto b;
    }
    //Question 3
c:cout << "\n\t\t\t\tNew or worsening cough." << setw(15) << "Yes/No\t";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.cough = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.cough = false;
    }
    else {
        cout << "\n\n\t\t\t\tPlease choose yes or no" << endl; goto c;
    }
    //Question 4
d:cout << "\n\t\t\t\tSore throat." << setw(15) << "Yes/No\t";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.soar_throat = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.soar_throat = false;
    }
    else {
        cout << "\n\n\t\t\t\tPlease choose yes or no" << endl; goto d;
    }
    //Question 5
e:cout << "\n\t\t\t\tVomiting or Diarrhea" << setw(15) << "Yes/No\t";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.vomiting = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.vomiting = false;
    }
    else {
        cout << "\n\n\t\t\t\tPlease choose yes or no" << endl; goto e;
    }
    //Question 6
f:cout << "\n\t\t\t\tSustained loss of smell, taste or appetite" << setw(15) << "Yes / No\t";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.loss_of_senses = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.loss_of_senses = false;
    }
    else {
        cout << "\n\n\t\t\t\tPlease choose yes or no" << endl; goto f;
    }
    //Question 7
g:cout << "\n\t\t\t\tHave you been within 6 feet (2 meters) of a COVID-19 case for 10 min or more in the last 2 weeks?" << setw(15) << "Yes / No\t";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.covid_case = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.covid_case = false;
    }
    else {
        cout << "\n\n\t\t\t\tPlease choose yes or no" << endl; goto g;
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

    //writing the data to the file named Client Data 
    outfile << "Name: " << person.name << endl;
    outfile << "Age: " << person.age << endl;
    outfile << "Gender: " << person.gender << endl;
    outfile << "Phone Number: " << person.phone << endl;
    outfile << "Card Number: " << person.cardnumber << endl;
    outfile << "Expiry Date: " << person.expirydate << endl;
    outfile << "CVV: " << person.cvv << endl;

    outfile.close();
    ifstream ifile;    // read from file 
    ifile.open("Client Data.txt");

    char ch;
    cout << endl << endl;
    //displaying the contents of the file
    while (!ifile.eof()) { //while its not the end of the file
        ifile.get(ch);  //read each character
        cout << ch; //and display
    }

}


//-------------------------------------------MAIN FUNCTION-------------------------------
int main() {
    if (LogIn() == false)
    {
        exit(1);
    }

    int UserRow, UserCol, reserve;
    welcome();
    showtime();
    
    map_empty();

    int UserChoice;

    do {
        UserChoice = MainMenu();

        ticket Shenawy;
        switch (UserChoice) {
        case 1:
        {

            cout << endl << endl << setw(30) << "\n\n\t\t\t\tSTEP ONE";
            cout << "\n\n\t\t\t\tFirst, you will need to complete the self-check." << endl;

            //Self check part
            self_check customer;
            string status = health_check(customer);

            if (status == "Highly Suspicious") {
                cout << "\n\n\t\t\t\tUnfortunately, you have too many symptoms.";
                cout << "\n\t\t\t\tFor your own safety and those around you, you will need to isolate yourself.";
                cout << "\n\t\t\t\tWe apologize. You won't be able to reserve a seat." << endl;
                return 0;
            }
            if (status == "Suspicious") {
                cout << "\n\n\t\tYour health status is: " << status << ".";
                cout << "\n\t\t\t\tFor your own safety and those around you, please repeat the self-check after 7 days.";
                cout << "\n\t\t\t\tYou will be able to reserve a seat for now.";
            }
            else {
                cout << endl << endl << "\n\n\t\t\t\tYour health status is: " << status;
                cout << "\n\t\t\t\tYou will be able to reserve a seat.";
            }
        }
        do {
            //Selecting a seat
            cout << endl << endl << setw(30) << "\n\n\t\t\t\tSTEP TWO";
            cout << "\n\n\t\t\t\tSelecting a seat...";

            //displaying the map
            Show_Map();

            cout << endl << "\n\n\t\t\t\tPlease select the row you would like to sit in:\t";
            cin >> UserRow;
            cout << endl << "\n\n\t\t\t\tPlease select the column you would like to sit in:\t";
            cin >> UserCol;
            cout << endl;

            if (map[UserRow - 1][UserCol - 1] == '*') {
                cout << "\n\n\t\t\t\tSorry that seat is sold-out, Please select a new seat.";
                cout << endl;
            }
            else if (map[UserRow - 2][UserCol - 2] == '*' || map[UserRow][UserCol] == '*' ||
                map[UserRow - 2][UserCol] == '*' || map[UserRow][UserCol - 2] == '*' || map[UserRow][UserCol - 1] == '*' || map[UserRow - 2][UserCol - 1] == '*' ||
                map[UserRow - 1][UserCol - 2] == '*' || map[UserRow - 1][UserCol] == '*') {

                cout << "\n\n\t\t\t\tWe care about your health. ";
                cout << "A near by seat is reserved, and due to COVID-19, we cannot allow people to be sitting close.";
                cout << "\n\t\t\t\tPlease choose another seat\n\n";

            }
            else {
                //displaying the types of seats
                displaySeats();

                cout << endl << "\n\n\t\t\t\tPlease enter the seat you want to reserve:\t";
                cin >> reserve;
                while (reserve < 1 || reserve > 8) {
                    cout << endl << "\n\n\t\t\t\tPlease enter a valid number from 1 - 8:\t";
                    cin >> reserve;
                }


                switch (reserve) {
                case (1):
                    Shenawy.sprice += 2800;
                    Shenawy.stype = "Floating beach lounger without umbrella"; break;
                case (2):
                    Shenawy.sprice += 3000;
                    Shenawy.stype = "Floating beach lounger with umbrella"; break;
                case (3):
                    Shenawy.sprice += 2000;
                    Shenawy.stype += "Foldable beach chair without umbrella"; break;
                case (4):
                    Shenawy.sprice += 2200;
                    Shenawy.stype = "Foldable beach chair with umbrella"; break;
                case (5):
                    Shenawy.sprice += 650;
                    Shenawy.stype = "Ariika Malibu folding cahir without umbrella"; break;
                case (6):
                    Shenawy.sprice += 850;
                    Shenawy.stype = "Ariika Malibu folding cahir with umbrella"; break;
                case (7):
                    Shenawy.sprice += 450;
                    Shenawy.stype = "Portable leisure wood chair without umbrella"; break;

                case (8):
                    Shenawy.sprice += 650;
                    Shenawy.stype = "Portable leisure wood chair with umbrella"; break;
                }

                //confirming the reservation
                cout << "\n\n\t\t\t\tAre you sure you want to reserve the seat at row no." << UserRow << " and column no." << UserCol << "?";
                cout << "\tYes <1>, No <0>\n"; cin >> LEAVE;
                if (LEAVE == 0)
                    break;
                cout << "\n\t\t\t\tSeat added to your cart.\n\n" << endl;
                map[UserRow - 1][UserCol - 1] = FULL;
            }

            cout << "\n\n\t\t\t\tDo you want to reserve another seat?";
            cout << "\tYes <1>, No <0>\n";
            cin >> LEAVE;
        } while (LEAVE == 1);

        {
            //the details of the client
            client info;

            cout << "\n\n\t\t\t\tNow we will be taking your information to book the slot.";
            
            
            //Question 1
        h: cout << "\n\t\t\t\tPlease enter your full name :\t";
            string first_name, last_name;
            cin >> first_name >> last_name;

            string alpha= first_name + ' ' + last_name;
            
            // meaning of unsigned is a datatype that only shows non-negative integers
            for (unsigned s = 0; s < alpha.length(); s++) { //loop over letters to find if all letters or not and if it is space its accepted   
                if (!isalpha(alpha[s]) && alpha[s] != ' ') {
                    cin.clear();
                    cout << "Invalid input" << endl;
                    goto h;
                }
            }
            info.name = alpha; //saves the name in info.name

            //Question 2
            string j;
        i: cout << "\n\t\t\t\tPlease enter your age:\t";
            cin >> j;
            for (int i = 0; i < j.length(); i++) {  //isdigit works with string... loop over the string
                if (!isdigit(j[i])) {
                    cin.clear();
                    cout << "\n\t\t\t\tInvalid input";
                    goto i;
                }
            }
            info.age = stoi(j); //redefine to store it in Nourhan.age from string to int 

            //Question 3
        j:cout << "\n\t\t\t\tPlease enter your gender (M/F):\t";
            char gen = ' ';
            cin >> gen;
            info.gender = gen;
            if (!(gen == 'M' || gen == 'm' || gen == 'F' || gen == 'f')) {
                cin.clear();
                cout << "\n\t\t\t\tInvalid input" << endl;
                goto j;
            }

            //Question 4
        k:cout << "\n\t\t\t\tPlease enter your phone number:\t";
            string ph;
            cin >> ph;
            for (int i = 0; i < ph.length(); i++) {
                if (!isdigit(ph[i])) {
                    cin.clear();
                    cout << "\n\t\t\t\tInvalid input" << endl;
                    goto k;
                }
            }
            info.phone = stoi(ph);

            //Question 5
        l:cout << "\n\t\t\t\tPlease enter your credit card number (without spaces):\t";
            string num;
            cin >> num;
            for (int i = 0; i < num.length(); i++) {
                if (!isdigit(num[i])) {
                    cin.clear();
                    cout << "\n\t\t\t\tInvalid input";
                    goto l;
                }
            }
            info.cardnumber = stoi(num);

            //Question 6
        z:cout << "\n\t\t\t\tPlease enter the month of the expiry date on the card: \t";
            int month;
            cin >> month;
            if (month > 12) {  //validate the month
                cout << "\n\t\t\t\tPlease enter the right month" << endl;
                goto z; //repeat the question
            }
            cout << "\n\t\t\t\tPlease enter the year of the expiry date on the card: \t";
            int year;
            cin >> year;
            string month_ = to_string(month); //convert from int to string 
            string year_ = to_string(year);
            string dat;
            dat = month_ + '/' + year_; //add all categories of expiry date to this variable
            info.expirydate = dat; //save it in class

         //Question 7
        n:cout << "\n\t\t\t\tPlease enter the card's cvv:\t";
            string cv;
            cin >> cv;
            for (int i = 0; i < cv.length(); i++) {
                if (!isdigit(cv[i])) {
                    cin.clear();
                    cout << "\n\t\t\t\tInvalid input";
                    goto n;
                }
            }
            info.cvv = stoi(cv);
            putFiles(info);             //function call 

            do {
                cout << "\n\t\t\t\tAre you a VIP client?\t <1>:Yes\t<0>:No\t";
                cin >> Shenawy.VIP;
            } while (!(Shenawy.VIP == 0 || Shenawy.VIP == 1));

            if (Shenawy.VIP == 1) {
                cout << "\n\n\t\t\t\tDrinks and food on da house ;)";
            }
            cout << "\n\n\t\t\t\tYour seat reservation has been confirmed.\n\n";
        }

        if (Shenawy.sprice >= 2000) {
            cout << "\n\n\t\t\t\tYour payment is over 2000 EGP.";
            cout << "\n\n\t\t\t\tCompliment from the Manager Shenawy- you are a special client.";
            cout << "\n\n\t\t\t\tWoho you got a 20% discount!";
            Shenawy.discount += 0.2;
        }

        // ---------------------------------------BILL:---------------------------------------
        {
            ifstream file;
            file.open("Client Data.txt");

            cout << "\n\n\t\t\t\tBILL:";
            cout << "\n\n\t\t\t\t";
            for (int i = 0; i < 10; i++) {
                string word;
                file >> word;
                cout << word << " ";
            }
        }
        cout << "\n\t\t\t\tSeat Type:\t" << Shenawy.stype;
        cout << "\n\t\t\t\tSeat Location:\t" << "Row: " << UserRow << "\t" << "Column: " << UserCol << endl;
        cout << "\n\n\t\t\t\tPrice:\t" << fixed << setprecision(2) << Shenawy.sprice * (1 - Shenawy.discount) << endl;
        cout << "\n\n\t\t\t\tWising you a restful vacation and hope you enjoy your visit!";
        cout << "\n\n\n";
        break;

        case 2:
            cout << "\n\n\t\t\t\tView Available Seats\n\n";
            Show_Map();
            break;


        case 3://cancelling the reservation
            int cancel;
        w:  cout << "\n\n\t\t\t\tAre you sure you want to cancel your reservation?\t" << "Yes <1> , No <0> \n";
            cin >> cancel;
            if (cancel == 1) {
                
                map_empty();

                Shenawy.wallet += Shenawy.sprice;

                cout << "\n\t\t\t\tReservation cancelled successfully.\n";
                cout << "\n\t\t\t\tYour wallet now contains: " << Shenawy.wallet;
            }
            else if (cancel == 0) {
                break;
            }
            else {
                cout << "\n\n\t\t\t\tPlease choose one of the available options.";
                goto w;
            }
            break;

        case 4:
        {
            //Self check part
            self_check customer;
            string status = health_check(customer);

            if (status == "Highly Suspicious") {
                cout << "\n\n\t\t\t\tUnfortunately, you have too many symptoms.";
                cout << "\n\t\t\t\tFor your own safety and those around you, you will need to isolate yourself.";
                cout << "\n\t\t\t\tWe apologize. You won't be able to reserve a seat." << endl;
                return 0;
            }
            if (status == "Suspicious") {
                cout << "\n\n\t\tYour health status is: " << status << ".";
                cout << "\t\tFor your own safety and those around you, please repeat the self-check after 7 days.";
                cout << "\t\tYou will be able to reserve a seat for now.";
            }
            else {
                cout << endl << endl << "\n\n\t\t\t\tYour health status is: " << status;
                cout << "\t\tYou will be able to reserve a seat.";
            }
        }
        break;

        case 5:
            cout << "\n\n\t\t\t\tQuitting";
            cout << "\n\t\t\t\tThank you for choosing our service!";
            break;

        default:
            cout << "\n\t\t\t\tInvalid input\n";
        }
    } while (UserChoice != 5);

    return 0;
}
