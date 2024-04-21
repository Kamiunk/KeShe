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
    char* a ;
    char removeID[ID_LEN];
    while (1) {
        loadStudents();
        printf("\nStudent Dorm Management System\n");
        printf("1. Sign up\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);  // ʹ�� fgets ��ȡ����
        if (sscanf(input, "%d", &choice) != 1) {  // ���ԴӶ�ȡ�����н�������
            printf("Invalid input. Please enter a number.\n");
            continue;  // �������ʧ�ܣ���ʾ��������
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
                        printf("\n��ӭ����������Ա\n");
                        printf("1. �鿴����ѧ��\n");
                        printf("2. ����ѧ��\n");
                        printf("3.ɾ��ѧ����Ϣ\n");
                        printf("4.Exit \n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1:
                                showStudents();
                                break;
                            case 2:
                                searchStudent();
                                break;
                            case 3:
                                printf("������Ҫɾ��ѧ����ѧ�ţ�");
                                scanf("%s",removeID);
                                removeStudent(removeID);
                                break;
                            case 4:
                                saveStudents();
                                printf("Exiting program.\n");
                                exit(0);
                            default:
                                printf("Invalid choice. Please choose again.\n");
                        }
                    }
                }
                else {
                    printf("��ӭ������%s\n",a);
                    printf("���������ĸ�����Ϣ��\n");
                    Student *s0=(Student *)((char *)a - offsetof(Student, name));
                    printf("���֣�%s\n",s0->name);
                    printf("���䣺%d\n",s0->age);
                    printf("�Ա�%s\n",s0->gender);
                    printf("ѧ�ţ�%s\n",s0->s.ID);
                    printf("����λ�ã�%s\n",s0->dormitoryLocation);
                    printf("��ϵ��ʽ��%s\n",s0->phone);
                }
                break;
            case 3:
                saveStudents();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}
