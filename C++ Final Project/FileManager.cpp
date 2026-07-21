#include "FileManager.h"

using namespace std;

void FileManager::saveGoals(Goal goals[], int goalCount) {
    ofstream outFile("goals.txt");

    if (!outFile) {
        cout << "Error opening goals.txt" << endl;
        return;
    }

    for (int i = 0; i < goalCount; i++) {
        outFile
            << goals[i].getName() << ","
            << goals[i].getCategory() << ","
            << goals[i].getXP() << ","
            << goals[i].isCompleted()
            << endl;
    }

    outFile.close();

    cout << "Goals saved successfully!" << endl;
}

void FileManager::loadGoals(Goal goals[], int &goalCount) {
    ifstream inFile("goals.txt");

    if (!inFile) {
        goalCount = 0;
        return;
    }

    string name;
    string category;
    string xpString;
    string completedString;

    goalCount = 0;

    while (getline(inFile, name, ',')) {
        getline(inFile, category, ',');
        getline(inFile, xpString, ',');
        getline(inFile, completedString);

        int xp = stoi(xpString);
        bool completed = stoi(completedString);

        goals[goalCount] = Goal(name, category, xp);

        if (completed) {
            goals[goalCount].completeGoal();
        }

        goalCount++;
    }

    inFile.close();
}

void FileManager::saveUser(User user) {
    ofstream outFile("user.txt");

    if (!outFile) {
        cout << "Error opening user.txt" << endl;
        return;
    }

    outFile << user.getUsername() << endl;
    outFile << user.getLevel() << endl;
    outFile << user.getXP() << endl;
    outFile << user.getStreak() << endl;
    outFile << user.getLongestStreak() << endl;
    outFile << user.getGoalsCompleted() << endl;

    outFile.close();

    cout << "User saved successfully!" << endl;
}

void FileManager::loadUser(User &user) {
    ifstream inFile("user.txt");

    if (!inFile) {
        return;
    }

    string username;
    int level;
    int xp;
    int streak;
    int longestStreak;
    int goalsCompleted;

    getline(inFile, username);

    inFile >> level;
    inFile >> xp;
    inFile >> streak;
    inFile >> longestStreak;
    inFile >> goalsCompleted;

    user.setUsername(username);
    user.setLevel(level);
    user.setXP(xp);
    user.setStreak(streak);
    user.setLongestStreak(longestStreak);
    user.setGoalsCompleted(goalsCompleted);

    inFile.close();
}
