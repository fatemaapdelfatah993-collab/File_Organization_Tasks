#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {
    int grade, deleteGrade;

    // 1. Create the file and write five integer grades
    ofstream outFile("grades.txt");
    if (!outFile) {
        cout << "Error creating grades.txt!" << endl;
        return 1;
    }

    cout << "Enter 5 integer grades:\n";
    for (int i = 0; i < 5; i++) {
        cin >> grade;
        outFile << grade << endl;
    }
    outFile.close();

    // 2. Read and print the grades using a correct reading loop
    ifstream inFile("grades.txt");
    if (!inFile) {
        cout << "Error opening grades.txt for reading!" << endl;
        return 1;
    }

    cout << "\nGrades in file:\n";
    while (inFile >> grade) {
        cout << grade<<endl;
        }
    inFile.close();

    // 3. Ask the user for a grade to delete, then create a temporary file without it
    cout << "\nEnter a grade to delete: ";
    cin >> deleteGrade;

    ifstream srcFile("grades.txt");
    ofstream tempFile("temp.txt");

    if (!srcFile || !tempFile) {
        cout << "Error opening files for deletion!" << endl;
        return 1;
    }

    bool found = false;
    while (srcFile >> grade) {
        if (grade != deleteGrade) {
            tempFile << grade << endl;
        } else {
            found = true;
        }
    }

    srcFile.close();
    tempFile.close();

    // 4. Replace the original file and show a success or error message
    if (remove("grades.txt") != 0) {
        cout << "Error removing original file!" << endl;
        remove("temp.txt");
        return 1;
    }

    if (rename("temp.txt", "grades.txt") != 0) {
        cout << "Error renaming temporary file!" << endl;
        return 1;
    }

    if (found) {
        cout << "Grade deleted and file updated successfully!" << endl;
    } else {
        cout << "Grade not found, file updated successfully!" << endl;
    }

    return 0;
}
