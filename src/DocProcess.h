//
// Created by Administrator on 24-4-21.
//

#ifndef KESHE_DOCPROCESS_H
#define KESHE_DOCPROCESS_H

#include <stdio.h>
#include "Student.h"
void loadStudents() {
    studentCount=0;
    FILE *file = fopen("D:\\githubFst_test\\KeShe\\src\\Student.dat", "r");
    if (file == NULL) {
        printf("No student data to load.\n");
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
    printf("Students loaded successfully.\n");
}

void saveStudents() {
    FILE *file = fopen("D:\\githubFst_test\\KeShe\\src\\Student.dat", "w");
    if (file == NULL) {
        printf("Failed to save students.\n");
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
    printf("Students saved successfully.\n");
}

#endif //KESHE_DOCPROCESS_H
