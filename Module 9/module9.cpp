#include <iostream>
#include <string>
using namespace std;

class User {
  protected:
    string username;

  public:
    User(string name) {
      username = name;
    }

    virtual void accessLevel() {
        cout << "General user access." << endl;
    }

    string getUsername() {
        return username;
    }

    virtual ~User() {}
};

class Employee : public User {
  public:
    Employee(string name) : User(name) {}

    void accessLevel() override {
        cout << "Employee Permissions: View inventory only." << endl;
    }
};

class Manager : public User {
  public:
    Manager(string name) : User(name) {}

    void accessLevel() override {
        cout << "Manager Permissions: View and update inventory." << endl;
    }
};

class Admin : public User {
  public:
    Admin(string name) : User(name) {}

    void accessLevel() override {
        cout << "Administrator Permissions: Full access - add, update, and delete inventory." << endl;
    }
};

int main() {
    Employee employee("John");
    Manager manager("Sarah");
    Admin admin("Michael");

    cout << "\nUser: " << employee.getUsername() << endl;
    employee.accessLevel();

    cout << "\nUser: " << manager.getUsername() << endl;
    manager.accessLevel();

    cout << "\nUser: " << admin.getUsername() << endl;
    admin.accessLevel();

    return 0;
}
