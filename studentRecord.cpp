//
// Created by User on 2020-02-13.
//

#include "studentRecord.h"


const std::string &studentRecord::getName() const {
    return name;
}

void studentRecord::setName(const std::string &name) {
    studentRecord::name = name;
}

const std::string &studentRecord::getSurname() const {
    return surname;
}

void studentRecord::setSurname(const std::string &surname) {
    studentRecord::surname = surname;
}

const std::string &studentRecord::getStudentNumber() const {
    return studentNumber;
}

void studentRecord::setStudentNumber(const std::string &studentNumber) {
    studentRecord::studentNumber = studentNumber;
}

const std::string &studentRecord::getStudentRecord() const {
    return classRecord;
}

void studentRecord::setStudentRecord(const std::string &studentRecord) {
    studentRecord::classRecord = studentRecord;
}

std::ostream &operator<<(std::ostream &os, const studentRecord &student) {
    os << "name: " << student.name << " surname: " << student.surname << " studentNumber: " << student.studentNumber
       << " classRecord: " << student.classRecord;
    return os;
}
