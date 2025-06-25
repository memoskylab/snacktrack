#ifndef ORDER_H
#define ORDER_H

#include <iostream>

using namespace std;

struct OrderItem {
    string itemName;
    float price;
    int quantity;
    float subtotal;
};

void placeOrder(const string &customerName);
int getNextOrder();

#endif //ORDER_H
