#include <iostream>
#include <cstdlib>
#include "studentRecord.h"

void clear();

using namespace std;
int main() {
    string name;
    string surname;
    string studentNumber;
    string classRecord;
    studentRecord s;

    std::cout << "1. add studentRecord" << std::endl;
    std::cout << "2. read database" << std::endl;
    std::cout << "3. save database" << std::endl;
    std::cout << "4. display given studentRecord data" << std::endl;
    std::cout << "5. grade studentRecord" << std::endl;
    std::cout << ""<< std::endl;
    std:: cout << "Enter a number (or q to quit) and press return." << std::endl;

    int option;

    for(;;) {
        cin>>option;
        switch (option) {
            case 1:
                //clear();
                cout<<"enter studentRecord details:"<<endl;

                cin>>name;
                cin>>surname;
                cin>>studentNumber;
                cin>>classRecord;

                s.setName(name);
                s.setSurname(surname);
                s.setStudentNumber(studentNumber);
                s.setStudentRecord(classRecord);
                //studentRecord().setStudentRecord(classRecord); wtf
                cout << "done"<<endl;
               //vector
                break;
            case 2:
               cout << studentRecord(s) << endl;
                break;
            case 3:
                cout<<"w";
                break;
            case 4:
                cout<<"u";
                break;
            case 5:
                cout<<"y";
                break;

        }
        if(option==6){break;}
    }
    return 0;
}

void clear(void) {
    system("clear");
}
