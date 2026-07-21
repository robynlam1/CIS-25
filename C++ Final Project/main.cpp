#include <iostream>
#include <string>

#include "Goal.h"
#include "User.h"
#include "FileManager.h"
using namespace std;

void displayMenu() {
  cout << "\nMOMENTUM: Gamified Habit Tracker";
  cout << "\n1. View Goals";
  cout << "\n2. Add Goal";
  cout << "\n3. Complete Goal";
  cout << "\n4. Edit Goal";
  cout << "\n5. Delete Goal";
  cout << "\n6. Search Goal";
  cout << "\n7. View Statistics";
  cout << "\n8. AI Coach";
  cout << "\n9. Save and Exit";

  cout << "\n\nChoose an option: ";
}

void viewGoals(Goal goals[], int goalCount) {
  if (goalCount == 0) {
      cout << "\nNo goals created yet.\n";
      return;
  }

  for (int i = 0; i < goalCount; i++) {
      cout << "\nGoal #" << i + 1;
      goals[i].displayGoal();
  }
}

void addGoal(Goal goals[], int &goalCount) {
  string name;
  string category;
  int xp;

  cout << "\nEnter goal name: ";
  getline(cin, name);

  cout << "Enter category: ";
  getline(cin, category);

  cout << "Enter XP reward: ";
  cin >> xp;
  cin.ignore();

  goals[goalCount] = Goal(name, category, xp);

  goalCount++;

  cout << "\nGoal added successfully!\n";
}

void completeGoal(Goal goals[], int goalCount, User &user) {
  int choice;

  viewGoals(goals, goalCount);

  cout << "\nChoose goal number to complete: ";
  cin >> choice;
  cin.ignore();

  if (choice > 0 && choice <= goalCount) {
      if (!goals[choice - 1].isCompleted()) {
          goals[choice - 1].completeGoal();

          user.addXP(goals[choice - 1].getXP());
          user.addCompletedGoal();
          user.increaseStreak();

          cout << "\nGoal completed!";
          cout << "\n+" << goals[choice - 1].getXP() << " XP earned!\n";
      } else {
          cout << "\nGoal already completed.\n";
      }
  }
  else {
      cout << "\nInvalid choice.\n";
  }
}

void editGoal(Goal goals[], int goalCount) {
  int choice;

  viewGoals(goals, goalCount);

  cout << "\nChoose goal number to edit: ";
  cin >> choice;
  cin.ignore();

  if (choice > 0 && choice <= goalCount) {
      string name;
      string category;

      cout << "New goal name: ";
      getline(cin, name);

      cout << "New category: ";
      getline(cin, category);

      goals[choice - 1].setName(name);
      goals[choice - 1].setCategory(category);

      cout << "\nGoal updated!\n";
  } else {
      cout << "\nInvalid choice.\n";
  }
}

void deleteGoal(Goal goals[], int &goalCount) {
  int choice;

  viewGoals(goals, goalCount);

  cout << "\nChoose goal number to delete: ";
  cin >> choice;
  cin.ignore();

  if (choice > 0 && choice <= goalCount) {

      for (int i = choice - 1; i < goalCount - 1; i++) {
          goals[i] = goals[i + 1];
      }

      goalCount--;

      cout << "\nGoal deleted!\n";
  } else {
      cout << "\nInvalid choice.\n";
  }
}

void searchGoal(Goal goals[], int goalCount) {
  string search;

  cout << "\nEnter goal name to search: ";
  getline(cin, search);

  bool found = false;

  for (int i = 0; i < goalCount; i++) {
      if (goals[i].getName() == search) {
          goals[i].displayGoal();
          found = true;
      }
  }

  if (!found) {
      cout << "\nGoal not found.\n";
  }
}

void aiCoach(User user) {
  cout << "\nAI Coach: \n";

  if (user.getStreak() >= 7) {
      cout << "Amazing streak!";
      cout << "\nYou are building strong habits.\n";
  }
  else if (user.getGoalsCompleted() < 3) {
      cout << "Start small.";
      cout << "\nComplete simple goals every day.\n";
  }
  else {
      cout << "Keep improving!";
      cout << "\nConsistency creates long-term success.\n";
  }
}

int main() {
  Goal goals[100];

  int goalCount = 0;

  User user("Player");
  FileManager file;

  file.loadGoals(goals, goalCount);
  file.loadUser(user);

  int choice;
  
  while (choice != 9) {
      displayMenu();
  
      cin >> choice;
      cin.ignore();
  
      if (choice == 1) {
          viewGoals(goals, goalCount);
      } else if (choice == 2) {
          addGoal(goals, goalCount);
      } else if (choice == 3) {
          completeGoal(goals, goalCount, user);
      } else if (choice == 4) {
          editGoal(goals, goalCount);
      } else if (choice == 5) {
          deleteGoal(goals, goalCount);
      } else if (choice == 6) {
          searchGoal(goals, goalCount);
      } else if (choice == 7) {
          user.displayStats();
      } else if (choice == 8) {
          aiCoach(user);
      } else if (choice == 9) {
          file.saveGoals(goals, goalCount);
          file.saveUser(user);
  
          cout << "\nData saved. Goodbye!\n";
      } else {
          cout << "\nInvalid option.\n";
      }
  }
}
