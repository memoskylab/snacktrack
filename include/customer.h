/*
 * Purpose : Declare variable and function
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

struct CustomerInfo {
    string name;
    string address;
    string phone;
};

    CustomerInfo registerCustomer(); // declare method insert information
    void displayCustomerFile(); // declare method display information from txt file
    void displayCustomerInfo(const CustomerInfo &customerInfo); // declare method display personal information

#endif
