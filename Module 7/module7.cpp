#include <iostream>
#include <fstream>
using namespace std;

// Class to store the information from CSV dataset
class Restaurant {
  public:
    string ID;
    string name;
    string city;
    string cuisine;
    string averageCost;
    string rating;
    string votes;

  void display() {
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "City: " << city << endl;
    cout << "Cuisine: " << cuisine << endl;
    cout << "Average Cost: " << averageCost << endl;
    cout << "Rating: " << rating << endl;
    cout << "Votes: " << votes << endl;
  }
};

// Separates one row of CSV file into individual columns
// Deals with commas inside quotation marks
int splitCSV(string line, string fields[]) {
  int count = 0;
  string field = "";
  bool insideQuote = false;

  for (char c : line) {
    if (c == '"') {
      insideQuote = !insideQuote;
    } else if (c == ',' && !insideQuote) {
      fields[count] = field;
      count++;
      field = "";
    } else {
      field += c;
    }
  }

  fields[count] = field;
  count++;

  return count;
}

int main() {
  // Opens CSV dataset
  ifstream file("Dataset.csv");

  // Checks if file opened
  if (!file) {
    cout << "Error opening file." << endl;
    return 1;
  }

  // Store first 10 restaurants
  Restuarant restaurants[10];
  string line;
  int count = 0;

  // Skip header row
  getline(file, line);

  // Use columns 0 (ID), 1 (name), 3 (city), 9 (cuisine), 10 (average cost for 2), 17 (aggregate rating), 20 (votes)
  while (getline(file, line) && count < 10) {
    string data[25];

    // Split current row into columns
    if (splitCSV(line, data) >= 21) {
      restaurants[count].id = data[0];
      restaurants[count].name = data[1];
      restaurants[count].city = data[3];
      restaurants[count].cuisines = data[9];
      restaurants[count].averageCost = data[10];
      restaurants[count].rating = data[17];
      restaurants[count].votes = data[20];

      count++;
  }

  // Close file after reading
  file.close();

  cout << "First 10 Restaurants from the Dataset:\n";

  // Display restaurants 
  for (int i = 0; i < count; i++) {
      restaurants[i].display();
  }

  return 0;
}
