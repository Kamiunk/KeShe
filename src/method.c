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
    char *a;
    char removeID[ID_LEN];

    while (1) {
        loadStudents();//加载学生信息
        printf("\n********************\n");
        printf("* 学生宿舍管理系统 *\n");
        printf("*    1.注册账户    *\n");
        printf("*    2.登录账户    *\n");
        printf("*    3.修改密码    *\n");
        printf("*    4.退出系统    *\n");
        printf("********************\n");
        printf("输入您的选项:");
        fgets(input, sizeof(input), stdin);  // 使用 fgets 读取整行
        if (sscanf(input, "%d", &choice) != 1) {  // 尝试从读取的行中解析整数
            printf("输入有误，请重新输入\n");
            continue;  // 如果解析失败，提示重新输入
        }
        switch (choice) {//首界面选项
            case 1:
                registerUser();
                break;
            case 2:
                a = loginUser();
                if (strcmp(a, admin) == 0) {
                    while (1) {
                        printf("\n************************\n");
                        printf("* 欢迎回来！管理员     *\n");
                        printf("* 1.查看所有学生       *\n");
                        printf("* 2.查找并修改学生信息 *\n");
                        printf("* 3.删除学生信息       *\n");
                        printf("* 4.添加学生信息       *\n");
                        printf("* 5.退出               *\n");
                        printf("************************\n");
                        printf("输入您的选项:");
                        scanf("%d", &choice);
                        printf("\n");
                        switch (choice) {//管理员界面选项
                            case 1:
                                showStudents();
                                break;
                                Student *s;
                            case 2:
                                s = searchStudent();
                                printf("\n下一步操作\n");
                                while (1) {
                                    printf("1.修改学生信息\n");
                                    printf("2.返回\n");
                                    printf("请输入您的选择：");
                                    scanf("%d", &choice);
                                    system("cls");
                                    printf("\n");
                                    clear_input_buffer();
                                    switch (choice) {//选择是否更改学生信息
                                        case 1:
                                            ModifyStuInfor(s);
                                            printf("1.修改学生信息\n");
                                            printf("2.退出\n");
                                            printf("请输入您的选择：");
                                            break;
                                        case 2:
                                            break;
                                        default:
                                            printf("无效输入，请重新输入一个整数");
                                            break;
                                    }
                                    if (choice == 2)break;
                                }
                                break;
                            case 3:
                                printf("请输入要删除学生的学号:");
                                scanf("%s", removeID);
                                removeStudent(removeID);
                                break;
                            case 4:
                                clear_input_buffer();
                                registerUser();
                                break;
                            case 5:
                                clear_input_buffer();
                                saveStudents();
                                system("cls");
                                break;
                            default:
                                printf("无效选择，请重新选择\n");

                        }
                        if (choice == 5)break;
                    }
                } else if (a == "0") {
                    break;
                } else {
                    printf("欢迎回来！%s\n", a);
                    printf("以下是您的个人信息：\n");
                    Student *s0 = (Student *) ((char *) a - offsetof(Student, name));
                    printf("名字：%s\n", s0->name);
                    printf("年龄：%d\n", s0->age);
                    printf("性别：%s\n", s0->gender);
                    printf("学号：%s\n", s0->s.ID);
                    printf("宿舍位置：%s\n", s0->dormitoryLocation);
                    printf("联系方式：%s\n", s0->phone);
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                changePassword();
                saveStudents();
                break;
            case 4:
                saveStudents();
                printf("已退出程序\n");
                exit(0);
            default:
                printf("无效选择，请重新选择\n");
        }
    }
    return 0;
}