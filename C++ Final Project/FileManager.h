#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

#include "Goal.h"
#include "User.h"

using namespace std;

class FileManager {
  public:
      void saveGoals(Goal goals[], int goalCount);
      void loadGoals(Goal goals[], int &goalCount);
  
      void saveUser(User user);
      void loadUser(User &user);
};

#endif
