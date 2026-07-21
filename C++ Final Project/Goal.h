#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <string>

using namespace std;

class Goal {
  private:
      string name;
      string category;
      int xp;
      bool completed;
  
  public:
      Goal(string n = "", string c = "", int x = 0);
  
      void completeGoal();
  
      string getName();
      string getCategory();
      int getXP();
      bool isCompleted();
  
      void setName(string n);
      void setCategory(string c);
      void setXP(int x);
  
      void displayGoal();
};

#endif
