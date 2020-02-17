#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>

#include "StudentRecord.h"
#include "main.h"



using namespace std;

int main() {
    for (;;) {
        ZMMALE001::clear();
        std::cout << "1. add studentRecord" << std::endl;
        std::cout << "2. read database" << std::endl;
        std::cout << "3. save database" << std::endl;
        std::cout << "4. display given studentRecord data" << std::endl;
        std::cout << "5. grade studentRecord" << std::endl << std::endl;
        std::cout << "Enter a number (or q to quit) and press return." << std::endl;

        char option;

        cin >> option;
        cout << &"chosen "[option] << endl;

        switch (option) {

            case '1':
                cout << "executing add..." << endl;
                ZMMALE001::optAddRecord();
                cout << "done executing add..." << endl;
                break;
            case '2':
                ZMMALE001::optReadData();
                break;
            case '3':
                ZMMALE001::optSaveData();
                break;
            case '4':
                ZMMALE001::optGetStudentMarks();
                break;
            case '5':
                ZMMALE001::optGrade();
                break;
        }
        if (option == 'q') { break; }
    }
    return 0;
}

void ZMMALE001::optGrade() {
// todo search for student number and print average of grades.

    try {
        ZMMALE001::StudentRecord student = ZMMALE001::getRecord();
        cin.ignore();

        string records = student.classRecord;
        double avg, count = 0.0, total = 0.0;
        // Used to split string around spaces.
        istringstream ss(records);

        // Traverse through all words
        int subject;
        do {
            // Read a word
            ss >> subject;
            total += subject;
            count++;
        } while (ss);

        avg = (total - subject )/ (count-1);

        // print avg
        cout << "Average for " + student.studentNumber + " is : " + to_string(avg) << endl;

    } catch (exception &e) {
        cout << "0" << endl;
    }

}

void ZMMALE001::optGetStudentMarks() {

    try {
        ZMMALE001::StudentRecord student = ZMMALE001::getRecord();
        cout << student.classRecord << endl;
    } catch (exception &e) {
        cerr << e.what() << endl;
    }

}

ZMMALE001::StudentRecord &ZMMALE001::getRecord() {

    string studentNumber;
    cout << "Enter Student Number: ";
    cin >> studentNumber;
    std::transform(studentNumber.begin(), studentNumber.end(), studentNumber.begin(), ::toupper);

    for (ZMMALE001::StudentRecord &s : ZMMALE001::ram_data) {
        if (s.studentNumber == studentNumber) {
            return s;
        }
    }

    throw (0);
}


void ZMMALE001::optSaveData() {
// format: name,surname,student-number,marks

    string fname;
    cout << "Enter Filename or File Path : ";
    cin >> fname;

    cout << "Saving..." << endl;
    ofstream ofs(fname);
    string line;
    for (const ZMMALE001::StudentRecord &sr : ZMMALE001::ram_data) {
        line = sr.name + "," + sr.surname + "," + sr.studentNumber + "," + sr.classRecord;
        cout << line << endl;
        ofs << line << endl;
    }
    ofs.close();
}

void ZMMALE001::optReadData() {
// todo load CSV and replace ram_data with data from CSV
    string fname;
    cout << "Enter Filename or File Path : ";
    cin >> fname;

    ifstream ifs(fname);
    string name, surname, studentNumber, marks;
    ZMMALE001::StudentRecord temp;

    // empty ram_data vector.
    ZMMALE001::ram_data.clear();

    while (getline(ifs, name, ',')) {
        temp.name = name;

        getline(ifs, surname, ',');
        temp.surname = surname;

        getline(ifs, studentNumber, ',');
        std::transform(studentNumber.begin(), studentNumber.end(), studentNumber.begin(), ::toupper);
        temp.studentNumber = studentNumber;

        getline(ifs, marks);
        temp.classRecord = marks;

        ZMMALE001::ram_data.push_back(temp);
        cout << "Loaded " + temp.studentNumber + " into memory.";
    }

    cout << "Finished loading records...";

}

void ZMMALE001::optAddRecord() {

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
    std::transform(studentNumber.begin(), studentNumber.end(), studentNumber.begin(), ::toupper);


    cout << "Enter Marks: " << endl;
    cin.ignore();
    getline(cin, classRecord);

    // create object
    ZMMALE001::StudentRecord s = ZMMALE001::StudentRecord{name, surname, studentNumber, classRecord};

    try {
        ZMMALE001::StudentRecord s2 = ZMMALE001::getRecord(s.studentNumber);
        cout << "Student " + s2.studentNumber + " already exists!" << endl;
    } catch (exception& e){
        ZMMALE001::ram_data.push_back(s);
        cout << "Record for " + s.studentNumber + " added." << endl;
    }

}

void ZMMALE001::clear() {
    // todo change to clear
    system("cls");
}

ZMMALE001::StudentRecord &ZMMALE001::getRecord(std::string studentNumber) {
    for (ZMMALE001::StudentRecord &s : ZMMALE001::ram_data) {
        if (s.studentNumber == studentNumber) {
            return s;
        }
    }

    throw (0);
}
