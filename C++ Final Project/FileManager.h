#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Goal.h"
#include "User.h"

using namespace std;

class FileManager {
  public:
      void saveGoals(vector<Goal>& goals);
      void loadGoals(vector<Goal>& goals);
  
      void saveUser(User& user);
      void loadUser(User& user);
};

#endif
