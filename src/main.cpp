#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

#include "StudentRecord.h"

void clear();

void optAddRecord();

void optReadData();

void optSaveData();

void optGetStudentMarks();

void optGrade();

using namespace std;

std::vector<StudentRecord> ram_data;

int main() {

    bool first = true;
    for (;;) {

        std::cout << "1. add studentRecord" << std::endl;
        std::cout << "2. read database" << std::endl;
        std::cout << "3. save database" << std::endl;
        std::cout << "4. display given studentRecord data" << std::endl;
        std::cout << "5. grade studentRecord" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Enter a number (or q to quit) and press return." << std::endl;

        char option;

        cin >> option;
        cout << &"chosen " [ option] << endl;

        switch (option) {

            case '1':
                cout << "executing add..." << endl;
                optAddRecord();
                cout << "done executing add..." << endl;
                break;
            case '2':
                optReadData();
                break;
            case '3':
                optSaveData();
                break;
            case '4':
                optGetStudentMarks();
                break;
            case '5':
                optGrade();
                break;
        }
        if (option == 'q') { break; }
    }
    return 0;
}

void optGrade() {
// todo search for student number and print average of grades.

}

void optGetStudentMarks() {
// todo search for student number and print grades.
}


void optSaveData() {
// format: name,surname,student-number,marks

    cout << "Saving..." << endl;
    ofstream ofs("data.csv");
    string line;
    for (const StudentRecord &sr : ram_data) {
        line = sr.name + "," + sr.surname + "," + sr.studentNumber + "," + sr.classRecord;
        cout << line << endl;
        ofs << line << endl;
    }
    ofs.close();
}

void optReadData() {
// todo load CSV and replace ram_data with data from CSV

    ifstream ifs("data.csv");
    string name, surname, studentNumber, marks;
    StudentRecord temp;

    // empty ram_data vector.
    ram_data.clear();

    while(getline(ifs, name, ',')){
        temp.name = name;

        getline(ifs, surname, ',');
        temp.surname = surname;

        getline(ifs, studentNumber, ',');
        temp.studentNumber = studentNumber;

        getline(ifs, marks);
        temp.classRecord = marks;

        ram_data.push_back(temp);
        cout << "Loaded " + temp.studentNumber + " into memory.";
    }

    cout << "Finished loading records...";

}

void optAddRecord() {

    string name;
    string surname;
    string studentNumber;
    string classRecord;

    cout << "Enter Name: " << endl;
    cin >> name;

    cout << "Enter Surname: " << endl;
    cin >> surname;

    cout << "Enter Student Number: " << endl;
    cin >> studentNumber;

    cout << "Enter Marks: " << endl;
    cin.ignore();
    getline(cin, classRecord);
    //cin >> ws;
//    cout << classRecord;

    // create object
    StudentRecord s = StudentRecord{name, surname, studentNumber, classRecord};

    // add to a vector (list)
    ram_data.push_back(s);
    cout << "Record for " + s.studentNumber + " added." << endl;
}

void clear() {
    // todo change to clear
    system("cls");
}
