#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
const char FULL = '*';			//Seat taken
const char EMPTY = '#';         //Seat open
int LEAVE = 1;
const int rows = 15;			   //Number of rows
const int columns = 30;		   //Number of seats per row
char map [rows][columns];		 //Array to hold seating chart
void welcome ()
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

void time ()
{
    // Declaring argument for time()
    time_t tt;

    // Declaring variable to store return value of
    // localtime()
    struct tm * ti;

    // Applying time()
    time (&tt);

    // Using localtime()
    ti = localtime(&tt);
    cout << endl << endl;
    cout << "Current Day, Date and Time is = "
         << asctime(ti);

}
int MainMenu (){
    int MenuChoice;
    cout<<"\n\t\t\t\t Welcome Customer!";	 																					//Menu for the user
    cout<<"\n\n\t\t\t\t <1> Reserve Seat";
    cout<<"\n\t\t\t\t <2> Check Available Seats";
    cout<<"\n\t\t\t\t <3> Return Ticket";
    cout<<"\n\t\t\t\t <4> Exit \n";
    cout << "\t\t\t\t _____________________\n";
    cout<<"\t\t\t\t Enter Your Choice :"<<"\t";
    cin >> MenuChoice;
    return MenuChoice;
}

void Show_Map ()
{
    cout << "Seats: ";
    cout << "\t1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n";

    for (int i = 0; i < 15; i++)
    {
        cout << endl << "Row " << (i + 1) << "\t";

        for (int j = 0; j < 30; j++)
        {
            cout << " " <<  map [i] [j];

        }
    }
    cout << endl;
}

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
                cout << "Reserving a seat...\n\n";
                do {
                    cout << "Please select the row you would like to sit in: ";
                    cin >> UserRow;
                    cout << "Please select the column you would like to sit in: ";
                    cin >> UserCol;

                    if (map[UserRow][UserCol] == '*') {
                        cout << "Sorry that seat is sold-out, Please select a new seat.";
                        cout << endl;
                    }
                    else if (map[UserRow + 1][UserCol] == '*' || map[UserRow][UserCol + 1] == '*' ||
                               map[UserRow - 1][UserCol] == '*' || map[UserRow][UserCol - 1] == '*') {
                        cout << "We care about your health.\n\n";
                        cout << "A near by seat is reserved, and due to COVID-19, we cannot allow people to be sitting close.\n";
                        cout << "Please choose another seat\n\n";

                    }
                    else {
                        cout << "File Shit\n\n";
                        cout << "\n\nAre you sure you want to reserve the seat at row no." << UserRow << " and column no." << UserCol << "?";
                        cout <<"\t Yes <1>, No <0>\n"; cin >> LEAVE;
                        if (LEAVE == 0)
                            break;
                        cout << "Your seat reservation has been confirmed.\n\n" << endl;
                        map[UserRow - 1][UserCol - 1] = FULL;
                        }

                    cout << "Do you want to reserve another seat?   Yes <1>, No <0>";
                    cin >> LEAVE;
                }
                while (LEAVE == 1 );
                break;
            case 2:
                cout << "View Available Seats\n\n";
                Show_Map();
                break;

            case 3:
                int cancel;
                cout << "Are you sure you want to cancel your reservation?\t" << "Yes <1> , No <0> \n";
            w:
                cin >> cancel;
                if (cancel == 1) {
                    cout << "Please enter the row number the column number of you seat\n\n";
                    cin >> UserRow >> UserCol;

                    map[UserRow][UserCol] = EMPTY;
                    cout << "Reservation cancelled successfully.\n";
                } else if (cancel == 0) {
                    break;
                } else {
                    cout << "Input Invalid.\n";
                    goto w;
                }
                break;

            case 4:
                cout << "quit\n";
                cout << "\nThank you for choosing our service!\n";
                break;

            default:
                cout << "Error input\n";
        }
    }
        while (UserChoice != 4);


        return 0;

}