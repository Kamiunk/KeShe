//
// Created by Administrator on 24-4-21.
//

#ifndef KESHE_DOCPROCESS_H
#define KESHE_DOCPROCESS_H

#include <stdio.h>
#include "Student.h"
void loadStudents() {
    studentCount = 0;
    FILE* file = fopen("D:\\githubFst_test\\KeShe\\src\\Student.dat", "r");
    if (file == NULL) {
        printf("当前无可加载数据，请先输入数据\n");
        return;
    }

    while (fscanf(file, "%s %s %s %s %d %s %s\n",
        students[studentCount].s.ID,
        students[studentCount].s.correctPassword,
        students[studentCount].name,
        students[studentCount].gender,
        &students[studentCount].age,
        students[studentCount].phone,
        students[studentCount].dormitoryLocation) == 7) {
        studentCount++;
        if (studentCount >= MAX_STUDENTS) break;
    }

    fclose(file);
    printf("学生数据加载成功\n");
}

void saveStudents() {
    FILE* file = fopen("D:\\githubFst_test\\KeShe\\src\\Student.dat", "w");
    if (file == NULL) {
        printf("学生数据保存失败\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%s %s %s %s %d %s %s\n",
            students[i].s.ID,
            students[i].s.correctPassword,
            students[i].name,
            students[i].gender,
            students[i].age,
            students[i].phone,
            students[i].dormitoryLocation);
    }
    fclose(file);
    studentCount = 0;
    printf("学生数据保存成功.\n");
}

#endif //KESHE_DOCPROCESS_H