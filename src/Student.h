//
// Created by Administrator on 24-4-15.
//

#ifndef KESHE_STUDENT_H
#define KESHE_STUDENT_H

#include <stdio.h>
#include <string.h>

#define NAME_LEN 32
#define ID_LEN 12
#define PASSWORD_LEN 50

#define admin "007"
#define adminpasswords "123456"

typedef struct Person {
    char ID[ID_LEN];
    char password[PASSWORD_LEN];
    char correctPassword[PASSWORD_LEN];
} Person;

typedef struct {
    Person s;
    char name[NAME_LEN];
    char gender[6];
    int age;
    char phone[13];
    char dormitoryLocation[11];
} Student;

#define MAX_STUDENTS 469
Student students[MAX_STUDENTS];
int studentCount = 0;
#include "DocProcess.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* ��ջ����� */
    }
}


void addStudent() {

    if (studentCount >= MAX_STUDENTS) {
        printf("�����������޷���Ӹ���ѧ������\n");
    }
    //password[strcspn(password, "\n")] = 0;

    printf("������ѧ������: ");
    fgets(students[studentCount].name,NAME_LEN+1,stdin);
    students[studentCount].name[strcspn(students[studentCount].name,"\n")]=0;

    printf("������ѧ���Ա�:");
    fgets(students[studentCount].gender,sizeof (students[studentCount].gender),stdin);
    students[studentCount].gender[strcspn(students[studentCount].gender,"\n")]=0;

    printf("������ѧ������:");
    scanf("%d", &students[studentCount].age);
    clear_input_buffer();

    printf("������ѧ�������ַ:");
    fgets(students[studentCount].dormitoryLocation,sizeof (students[studentCount].dormitoryLocation),stdin);
    students[studentCount].dormitoryLocation[strcspn(students[studentCount].dormitoryLocation,"\n")]=0;

    printf("�������ֻ���:");
    fgets(students[studentCount].phone,sizeof (students[studentCount].phone),stdin);
    students[studentCount].phone[strcspn(students[studentCount].phone,"\n")]=0;
}

void registerUser() {
    Student s1;

    printf("�������û���:");

    fgets(s1.s.ID, NAME_LEN, stdin);
    s1.s.ID[strcspn(s1.s.ID, "\n")] = 0; // �Ƴ����з�

    while (1) {
        printf("����������:");
        fgets(s1.s.password, PASSWORD_LEN, stdin);
        s1.s.password[strcspn(s1.s.password, "\n")] = 0; // �Ƴ����з�
        printf("���ٴ�ȷ������:");

        fgets(s1.s.correctPassword, PASSWORD_LEN, stdin);
        s1.s.correctPassword[strcspn(s1.s.correctPassword, "\n")] = 0; // �Ƴ����з�
        if (strcmp(s1.s.password, s1.s.correctPassword) == 0)break;
        else printf("�������벻һ�£�����������\n");
    }


    // ����û����Ƿ��Ѵ���
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, s1.s.ID) == 0) {
            printf("���û����ѱ�ռ�ã�����������\n");
            system("pause");
            system("cls");
            return;
        }
    }

    // ������û�
    strcpy(students[studentCount].s.ID, s1.s.ID);
    strcpy(students[studentCount].s.correctPassword, s1.s.correctPassword);
    addStudent();
    studentCount++;
    printf("�û�ע��ɹ�!\n");
    saveStudents();
    system("pause");
    system("cls");
}

char *loginUser() {
    char userID[NAME_LEN];
    char password[PASSWORD_LEN];
    printf("�������û���:");
    fgets(userID, NAME_LEN, stdin);
    userID[strcspn(userID, "\n")] = 0; // �Ƴ��ַ���ĩβ�Ļ��з�
    printf("����������: ");
    fgets(password, PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = 0; // �Ƴ��ַ���ĩβ�Ļ��з�
    if (strcmp(admin, userID) == 0 && strcmp(adminpasswords, password) == 0)
        return "007";
    else {
        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].s.ID, userID) == 0 && strcmp(students[i].s.correctPassword, password) == 0) {
                printf("��¼�ɹ�!\n");
                return students[i].name;
            }
        }
    }
    printf("�û������������������\n");
    return 0;
}

void showStudents() {
    printf("List of all students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d. ѧ��������%s, ����λ��: %s, �ֻ�����: %s, �û���: %s, �Ա�: %s, ����: %d\n",
               i + 1,
               students[i].name,
               students[i].dormitoryLocation,
               students[i].phone,
               students[i].s.ID,
               students[i].gender,
               students[i].age);
    }
    system("pause");
    system("cls");
}

void searchStudent() {
    char ID[50];
    printf("��������ҵ��û���:");
    scanf("%11s", ID);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, ID) == 0) {
            printf("ѧ��: %s, �����ַ: %s, �ֻ���: %s, ѧ��: %s, �Ա�: %s, ����: %d\n",
                   students[i].name,
                   students[i].dormitoryLocation,
                   students[i].phone,
                   students[i].s.ID,
                   students[i].gender,
                   students[i].age
            );
            system("pause");
            system("cls");
            return;
        }
    }
    printf("û���ҵ�ѧ��Ϊ %s ��ѧ��\n", ID);
    system("pause");
    system("cls");
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
            system("pause");
            system("cls");
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ�ѧ��\n");
        system("pause");
        system("cls");
    }
}

void changePassword() {
    char userID[NAME_LEN];
    char password[PASSWORD_LEN];
    char correctPassword[PASSWORD_LEN];
    printf("�������û���:");
    fgets(userID, NAME_LEN, stdin);
    userID[strcspn(userID, "\n")] = 0; // �Ƴ��ַ���ĩβ�Ļ��з�
    printf("����������: ");
    fgets(password, PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = 0; // �Ƴ��ַ���ĩβ�Ļ��з�
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, userID) == 0 && strcmp(students[i].s.correctPassword, password) == 0) {
            while (1) {
                printf("������������:");
                fgets(password, PASSWORD_LEN, stdin);
                password[strcspn(password, "\n")] = 0; // �Ƴ����з�
                printf("���ٴ�ȷ��������:");
                fgets(correctPassword, PASSWORD_LEN, stdin);
                correctPassword[strcspn(correctPassword, "\n")] = 0; // �Ƴ����з�
                if (strcmp(password, correctPassword) == 0)break;
                else printf("�������벻һ�£�����������\n");
            }
            strcpy(students[i].s.correctPassword, correctPassword);
            if (strcmp(students[i].s.correctPassword, correctPassword) == 0){
                printf("�����޸ĳɹ���");
                system("pause");
                system("cls");
            }
        }
    }
    return;
}

#endif //KESHE_STUDENT_H
