//
// Created by Mohammad Aslam on 24/06/2025.
//

#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>


using namespace std;

struct Feedback {
    string name;
    int rating;
    string comment;
};

void insertFeedback(const string &customerName);

#endif //FEEDBACK_H
