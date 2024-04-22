//
// Created by Administrator on 24-4-15.
//

#ifndef KESHE_STUDENT_H
#define KESHE_STUDENT_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define USERNAME_LEN 31
#define PASSWORD_LEN 50
#define ID_LEN 11

#define admin "007"
#define adminpasswords "123456"

typedef struct Person {

    char ID[ID_LEN];
    char password[PASSWORD_LEN];
    char correctPassword[PASSWORD_LEN];

} Person;

typedef struct {
    Person s;
    char name[USERNAME_LEN];
    char gender[5];
    int age;
    char phone[12];
    char dormitoryLocation[10];
} Student;

#define MAX_STUDENTS 469
Student students[MAX_STUDENTS];
int studentCount = 0;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* ��ջ����� */ }
}


void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
    }
    printf("Enter student's name: ");
    scanf("%31s", students[studentCount].name);
    clear_input_buffer();
    printf("Enter student's gender:");
    scanf("%5s", students[studentCount].gender);
    clear_input_buffer();
    printf("Enter student's age: ");
    scanf("%d", &students[studentCount].age);
    clear_input_buffer();
    printf("Enter dormitoryLocation: ");
    scanf("%10s", students[studentCount].dormitoryLocation);
    clear_input_buffer();
    printf("Enter phone number: ");
    scanf("%12s", students[studentCount].phone);
    clear_input_buffer();

}

void registerUser() {
    Student s1;

    printf("Enter username: ");
    fgets(s1.s.ID, USERNAME_LEN, stdin);
    s1.s.ID[strcspn(s1.s.ID, "\n")] = 0; // �Ƴ����з�


    while (1) {
        printf("Enter password: ");
        fgets(s1.s.password, PASSWORD_LEN, stdin);
        s1.s.password[strcspn(s1.s.password, "\n")] = 0; // �Ƴ����з�
        printf("Enter the password again: ");
        fgets(s1.s.correctPassword, PASSWORD_LEN, stdin);
        s1.s.correctPassword[strcspn(s1.s.correctPassword, "\n")] = 0; // �Ƴ����з�
        if (strcmp(s1.s.password, s1.s.correctPassword) == 0)break;
        else printf("The passwords entered twice do not match. Please re-enter them\n");
    }


    // ����û����Ƿ��Ѵ���
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, s1.s.ID) == 0) {
            printf("UserID already exists. Please try a different userID.\n");
            return;
        }
    }

    // ������û�
    strcpy(students[studentCount].s.ID, s1.s.ID);
    strcpy(students[studentCount].s.correctPassword, s1.s.correctPassword);
    addStudent();
    studentCount++;
    printf("User registered successfully!\n");
}

char *loginUser() {
    char userID[USERNAME_LEN];
    char password[PASSWORD_LEN];

    printf("Enter userID: ");
    fgets(userID, USERNAME_LEN, stdin);


    userID[strcspn(userID, "\n")] = 0; // �Ƴ��ַ���ĩβ�Ļ��з�

    printf("Enter password: ");

    fgets(password, PASSWORD_LEN, stdin);


    password[strcspn(password, "\n")] = 0; // �Ƴ��ַ���ĩβ�Ļ��з�

    if (strcmp(admin, userID) == 0 && strcmp(adminpasswords, password) == 0)
        return "007";
    else {
        for (int i = 0; i < studentCount; i++) {
            printf("%d", studentCount);
            printf("%s", students[i].s.ID);
            printf("%s", students[i].s.correctPassword);
            if (strcmp(students[i].s.ID, userID) == 0 && strcmp(students[i].s.correctPassword, password) == 0) {
                printf("Login successful!\n");
                return students[i].name;
            }
        }
    }
    printf("Invalid username or password. Please try again.\n");
    return 0;
}

void showStudents() {
    printf("List of all students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d. %s, dormitoryLocation: %s, Phone: %s, StudentID: %s, Gender: %s, Age: %d\n",
               i + 1,
               students[i].name,
               students[i].dormitoryLocation,
               students[i].phone,
               students[i].s.ID,
               students[i].gender,
               students[i].age);
    }
}

void searchStudent() {
    char ID[50];
    printf("Enter ID to search: ");
    scanf("%11s", ID);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, ID) == 0) {
            printf("Found student: %s, dormitoryLocation: %s, Phone: %s, StudentID: %s, Gender: %s, Age: %d\n",
                   students[i].name,
                   students[i].dormitoryLocation,
                   students[i].phone,
                   students[i].s.ID,
                   students[i].gender,
                   students[i].age
            );
            return;
        }
    }
    printf("No student found with the ID %s.\n", ID);
}

void removeStudent(char *ID) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, ID) == 0) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++)
                students[j] = students[j + 1];

            studentCount--;
            printf("ѧ��ɾ���ɹ���\n");
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ�ѧ����\n");
    }
}

#endif //KESHE_STUDENT_H
