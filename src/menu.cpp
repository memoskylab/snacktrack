#include <iostream>
#include <string>
#include <iomanip>

#include "../include/menu.h"

using namespace std;

const int MENU_SIZE = 5;

static string menuItems[MENU_SIZE] = {
    "Nasi Lemak",
    "Nasi Ayam Gepuk",
    "Chicken Chop Premium",
    "Nasi Goreng Chili Padi",
    "Nasi Singapore Original",
};

static float menuPrices[MENU_SIZE] = {
    5.00, 12.00, 18.00, 20.00, 25.00
};


void displayMenu(bool pause) {

    cout <<"\n=========== Available Menu =============\n";
    cout << left << setw(30) << "Item" << "Price (RM)" << endl;
    cout << "========================================\n";

    for (int i = 0; i < MENU_SIZE; i++) {
        cout << left << setw(30) << menuItems[i] << fixed << setprecision(2) << menuPrices[i] << endl;
    }

    if (pause) {
        cout << "\nPress ENTER to return to main menu...";
        cin.ignore();
        cin.get();
    }
}

int getMenuSize() {
    return MENU_SIZE;
}

string getMenuNameItem(int index) {
    if (index >= 0 && index < MENU_SIZE ) {
        return menuItems[index];
    } else {
        return "Invalid Item";
    }
}

float getMenuPrice(int index) {
    if (index >= 0 && index < MENU_SIZE ) {
        return menuPrices[index];
    } else {
        return 0.0;
    }
}

