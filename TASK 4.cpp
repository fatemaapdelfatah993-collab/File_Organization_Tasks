#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");

    for (int i = 0; i < n; i++)
    {
        Person p;

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Enter age: ";
        cin >> p.age;

        outFile << p.name << endl;
        outFile << p.age << endl;
    }

    outFile.close();

    vector<Person> people;

    ifstream inFile("persons.txt");

    Person p;

    while (getline(inFile, p.name))
    {
        if (!(inFile >> p.age))
            break;
            inFile.ignore();

        people.push_back(p);
    }

    inFile.close();

    if (people.empty())
    {
        cout << "No persons found";
        return 0;
    }

    int youngest = people[0].age;
    int oldest = people[0].age;

    ofstream resultFile("results.txt");

    resultFile << "Youngest Persons:" << endl;

    for (int i = 0; i < people.size(); i++)
    {
        if (people[i].age < youngest)
            youngest = people[i].age;

        if (people[i].age > oldest)
            oldest = people[i].age;
    }

    for (int i = 0; i < people.size(); i++)
    {
        if (people[i].age == youngest)
            resultFile << people[i].name << " "
            << people[i].age << endl;
    }

    resultFile << "Oldest Persons:" << endl;

    for (int i = 0; i < people.size(); i++)
    {
        if (people[i].age == oldest)
            resultFile << people[i].name << " "
                       << people[i].age << endl;
    }

    resultFile.close();

    cout << "Results saved successfully";

    return 0;}
