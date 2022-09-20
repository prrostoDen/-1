#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct student
{
    string name;
    string surname;
    int day;
    int month;
    int year;
    string street;
    int house;
    string telefon;
};

bool SortByStreet(student& a, student& b)
{
    return a.street < b.street;
}

int RW(int N, int dayN)
{ 

    student stud[100];
    ofstream myfile("Info.dat", ios::out | ios::binary);
    if(myfile.is_open());
    {
        for (int i = 0; i < N; i++)
        {
            cout << "Student " << i + 1 << "\n";
            cout << "Enter name:" << endl;
            cin >> stud[i].name;

            cout << "Enter surname:" << endl;
            cin >> stud[i].surname;

            cout << "Birthday student:" << endl;
            cin >> stud[i].day;
            cin >> stud[i].month;
            cin >> stud[i].year;

            
        }
    }
    for (int i = 0; i < N; i++)
    {
        myfile.write((char*)&(stud[i]), sizeof(student));
    }
    myfile.close();

    cout << "Student to " << dayN << "th" << "\n\n";

    for (int i = 0; i < N; i++)
    {
        if (stud[i].day <= dayN)
            cout << stud[i].surname << "\n";
    }
    return 0;
}

void RD(string file_text, int N)
{
    student stud[100];
    ifstream file("info.dat", ios::in | ios::binary);

    cout << "Read the array...\n";

    for (int i = 0; i < N; i++)
    {
        file.read((char*)&(stud[i]), sizeof(student));
    }

    for (int i = 0; i < N; i++)
    {
        cout << stud[i].surname << ", ";
    }
}

void RD(string file_text, ifstream& myfile2)
{
    student stud[100];
    if (myfile2.is_open())
    {
        while (getline(myfile2, file_text))
        {
            cout << "\n";
            cout << file_text << "\n";
        }

        myfile2.close();

    }
}

void RW(int N)
{
    student stud[100];
    ofstream myfile2("Info.txt");
    if (myfile2.is_open());
    {
        for (int i = 0; i < N; i++)
        {
            cout << "Student " << i + 1 << "\n";
            cout << "Enter name:" << endl;
            cin >> stud[i].name;

            cout << "Enter surname:" << endl;
            cin >> stud[i].surname;

            cout << "Adressa student:" << endl;
            cin >> stud[i].street;
            cin >> stud[i].house;

            cout << "Telefon:" << endl;
            cin >> stud[i].telefon;

            myfile2 << stud[i].name << "  " << stud[i].surname << "; " << stud[i].street << "." << stud[i].house << ";" << stud[i].telefon << "\n";
        }
    }
    
    sort(stud, stud + N, SortByStreet);

    for (int i = 0;  i < N;  i++)
    {
        cout << stud[i].surname << ";" << stud[i].street << "." << stud[i].house << endl;
    }

    myfile2.close();
}

int main(void)
{
    int N, dayN;

    ifstream myfile("Info.dat");
    ifstream myfile2("Info.txt");
    string test;
    student stud[100];

    cout << "Number students: ";
    cin >> N;
    cout << "\n";
    cout << "Day: ";
    cin >> dayN;
    cout << "\n";

    RW(N, dayN);
    RD("Info.dat", N);
}