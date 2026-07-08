#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Patient
{
    int ID;
    string name;
    int age;
    string gender;
    string diagnosis;
};

void addPatient(Patient* patients, int& count);
void displayPatients(Patient* patients, int count);
int binarySearch(Patient* patients, int count, int id);
void updatePatient(Patient* patients, int count);
void saveToFile(Patient* patients, int count);
void sortPatients(Patient* patients, int count);

int main() {
    Patient* patients = new Patient[100];
    int count = 0;
    int choice = 0;

    while (choice != 6) {
        cout << "\nHospital Patient Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Search Patient by ID\n";
        cout << "4. Update Patient Information\n";
        cout << "5. Save Patients to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addPatient(patients, count);
        } else if (choice == 2) {
            displayPatients(patients, count);
        } else if (choice == 3) {
            int ID;

            cout << "Enter Patient ID to search: ";
            cin >> ID;

            int result = binarySearch(patients, count, ID);

            if (result == -1) {
                cout << "Patient not found.\n";
            } else {
                cout << "\nPatient Found:\n";
                cout << "ID: " << patients[result].ID << endl;
                cout << "Name: " << patients[result].name << endl;
                cout << "Age: " << patients[result].age << endl;
                cout << "Gender: " << patients[result].gender << endl;
                cout << "Diagnosis: " << patients[result].diagnosis << endl;
            }
        } else if (choice == 4) {
            updatePatient(patients, count);
        } else if (choice == 5) {
            saveToFile(patients, count);
        } else if (choice == 6) {
            cout << "Good Bye!" << endl;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    delete[] patients;

    return 0;
}

void addPatient(Patient* patients, int& count) {
    cout << "\nEnter Patient ID: ";
    cin >> patients[count].ID;

    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, patients[count].name);

    cout << "Enter Age: ";
    cin >> patients[count].age;

    cout << "Enter Gender: ";
    cin >> patients[count].gender;

    cin.ignore();

    cout << "Enter Diagnosis: ";
    getline(cin, patients[count].diagnosis);

    count++;

    sortPatients(patients, count);

    cout << "Patient added successfully.\n";
}

void displayPatients(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patients available.\n";
        return;
    }

    cout << "\nPatient Records:\n";

    for (int i = 0; i < count; i++) {
        cout << "\nPatient " << i + 1 << endl;
        cout << "ID: " << patients[i].ID << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
    }
}

int binarySearch(Patient* patients, int count, int ID) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (patients[middle].ID == ID) {
            return middle;
        } else if (patients[middle].ID < ID) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

void updatePatient(Patient* patients, int count) {
    int ID;

    cout << "Enter Patient ID to update: ";
    cin >> ID;

    int index = binarySearch(patients, count, ID);

    if (index == -1) {
        cout << "Patient not found.\n";
        return;
    }

    cin.ignore();

    cout << "Enter new diagnosis: ";
    getline(cin, patients[index].diagnosis);

    cout << "Patient information updated successfully.\n";
}

void saveToFile(Patient* patients, int count) {
    ofstream file("patients.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << patients[i].ID << " "
             << patients[i].name << " "
             << patients[i].age << " "
             << patients[i].gender << " "
             << patients[i].diagnosis << endl;
    }

    file.close();
    cout << "Patients saved to patients.txt\n";
}

void sortPatients(Patient* patients, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (patients[j].ID > patients[j + 1].ID) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}
