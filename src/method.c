//
// Created by Administrator on 24-4-16.
//
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Student.h"
#include "DocProcess.h"

int main() {
    int choice;
    char input[100];

    char* a;
    char removeID[ID_LEN];
    while (1) {
        loadStudents();
        printf("\n学生宿舍管理系统\n");
        printf("1. 注册\n");
        printf("2. 登录\n");
        printf("3. 退出\n");
        printf("输入您的选项: ");
        fgets(input, sizeof(input), stdin);  // 使用 fgets 读取整行
        if (sscanf(input, "%d", &choice) != 1) {  // 尝试从读取的行中解析整数
            printf("输入有误，请重新输入\n");
            continue;  // 如果解析失败，提示重新输入
        }
        switch (choice) {
        case 1:
            registerUser();
            saveStudents();
            break;
        case 2:
            a = loginUser();
            if (strcmp(a, admin) == 0) {
                while (1) {
                    printf("\n欢迎回来！管理员\n");
                    printf("1. 查看所有学生\n");
                    printf("2. 查找学生\n");
                    printf("3.删除学生信息\n");
                    printf("4.退出 \n");
                    printf("输入您的选项: ");
                    scanf("%d", &choice);
                    switch (choice) {
                    case 1:
                        showStudents();
                        break;
                    case 2:
                        searchStudent();
                        break;
                    case 3:
                        printf("请输入要删除学生的学号：");
                        scanf("%s", removeID);
                        removeStudent(removeID);
                        break;
                    case 4:
                        saveStudents();
                        printf("已退出程序\n");
                        exit(0);
                    default:
                        printf("无效选择，请重新选择\n");

                    }
                }
            }
            else {
                printf("欢迎回来！%s\n", a);
                printf("以下是您的个人信息：\n");
                Student* s0 = (Student*)((char*)a - offsetof(Student, name));
                printf("名字：%s\n", s0->name);
                printf("年龄：%d\n", s0->age);
                printf("性别：%s\n", s0->gender);
                printf("学号：%s\n", s0->s.ID);
                printf("宿舍位置：%s\n", s0->dormitoryLocation);
                printf("联系方式：%s\n", s0->phone);
            }
            break;
        case 3:
            saveStudents();
            printf("已退出程序\n");
            exit(0);
        default:
            printf("无效选择，请重新选择\n");
        }
    }
    return 0;
}