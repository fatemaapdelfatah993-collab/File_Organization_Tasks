#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fruit;

    ifstream inFile("fruit.txt");

    if (!inFile)
    {
        cout << "File not found";
        return 0;
    }

    while (getline(inFile, fruit))
    {
        cout << fruit << endl;
    }

    inFile.close();

    ofstream outFile("fruit.txt", ios::app);

    outFile << "Fresh Fruits" << endl;

    outFile.close();

    return 0;
}
