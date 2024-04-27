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
        loadStudents();//����ѧ����Ϣ
        printf("\n********************\n");
        printf("* ѧ���������ϵͳ *\n");
        printf("*    1.ע���˻�    *\n");
        printf("*    2.��¼�˻�    *\n");
        printf("*    3.�޸�����    *\n");
        printf("*    4.�˳�ϵͳ    *\n");
        printf("********************\n");
        printf("��������ѡ��:");
        fgets(input, sizeof(input), stdin);  // ʹ�� fgets ��ȡ����
        if (sscanf(input, "%d", &choice) != 1) {  // ���ԴӶ�ȡ�����н�������
            printf("������������������\n");
            continue;  // �������ʧ�ܣ���ʾ��������
        }
        switch (choice) {//�׽���ѡ��
            case 1:
                registerUser();
                break;
            case 2:
                a = loginUser();
                if (strcmp(a, admin) == 0) {
                    while (1) {
                        printf("\n************************\n");
                        printf("* ��ӭ����������Ա     *\n");
                        printf("* 1.�鿴����ѧ��       *\n");
                        printf("* 2.���Ҳ��޸�ѧ����Ϣ *\n");
                        printf("* 3.ɾ��ѧ����Ϣ       *\n");
                        printf("* 4.���ѧ����Ϣ       *\n");
                        printf("* 5.�˳�               *\n");
                        printf("************************\n");
                        printf("��������ѡ��:");
                        scanf("%d", &choice);
                        printf("\n");
                        switch (choice) {//����Ա����ѡ��
                            case 1:
                                showStudents();
                                break;
                                Student *s;
                            case 2:
                                s = searchStudent();
                                printf("\n��һ������\n");
                                while (1) {
                                    printf("1.�޸�ѧ����Ϣ\n");
                                    printf("2.����\n");
                                    printf("����������ѡ��");
                                    scanf("%d", &choice);
                                    system("cls");
                                    printf("\n");
                                    clear_input_buffer();
                                    switch (choice) {//ѡ���Ƿ����ѧ����Ϣ
                                        case 1:
                                            ModifyStuInfor(s);
                                            printf("1.�޸�ѧ����Ϣ\n");
                                            printf("2.�˳�\n");
                                            printf("����������ѡ��");
                                            break;
                                        case 2:
                                            break;
                                        default:
                                            printf("��Ч���룬����������һ������");
                                            break;
                                    }
                                    if (choice == 2)break;
                                }
                                break;
                            case 3:
                                printf("������Ҫɾ��ѧ����ѧ��:");
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
                                printf("��Чѡ��������ѡ��\n");

                        }
                        if (choice == 5)break;
                    }
                } else if (a == "0") {
                    break;
                } else {
                    printf("��ӭ������%s\n", a);
                    printf("���������ĸ�����Ϣ��\n");
                    Student *s0 = (Student *) ((char *) a - offsetof(Student, name));
                    printf("���֣�%s\n", s0->name);
                    printf("���䣺%d\n", s0->age);
                    printf("�Ա�%s\n", s0->gender);
                    printf("ѧ�ţ�%s\n", s0->s.ID);
                    printf("����λ�ã�%s\n", s0->dormitoryLocation);
                    printf("��ϵ��ʽ��%s\n", s0->phone);
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
                printf("���˳�����\n");
                exit(0);
            default:
                printf("��Чѡ��������ѡ��\n");
        }
    }
    return 0;
}