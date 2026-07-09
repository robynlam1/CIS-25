#include <iostream>
#include <string>
using namespace std;

struct Patient{
    int ID;
    string name;
    int age;
};

int main() {
    Patient patient1;

    Patient *ptr = &patient1;

    patient1.ID = 001;
    patient1.name = "Bob Jones";
    patient1.age = 18;

    cout << "\nPatient Information:" << endl;
    cout << "ID: " << ptr->ID << endl;
    cout << "Name: " << ptr->name << endl;
    cout << "Age: " << ptr->age << endl;

    return 0;
}
