#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
  private:
      string username;
      int level;
      int xp;
      int streak;
      int longestStreak;
      int goalsCompleted;
  
  public:
      User(string name = "Player");
  
      string getUsername();
      int getLevel();
      int getXP();
      int getStreak();
      int getLongestStreak();
      int getGoalsCompleted();
  
      void setUsername(string name);
      void setLevel(int l);
      void setXP(int x);
      void setStreak(int s);
      void setLongestStreak(int ls);
      void setGoalsCompleted(int gc);
  
      void addXP(int amount);
      void increaseStreak();
      void resetStreak();
      void addCompletedGoal();
  
      void displayStats();
};

#endif
