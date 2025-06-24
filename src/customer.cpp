/*
 * Purpose : Get Customer Information / Store inside customer.txt / Display customer.txt Information
 * Author : Mohammad Aslam Bin Azman
 * Date : 23 June 2025
*/

#include <iostream>
#include <string>
#include <fstream>
#include "../include/customer.h"

using namespace std;

// Get Customer Information
CustomerInfo registerCustomer() {
    CustomerInfo customerInfo;
    cout << "Please Enter your name: ";
    cin.ignore();
    getline(cin, customerInfo.name);
    cout << "Please Enter your address: ";
    getline(cin, customerInfo.address);
    cout << "Please Enter your phone: ";
    getline(cin, customerInfo.phone);

    // Store and Write Customer Information on customer.txt
    fstream customerFile("../data/customer.txt", ios::app);
    if (customerFile.is_open()) {
        customerFile << "Name : " << customerInfo.name << endl;
        customerFile << "Address : " << customerInfo.address << endl;
        customerFile << "Phone Number : " << customerInfo.phone << endl;
        customerFile.close();
        cout << "\nCustomer information save successfully \n";

        cout << "\nPlease Enter to return to main menu...";
        cin.ignore();
        cin.get();

    } else {
        cout << "Failed to open file to save customer information";
    }
    return customerInfo;
}

// Display Customer Information from customer.txt
void displayCustomerFile() {
    ifstream inFile("../data/customer.txt");
    string customerDetails;

    if (inFile.is_open()) {
        while (getline(inFile, customerDetails)) {
            cout << customerDetails << endl;
        }
        inFile.close();
    } else {
        cout << "Failed to open file to display customer information";
    }

    cout << "\nPlease Enter to return to main menu...";
    cin.ignore();
    cin.get();
}