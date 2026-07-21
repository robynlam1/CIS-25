#include "Goal.h"

Goal::Goal(string n, string c, int x) {
    name = n;
    category = c;
    xp = x;
    completed = false;
}

string Goal::getName() {
    return name;
}

string Goal::getCategory() {
    return category;
}

int Goal::getXP() {
    return xp;
}

bool Goal::isCompleted() {
    return completed;
}

void Goal::setName(string n) {
    name = n;
}

void Goal::setCategory(string c) {
    category = c;
}

void Goal::setXP(int x) {
    xp = x;
}

void Goal::setCompleted(bool c) {
    completed = c;
}

void Goal::completeGoal() {
    completed = true;
}

void Goal::displayGoal() {
    cout << "\nGoal: " << name << endl;
    cout << "Category: " << category << endl;
    cout << "XP Reward: " << xp << endl;

    if (completed)
        cout << "Status: Completed" << endl;
    else
        cout << "Status: Not Completed" << endl;
}
