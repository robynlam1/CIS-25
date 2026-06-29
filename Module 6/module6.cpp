#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    double totalPrice() {
        return price * quantity;
    }
};

int main() {
    int choice = 0;

    while (choice != 3) {

        cout << "\nShopping Cart Menu: " << endl;
        cout << "1. Add Item to Cart" << endl;
        cout << "2. View Checkout" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            Item item;

            cout << "Enter item name: ";
            cin >> item.name;

            cout << "Enter item price: ";
            cin >> item.price;

            cout << "Enter item quantity: ";
            cin >> item.quantity;

            ofstream outFile("cart.txt", ios::app);

            if (outFile.is_open()) {
                outFile << item.name << " "
                        << item.price << " "
                        << item.quantity << endl;
                outFile.close();
                cout << "Item added to cart!" << endl;
            } else {
                cout << "Error opening file." << endl;
            }
        }
        else if (choice == 2) {
            ifstream inFile("cart.txt");

            if (!inFile) {
                cout << "Cart is empty or file not found." << endl;
            } else {
                Item item;
                double total = 0;

                cout << "\nCheckout: " << endl;

                while (inFile >> item.name >> item.price >> item.quantity) {
                    cout << "Item: " << item.name << endl;
                    cout << "Price: $" << item.price << endl;
                    cout << "Quantity: " << item.quantity << endl;
                    cout << "Total: $" << item.totalPrice() << endl;
                    total += item.totalPrice();
                }
                cout << "Total: $" << total << endl;
                inFile.close();
            }
        }
        else if (choice == 3) {
            cout << "Thank you for shopping!" << endl;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
