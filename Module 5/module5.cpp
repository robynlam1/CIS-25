#include <iostream>
#include <cmath>
using namespace std;

void add();
void sub();
void mult();

int main() {
  int choice;

  cout << "Calculator Menu: " << endl;
  cout << "1. Add" << endl;
  cout << "2. Subtract" << endl;
  cout << "3. Square" << endl;
  cout << "Please enter your choice: ";
  cin >> choice;

  if (choice == 1) {
    add();
  } else if (choice == 2) {
    sub();
  } else {
    square();
  }

  return 0;
}

void add() {
  double num1, num2;

  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  cout << "Sum: " << num1 + num2;
}

void sub() (
  double num1, num2;

  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  cout << "Difference: " << num1 - num2 << endl;
}

void square() {
  double num1, num2;

  cout << "Enter a number: ";
  cin >> num;

  cout << "Square: " << pow(num, 2) << endl;
}
