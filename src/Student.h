//
// Created by Administrator on 24-4-15.
//

#ifndef KESHE_STUDENT_H
#define KESHE_STUDENT_H

#include <stdio.h>
#include <string.h>
//#include "DocProcess.h"

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
#include "DocProcess.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* 清空缓冲区 */
    }
}


void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("数据已满，无法添加更多学生数据\n");
    }
    printf("请输入学生姓名: ");
    scanf("%31s", students[studentCount].name);
    clear_input_buffer();

    printf("请输入学生性别:");
    scanf("%5s", students[studentCount].gender);
    clear_input_buffer();
    printf("请输入学生年龄:");
    scanf("%d", &students[studentCount].age);
    clear_input_buffer();
    printf("请输入学生宿舍:");
    scanf("%10s", students[studentCount].dormitoryLocation);
    clear_input_buffer();
    printf("请输入手机号:");

    scanf("%12s", students[studentCount].phone);
    clear_input_buffer();
}

void registerUser() {
    Student s1;

    printf("请输入用户名:");

    fgets(s1.s.ID, USERNAME_LEN, stdin);
    s1.s.ID[strcspn(s1.s.ID, "\n")] = 0; // 移除换行符


    while (1) {
        printf("请输入密码:");
        fgets(s1.s.password, PASSWORD_LEN, stdin);
        s1.s.password[strcspn(s1.s.password, "\n")] = 0; // 移除换行符
        printf("请再次确认密码:");


        fgets(s1.s.correctPassword, PASSWORD_LEN, stdin);
        s1.s.correctPassword[strcspn(s1.s.correctPassword, "\n")] = 0; // 移除换行符
        if (strcmp(s1.s.password, s1.s.correctPassword) == 0)break;
        else printf("两次密码不一致，请重新输入\n");
    }


    // 检查用户名是否已存在
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, s1.s.ID) == 0) {
            printf("该用户名已被占用，请重新输入\n");
            system("pause");
            system("cls");
            return;
        }
    }

    // 添加新用户
    strcpy(students[studentCount].s.ID, s1.s.ID);
    strcpy(students[studentCount].s.correctPassword, s1.s.correctPassword);
    addStudent();
    studentCount++;
    printf("用户注册成功!\n");
    saveStudents();
    system("pause");
    system("cls");
}

char *loginUser() {
    char userID[USERNAME_LEN];
    char password[PASSWORD_LEN];
    printf("请输入用户名:");
    fgets(userID, USERNAME_LEN, stdin);
    userID[strcspn(userID, "\n")] = 0; // 移除字符串末尾的换行符
    printf("请输入密码: ");
    fgets(password, PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = 0; // 移除字符串末尾的换行符
    if (strcmp(admin, userID) == 0 && strcmp(adminpasswords, password) == 0)
        return "007";
    else {
        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].s.ID, userID) == 0 && strcmp(students[i].s.correctPassword, password) == 0) {
                printf("登录成功!\n");

                return students[i].name;
            }
        }
    }
    printf("用户名或密码错误，请重试\n");
    return 0;
}

void showStudents() {
    printf("List of all students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d. 学生姓名：%s, 宿舍位置: %s, 手机号码: %s, 用户名: %s, 性别: %s, 年龄: %d\n",
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
    printf("请输入查找的用户名:");
    scanf("%11s", ID);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, ID) == 0) {
            printf("学生: %s, 宿舍地址: %s, 手机号: %s, 学号: %s, 性别: %s, 年龄: %d\n",
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
    printf("没有找到学号为 %s 的学生\n", ID);
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
            printf("学生删除成功！\n");
            break;
        }
    }
    if (!found) {
        printf("未找到学生\n");
    }
}

void changePassword() {
    char userID[USERNAME_LEN];
    char password[PASSWORD_LEN];
    char correctPassword[PASSWORD_LEN];
    printf("请输入用户名:");
    fgets(userID, USERNAME_LEN, stdin);
    userID[strcspn(userID, "\n")] = 0; // 移除字符串末尾的换行符
    printf("请输入密码: ");
    fgets(password, PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = 0; // 移除字符串末尾的换行符
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].s.ID, userID) == 0 && strcmp(students[i].s.correctPassword, password) == 0) {
            while (1) {
                printf("请输入新密码:");
                fgets(password, PASSWORD_LEN, stdin);
                password[strcspn(password, "\n")] = 0; // 移除换行符
                printf("请再次确认新密码:");
                fgets(correctPassword, PASSWORD_LEN, stdin);
                correctPassword[strcspn(correctPassword, "\n")] = 0; // 移除换行符
                if (strcmp(password, correctPassword) == 0)break;
                else printf("两次密码不一致，请重新输入\n");
            }
            strcpy(students[i].s.correctPassword, correctPassword);
            if (strcmp(students[i].s.correctPassword, correctPassword) == 0)printf("密码修改成功！");
        }
    }
    return;
}

#endif //KESHE_STUDENT_H
