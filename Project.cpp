
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

    self_check() { //constructor that declares all variables to NULL
        fever = NULL;
        difficulity_breathing = NULL;
        cough= NULL;
        soar_throat= NULL;
        vomiting= NULL;
        loss_of_senses= NULL;
        covid_case= NULL;
    }
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

    client() { //constructor
        name = "";
        age = NULL;
        gender = NULL;
        phone = NULL;
        cardnumber = NULL;
        expirydate = NULL;
        cvv = NULL;
    }
};

class ticket {
    public:
        int VIP;
        double sprice;
        string stype;
        double discount;
        int wallet;

        ticket() {
            VIP = NULL;
            sprice = 0;
            discount = 0;
            wallet = 0;
        }
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
/* void time()
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

}*/

//Main menu function
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

//Function to log in
bool LogIn() {
    string userName;
    string userPassword;
    int loginAttempt = 0;

    do {
        cout << "\t-------------------------Log in-------------------------" << endl;

        cout << "Please enter your user name then password: " << endl;
        getline(cin, userName);
        cin>> userPassword;

        if (userName == "Selim" && userPassword == "CS106") {
            cout << "Welcome Selim!\n";
            return true;
        }
        else if (userName == "Dr Aya" && userPassword == "CSCS") {
            cout << "Welcome Dr Aya!\n";
            return true;
        }
        else {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }

    } while (loginAttempt < 5);

    if (loginAttempt == 5) {
        cout << "Too many login attempts! The program will now terminate.";
        return false;
    }
}

//Funtion to show the seats
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

    cout << "\n\n\tFor each of the following items, choose whether you have recently experienced them or not.";
    cout << endl << endl;
    //Question 1
a:cout << "  Fever, chills, or sweating." << setw(15) << "Yes/No" << "\n\n";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.fever = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.fever = false;
    }
    else {
        cout << "Please choose yes or no" << endl; goto a;
    }
    //Question 2
b:cout << "  Difficulty breathing (e.g., struggling for each breath, speaking in single words)." << setw(15) << "Yes/No" << "\n\n";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.difficulity_breathing = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.difficulity_breathing = false;
    }
    else {
        cout << "Please choose yes or no" << endl; goto b;
    }
    //Question 3
c:cout << "  New or worsening cough." << setw(15) << "Yes/No" << "\n\n";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.cough = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.cough = false;
    }
    else {
        cout << "Please choose yes or no" << endl; goto c;
    }
    //Question 4
d:cout << "  Sore throat." << setw(15) << "Yes/No" << "\n\n";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.soar_throat = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.soar_throat = false;
    }
    else {
        cout << "Please choose yes or no" << endl; goto d;
    }
    //Question 5
e:cout << "  Vomiting or Diarrhea" << setw(15) << "Yes/No" << "\n\n";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.vomiting = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.vomiting = false;
    }
    else {
        cout << "Please choose yes or no" << endl; goto e;
    }
    //Question 6
f:cout << "  Sustained loss of smell, taste or appetite" << setw(15) << "Yes / No" << "\n\n";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.loss_of_senses = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.loss_of_senses = false;
    }
    else {
        cout << "Please choose yes or no" << endl; goto f;
    }
    //Question 7
g:cout << "  Have you been within 6 feet (2 meters) of a COVID-19 case for 10 min or more in the last 2 weeks?" << setw(15) << "Yes / No" << "\n\n";
    cin >> input;

    if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
        customer.covid_case = true;
    }
    else if (input == "No" || input == "no" || input == "N" || input == "n") {
        customer.covid_case = false;
    }
    else {
        cout << "Please choose yes or no" << endl; goto g;
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

}


//-------------------------------------------MAIN FUNCTION-------------------------------
int main() {
    if (LogIn() == false)
    {
        exit(1);
    }

    int UserRow, UserCol;
    welcome();
    //time();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) { map[i][j] = EMPTY; }
    }
    int UserChoice;
    

    do {
        UserChoice = MainMenu();

        ticket Shenawy;
        switch (UserChoice) {
        case 1:
        {

            cout << endl << endl << setw(30) << "STEP ONE\n";
            cout << "\n\n\t\tFirst, you will need to complete the self-check." << endl;

            //Self check part
            self_check customer;
            string status = health_check(customer);

            if (status == "Highly Suspicious") {
                cout << "\n\n\t\t Unfortunately, you have too many symptoms." << endl;
                cout << "\t\tFor your own safety and those around you, you will need to isolate yourself." << endl;
                cout << "\t\tWe apologize. You won't be able to reserve a seat." << endl;
                return 0;
            }
            if (status == "Suspicious") {
                cout << "\n\n\t\tYour health status is: " << status << "." << endl;
                cout << "\t\tFor your own safety and those around you, please repeat the self-check after 7 days." << endl;
                cout << "\t\tYou will be able to reserve a seat for now." << endl;
            }
            else {
                cout << endl << endl << "Your health status is: " << status << endl;
            }
        }
            do {
                //Selecting a seat
                cout << endl << endl << setw(30) << "STEP TWO\n";
                cout << "\nSelecting a seat...\n\n";

                //displaying the map
                Show_Map();

                cout << endl<<"Please select the row you would like to sit in: ";
                cin >> UserRow;
                cout << endl<<"Please select the column you would like to sit in: ";
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
                    cout << endl<<"please enter the seat you want to reserve: ";
                    cin >> reserve;
                    while (reserve < 1 || reserve > 8) {
                        cout << endl<<"please enter a valid number from 1 - 8: ";
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

                    //the details of the client
                    client Nourhan;

                    cout << "\n \n Now we will be taking your information to book the slot" << endl;
                    
                    //Question 1
                h: cout << "Please enter your first name :" << endl;
                    cin >> Nourhan.name;
                    string alpha;
                    alpha = Nourhan.name;
                    for (unsigned s = 0; s < alpha.length(); s++) { //loop over letters to find if all letters or not
                        if (!isalpha(alpha[s])) {
                            cin.clear();
                            cout << "Invalid input" << endl;
                            goto h;
                        }
                    }
                    //Question 2
                    string j;
                i: cout << "Please enter your age" << endl;
                    cin >> j;
                    for (int i = 0; i < j.length(); i++) {  //isdigit works with string... loop over the string
                        if (!isdigit(j[i])) {
                            cin.clear();
                            cout << "Invalid input" << endl;
                            goto i;
                        }
                    }
                    Nourhan.age = stoi(j); //redefine to store it in Nourhan.age from string to int 
                    //Question 3
                j:cout << "Please enter your gender (M/F) :" << endl;
                    char gen = ' ';
                    cin >> gen;
                    Nourhan.gender = gen;
                    if (!(gen == 'M' || gen == 'm' || gen == 'F' || gen == 'f')) {
                        cin.clear();
                        cout << "Invalid input" << endl;
                        goto j;
                    }
                    //Question 4
                k:cout << "Please enter your phone number :" << endl;
                    string ph;
                    cin >> ph;
                    for (int i = 0; i < ph.length(); i++) {
                        if (!isdigit(ph[i])) {
                            cin.clear();
                            cout << "Invalid input" << endl;
                            goto k;
                        }
                    }
                    Nourhan.phone = stoi(ph);
                    //Question 5
                l:cout << "Please enter your credit card number (without spaces) :" << endl;
                    string num{}; {};
                    cin >> num;
                    for (int i = 0; i < num.length(); i++) {
                        if (!isdigit(num[i])) {
                            cin.clear();
                            cout << "Invalid input" << endl;
                            goto l;
                        }
                    }
                    Nourhan.cardnumber = stoi(num);
                    //Question 6
                m: cout << "Please enter the card's expiry date : " << endl;
                    string dat{};
                    cin >> dat;
                    for (int i = 0; i < dat.length(); i++) {
                        if (!isdigit(dat[i])) {
                            cin.clear();
                            cout << "Invalid input" << endl;
                            goto m;
                        }
                    }
                    Nourhan.expirydate = stoi(dat);
                    //Question 7
                n:cout << "Please enter the card's cvv :" << endl;
                    string cv;
                    cin >> cv;
                    for (int i = 0; i < cv.length(); i++) {
                        if (!isdigit(cv[i])) {
                            cin.clear();
                            cout << "Invalid input" << endl;
                            goto n;
                        }
                    }
                    Nourhan.cvv = stoi(cv);
                    putFiles(Nourhan);             //function call 

                    do {
                        cout << "Are you a VIP client?\t <1>:Yes\t<0>:No\t";
                        cin >> Shenawy.VIP;
                    } while (!(Shenawy.VIP == 0 || Shenawy.VIP == 1));

                    if (Shenawy.VIP == 1) {
                        cout << "\nDrinks and Food are included in the ticket price";
                    }

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
            } while (LEAVE == 1);
            
            if (Shenawy.sprice >= 2000) {
                Shenawy.discount += 0.2;
            }

// ---------------------------------------BILL:---------------------------------------
            {
                ifstream file;
                file.open("Client Data.txt");

                cout << "\n\nBILL:\n";
                for (int i = 0; i < 8; i++) {
                    char c;
                    file.get(c);
                    cout << c;
            }
            }
            cout << endl;
            cout << "Seat Type:\t"<<Shenawy.stype;
            cout << "Seat Location:\t" << "Row: " << UserRow << "\t" << "Column: " << UserCol << endl;
            cout << "Price:\t" << fixed<<setprecision(2)<<Shenawy.sprice * (1 - Shenawy.discount) << endl;
            cout << "Wising you a restful vacation and hope you enjoy your visit!";
            break;

        case 2:
            cout << "View Available Seats\n\n";
            Show_Map();
            break;

            
        case 3://cancelling the reservation
            int cancel;
        w:  cout << "Are you sure you want to cancel your reservation?\t" << "Yes <1> , No <0> \n";
            cin >> cancel;
            if (cancel == 1) {
                cout << "Please enter the row number the column number of you seat\n\n";
                cin >> UserRow >> UserCol;
                
                map[UserRow - 1][UserCol - 1] = EMPTY;

                Shenawy.wallet += Shenawy.sprice;

                cout << "Reservation cancelled successfully.\n";
                cout << "Your wallet now contains: " << Shenawy.wallet;
            }
            else if (cancel == 0) {
                break;
            }
            else {
                cout << "Please choose one of the available options .\n";
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
    } while (UserChoice != 4);

    return 0;
}
