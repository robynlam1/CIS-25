#include <iostream>
using namespace std;

int main() {
  float n1, n2, n3;

  cout << "Enter three numbers: ";

  // Used >> for all three inputs
  cin >> n1 >> n2 >> n3;

  // Nested if statement to determine the largest number
  if (n1 >= n2) {
    // Nested if statement to compare n1 and n3
    if (n1 >= n3) {
      cout << "Largest number: " << n1;
    } else {
      cout << "Largest number: " << n3;
    }
  } else {
    // Nested if statement to compare n2 and n3
    if (n2 >= n3) {
      cout << "Largest number: " << n2;
    } else {
      cout << "Largest number: " << n3;
    }
  }

  return 0;
}
