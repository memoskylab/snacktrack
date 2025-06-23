#include <iostream>
#include <string>
#include "../include/customer.h"
#include "../include/menu.h"
#include "../include/order.h"

using namespace std;

int main() {

    int choice;
    CustomerInfo currentCustomerInfo;

    do {
        cout << "\n============================================\n";
        cout << "Welcome to SnackTrack Online Food Ordering\n";
        cout << "============================================\n";
        cout << "1. Register Customer\n2. View Menu\n3. Place Order\n4. Insert Feedback"
                "\n5. View Feedback\n6. Generate report\n7. Exit\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                currentCustomerInfo = registerCustomer();
                break;
            case 2:
                displayMenu(); // This for test purpose
                break;
            case 3:
                if (currentCustomerInfo.name.empty()) {
                    cout << "\nOpps. It seem you havent register as customer. Please choose option 1 to register first\n";
                    cout << "Please click enter to continue...";
                    cin.ignore();
                    cin.get();
                } else {
                    placeOrder(currentCustomerInfo.name);
                }
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 7);
}