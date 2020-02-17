//
// Created by User on 2020-02-17.
//

#ifndef ASSIGMENT_1_MAIN_H
#define ASSIGMENT_1_MAIN_H

#include <vector>
#include "StudentRecord.h"

namespace ZMMALE001 {

    void clear();

    void optAddRecord();

    void optReadData();

    void optSaveData();

    void optGetStudentMarks();

    void optGrade();

    StudentRecord &getRecord();

    StudentRecord &getRecord(std::string studentNumber);

    std::vector<StudentRecord> ram_data;

}
#endif //ASSIGMENT_1_MAIN_H
