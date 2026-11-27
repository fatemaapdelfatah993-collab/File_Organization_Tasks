 #include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("students.txt", ios::app);

    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char choice = 'y';
    string name;
    int id;
    float grade;

    while (choice == 'y' || choice == 'Y') {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Grade: ";
        cin >> grade;

        outFile << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Do you want to add more records? (y/n): ";
        cin >> choice;
    }

    outFile.close();
    cout << "Data written to students.txt successfully!" << endl;

    return 0;
}
