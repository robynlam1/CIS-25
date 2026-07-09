#include <iostream>
#include <string>
using namespace std;

class Product {
  private:
      int ID;
      string name;
      double price;
  
  public:
    Product(int id, string productName, double productPrice) {
        ID = id;
        name = productName;
        price = productPrice;

        cout << "Product object created." << endl;
    }

    ~Product() {
        cout << "Product object destroyed." << endl;
    }

    void printDetails() {
        cout << "\nProduct Details" << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
    }
};

int main()
{
    Product product1(001, "Airpods", 399.99);

    product1.printDetails();

    return 0;
}
