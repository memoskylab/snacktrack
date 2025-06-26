#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

void showAllOrders() {
    ifstream inFile("../data/order.txt");
    string line;

    if (inFile.is_open()) {
        cout << "\n=========== ALL ORDER RECORDS ===============\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Failed to open order.txt.\n";
    }
}

void generateOrderSummary() {
    ifstream inFile("../data/order.txt");
    string line;
    float totalRevenue = 0.0;
    int orderCount = 0;

    if (!inFile.is_open()) {
        cout << "Failed to open order.txt.\n";
        return;
    }

    while (getline(inFile, line)) {
        size_t pos = line.find("Total: RM");
        if (pos != string::npos) {
            string amountStr = line.substr(pos + 9);
            try {
                totalRevenue += stof(amountStr);
                orderCount++;
            } catch (...) {

            }
        }
    }

    inFile.close();

    cout << "\n=========== ORDER SUMMARY REPORT =============\n";
    cout << "Total Orders   : " << orderCount << endl;
    cout << "Total Revenue  : RM" << fixed << setprecision(2) << totalRevenue << endl;
    cout << "==============================================\n";

    cout << "\nPlease click enter to return to main menu...";
    cin.ignore();
    cin.get();
}