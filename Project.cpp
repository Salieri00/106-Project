// Project

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//-----------------------------------------Self-check----------------------------------------------------

struct self_check {
    bool fever;
    bool difficulity_breathing;
    bool cough;
    bool soar_throat;
    bool vomiting;
    bool loss_of_senses;
    bool covid_case;
};
 
//function to check the health of the customer
string check_health(self_check A) {
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

string health_check(self_check customer)
{
    string input;
   
    cout << "For each of the following itmes, choose whether you have recently experienced them or not.";
    cout << endl << endl;
    //Question 1
    a:cout<< " Fever, chills, or sweating."<< setw(15)<< "Yes/No" <<endl;
    cin >> input;
    
    if (input == "Yes" || input == "yes") {
        customer.fever = true;
    }
    else if(input=="No" || input == "no"){
        customer.fever = false;
    }
    else {
        cout << "Invalid input"; goto a;
    }
    //Question 2
    b:cout << "Difficulty breathing (e.g., struggling for each breath, speaking in single words)." << setw(15) << "Yes/No" << endl;
    cin >> input;
    
    if (input == "Yes" || input == "yes") {
        customer.difficulity_breathing = true;
    }
    else if (input == "No" || input == "no") {
        customer.difficulity_breathing = false;
    }
    else {
        cout << "Invalid input"; goto b;
    }
    //Question 3
    c:cout << "New or worsening cough." << setw(15) << "Yes/No" << endl;
    cin >> input;
    
    if (input == "Yes" || input == "yes") {
        customer.cough = true;
    }
    else if (input == "No" || input == "no") {
        customer.cough = false;
    }
    else {
        cout << "Invalid input"; goto c;
    }
    //Question 4
    d:cout << "Sore throat." << setw(15) << "Yes/No" << endl;
    cin >> input;
    
    if (input == "Yes" || input == "yes") {
        customer.soar_throat = true;
    }
    else if (input == "No" || input == "no") {
        customer.soar_throat = false;
    }
    else {
        cout << "Invalid input"; goto d;
    }
    //Question 5
    e:cout << "Vomiting or Diarrhea" << setw(15) << "Yes/No" << endl;
    cin >> input;
    
    if (input == "Yes" || input == "yes") {
        customer.vomiting = true;
    }
    else if (input == "No" || input == "no") {
        customer.vomiting = false;
    }
    else {
        cout << "Invalid input"; goto e;
    }
    //Question 6
    f:cout << "Sustained loss of smell, taste or appetite"<< setw(15)<< "Yes / No" <<endl;
    cin >> input;
    
    if (input == "Yes" || input == "yes") {
        customer.loss_of_senses = true;
    }
    else if (input == "No" || input == "no") {
        customer.loss_of_senses = false;
    }
    else {
        cout << "Invalid input"; goto f;
    }
    //Question 7
    g:cout << "Have you been within 6 feet (2 meters) of a COVID-19 case for 10 min or more in the last 2 weeks?"<< setw(15) << "Yes / No" << endl;
    cin >> input;
    
    if (input == "Yes" || input == "yes") {
        customer.covid_case = true;
    }
    else if (input == "No" || input == "no") {
        customer.covid_case = false;
    }
    else {
        cout << "Invalid input"; goto g;
    }

    string status = check_health(customer);
    return status;
}

int main() {
    self_check Masa;
    cout<< health_check(Masa);




}
