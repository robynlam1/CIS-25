#include "User.h"

User::User(string name) {
    username = name;
    level = 1;
    xp = 0;
    streak = 0;
    longestStreak = 0;
    goalsCompleted = 0;
}

string User::getUsername() {
    return username;
}

int User::getLevel() {
    return level;
}

int User::getXP() {
    return xp;
}

int User::getStreak() {
    return streak;
}

int User::getLongestStreak() {
    return longestStreak;
}

int User::getGoalsCompleted() {
    return goalsCompleted;
}

void User::setUsername(string name) {
    username = name;
}

void User::setLevel(int l) {
    level = l;
}

void User::setXP(int x) {
    xp = x;
}

void User::setStreak(int s) {
    streak = s;
}

void User::setLongestStreak(int ls) {
    longestStreak = ls;
}

void User::setGoalsCompleted(int gc) {
    goalsCompleted = gc;
}

void User::addXP(int amount) {
    xp += amount;

    while (xp >= 100) {
        xp -= 100;
        level++;

        cout << "\n****************************\n";
        cout << "       LEVEL UP!\n";
        cout << "You reached Level " << level << "!\n";
        cout << "****************************\n";
    }
}

void User::increaseStreak() {
    streak++;

    if (streak > longestStreak)
    {
        longestStreak = streak;
    }
}

void User::resetStreak() {
    streak = 0;
}

void User::addCompletedGoal() {
    goalsCompleted++;
}

void User::displayStats() {
    cout << "\nPLAYER STATS:\n";
    cout << "Username: " << username << endl;
    cout << "Level: " << level << endl;
    cout << "XP: " << xp << "/100" << endl;
    cout << "Current Streak: " << streak << " days" << endl;
    cout << "Longest Streak: " << longestStreak << " days" << endl;
    cout << "Goals Completed: " << goalsCompleted << endl;
}
