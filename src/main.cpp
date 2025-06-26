#include <iostream>
#include <string>
#include "../include/customer.h"
#include "../include/menu.h"
#include "../include/order.h"
#include "../include/feedback.h"
#include "../include/report.h"

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
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            cin.clear();
            cout << "\nInvalid choice, please enter number in between 1 and 7: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                currentCustomerInfo = registerCustomer();
                break;
            case 2:
                displayMenu();
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
            case 4:
                if (currentCustomerInfo.name.empty()) {
                    cout << "\nOpps. It seem you havent register as customer. Please choose option 1 to register first\n";
                    cout << "Please click enter to continue...";
                    cin.ignore();
                    cin.get();
                } else {
                    insertFeedback(currentCustomerInfo.name);
                }
                break;
            case 5:
                displayFeedback();
                break;
            case 6:
                showAllOrders();
                generateOrderSummary();
                break;
            case 7:
                cout << "\nThank you for using snacktrack online food. Existing the system...\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }
    } while (choice != 7);
}