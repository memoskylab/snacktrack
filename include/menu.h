#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

void displayMenu(bool pause = true); // declare method
int getMenuSize(); // Get total menu items that available
string getMenuNameItem(int index); // Get menu name that been chosen by customer
float getMenuPrice(int index); // Get menu price based on getMenuNameItem


#endif //MENU_H
