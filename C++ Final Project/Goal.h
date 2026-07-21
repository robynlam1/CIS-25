#ifndef GOAL_H
#define GOAL_H

#include <string>

using namespace std;

class Goal {
  private:
      string name;
      string category;
      string difficulty;
      int xp;
      bool completed;
  
  public:
      Goal();
  
      Goal(string n, string c, string d, int x, bool comp);
  
      string getName();
      string getCategory();
      string getDifficulty();
      int getXP();
      bool isCompleted();
  
      void setName(string n);
      void setCategory(string c);
      void setDifficulty(string d);
      void setXP(int x);
      void setCompleted(bool c);
};

#endif
