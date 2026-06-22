#include <iostream>
using namespace std;
int main() {
  string itemName;
  int quantity;
  float cost;

  cout << "Enter the item name: ";
  cin >> itemName;

  cout << "Enter quantity: ";
  cin >> quantity;

  cout << "Enter the individual cost of the item: ";
  cin >> cost;

  cout << "The total cost for " << quantity << itemName << " is $" << (quantity * cost);

  return 0;
}
