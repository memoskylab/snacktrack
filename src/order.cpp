#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "../include/order.h"
#include "../include/menu.h"

using namespace std;

void placeOrder(const string &customerName) {
    OrderItem orders[10];
    string orderSummary[10][3];
    int orderCounts = 0;
    float total = 0.0;
    string input;

    cout << "\nWelcome " << customerName << endl;

    int menuSize = getMenuSize();
    displayMenu(false); // this will show menu without pause

    cout << "\n would like to place an order? Please type 'yes' to continue or 'no' to cancel : ";
    cin.ignore();
    getline(cin, input);

    if (input != "yes") {
        cout << "Returning to main menu...";
        return;
    }

    while (true) {
        int itemIndex, qty;

        while (true) {
            cout << "\nEnter item number (1 - " << menuSize << "): ";
            cin >> itemIndex;

            if (cin.fail()) {
                cin.clear();
                cout << "\nInvalid input. Please try again";
                cin.ignore(1000, '\n');
                cin.get();
            } else if (itemIndex < 1 || itemIndex > menuSize) {
                cin.clear();
                cout << "\nItem number must be greater than 0. Please try again";
                cin.ignore(1000, '\n');
                cin.get();
            } else {
                break;
            }
        }

    while (true) {
        cout << "Enter quantity : ";
        cin >> qty;

        if (cin.fail()) {
            cin.clear();
            cout << "\nInvalid input. Please try again";
            cin.ignore(1000, '\n');
            cin.get();
        } else if (qty < 1 || qty > qty) {
            cin.clear();
            cout << "\nQuantity must be greater than 0. Please try again";
            cin.ignore(1000, '\n');
            cin.get();
        } else {
            break;
        }
    }

        cin.ignore();

        //Populate order item
        orders[orderCounts].itemName = getMenuNameItem(itemIndex - 1);
        orders[orderCounts].price = getMenuPrice(itemIndex - 1);
        orders[orderCounts].quantity = qty;
        orders[orderCounts].subtotal = orders[orderCounts].price * qty;
        total += orders[orderCounts].subtotal;

        // Insert 2D array for order summary display
        orderSummary[orderCounts][0] = orders[orderCounts].itemName;
        orderSummary[orderCounts][1] = to_string(qty);
        ostringstream stream;
        stream << fixed << setprecision(2) << orders[orderCounts].subtotal;
        orderSummary[orderCounts][2] = stream.str();

        orderCounts++;

        cout << "\n Would you like to continue ordering? Please type 'yes' to continue or click enter to view summary : ";
        getline(cin, input);
        if (input.empty()) break;
    }

    // Display Order Summary
    cout << "\n=========== Order Summary ===========\n";
    cout << left << setw(30) << "Item" << setw(10) << "Quantity" << setw(15) << "Subtotal (RM)" << endl;
    cout << "=======================================\n";

    for (int i = 0; i < orderCounts; i++) {
        cout << left << setw(30) << orderSummary[i][0] << setw(10) << orderSummary[i][1]
        << setw(15) << orderSummary[i][2] << endl;
    }

    cout << "=======================================\n";
    cout << "Total: RM" << fixed << setprecision(2) << total << endl;

    // Write to order.txt
    ofstream outFile("../data/orders.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "--- Order Summary ---\n";
        for (int i = 0; i < orderCounts; i++) {
            outFile << i + 1 << ". " << orders[i].itemName << " x" << orders[i].quantity
            << " RM" << fixed << setprecision(2) << orders[i].subtotal << endl;
        }
        outFile << "Total: RM" << fixed << setprecision(2) << total << endl << endl;
        outFile.close();
        cout << "\nSuccessful save order\n";
    } else {
        cout << "\nFailed to save order, please contact developer for assistant.\n";
    }

    cout << "\nPresee enter to return to main menu...";
    cin.get();
}