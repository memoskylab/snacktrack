#include <iostream>
#include <fstream>
#include "../include/feedback.h"


using namespace std;

void insertFeedback(const string &customerName) {

    Feedback provideFeedback[1];
    string name = customerName;
    int rating = 0;
    string comment;

    cout << "\nWelcome " << customerName << endl;

    while (true) {
        cout << "\nPlease enter your rating for our platform 1 to 10 : ";
        cin >> rating;

        if (cin.fail()) {
            cin.clear();
            cout << "Invalid input. Please try again." << endl;
            cin.ignore(1000, '\n');
            cin.get();
        } else if (rating < 1 || rating > 10) {
            cin.clear();
            cout << "I appreciate your value. but max value is 10 only. Please try again.";
            cin.ignore(1000, '\n');
            cin.get();
        } else {
            break;
        }
    }

    cin.ignore();
    cout << "Please enter your comment : ";
    getline(cin, comment);

    //Populate the information on 1D Array
    provideFeedback[0].name = name;
    provideFeedback[0].comment = comment;
    provideFeedback[0].rating = rating;

    cout << "\n --- Hey " << customerName << " thanks for feedback ---\n";
    cout << "\nYour rating is : " << provideFeedback[0].rating << endl;
    cout << "Your comment is : " << provideFeedback[0].comment << endl;

    fstream inputFeedbackFile("../data/feedback.txt", ios::app);
    if (inputFeedbackFile.is_open()) {
        inputFeedbackFile << "Customer Name : " << provideFeedback[0].name << endl;
        inputFeedbackFile << "Customer Rating : " << provideFeedback[0].rating << endl;
        inputFeedbackFile << "Customer Comment : " << provideFeedback[0].comment << endl;
        inputFeedbackFile << endl;
        inputFeedbackFile.close();

        cout << "\nYour feedback successful save\n";
        cout << "\nPlease click enter to return to main menu...";
        cin.get();
    }
    else {
        cout << "\nSomething when wrong, unable to save order feeedback.";
    }

}

void displayFeedback() {
    ifstream feedbackFile("../data/feedback.txt");
    string feedbackCustomer;

    if (feedbackFile.is_open()) {
        cout << "\n----- List of feedback -----\n";
        cout << endl;
        while (getline(feedbackFile, feedbackCustomer)) {
            cout << feedbackCustomer << endl;
        }
        feedbackFile.close();
    } else {
        cout << "There was an error opening the file." << endl;
    }

    cout << "\nPlease click enter to return to main menu...";
    cin.ignore();
    cin.get();
}