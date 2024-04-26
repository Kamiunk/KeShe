//
// Created by Administrator on 24-4-21.
//

#ifndef KESHE_DOCPROCESS_H
#define KESHE_DOCPROCESS_H

#include <stdio.h>
#include "Student.h"

void loadStudents() {

    studentCount = 0;
    FILE *file = fopen("Student.dat", "r");


    if (file == NULL) {
        printf("��ǰ�޿ɼ������ݣ�������������\n");
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
    printf("ѧ�����ݼ��سɹ�\n");
}

void saveStudents() {


    FILE *file = fopen("Student.dat", "w");

    if (file == NULL) {
        printf("ѧ�����ݱ���ʧ��\n");
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

    printf("ѧ�����ݱ���ɹ�\n");

}

#endif //KESHE_DOCPROCESS_H

/*�ڵ�һ�ε��� fgets ֮���û�����Ļ��з��Ѿ�����ȡ����־�������еĽ�����
 * ���������뻺����������ˣ����߸�׼ȷ��˵������ fgets �����ˡ�
 * ��ˣ�����������һ�� fgets ����ʱ������ȴ��µ����룬��Ϊ��һ�е����ݣ��������з����Ѿ�����һ�� fgets ��ȡ�ˡ�

    �����ǹؼ��㣺ֻҪ��������С�����õ��㹻���������û��������������У�ÿ�� fgets ���ö����ȡһ���У������ַ�����ĩβ�������з���
                ֮�󣬸ú��������ַ���ĩβ���Ͽ��ַ� \0����ʾ�ַ����Ľ�����

    ֻ���ڶ�ȡ���г����� fgets ָ���Ļ�������Сʱ�������� fgets ����֮�����������͵����뺯�����ã��� scanf������Щ�������ܲ���ȡ���з�������Ҫ������뻺������
    ���� fgets �Ѿ������˶�ȡ���з��Ķ��������������� fgets ֮��ͨ������Ҫ�ֶ���ջ�������
*/


/*�Ƴ� fgets ��ȡ�ַ���ĩβ�Ļ��з���һ�ֳ�����ʵ����ԭ�����£�


    1.�������ַ������ݣ�
                   ͨ��������ʹ���ַ�������ʾ�ı����ݣ����ܻ�洢���Ƚϻ�������ǡ�
                   ���з�ͨ������Ϊ��������еĸ���Ʒ���������ַ������ݵ�һ���֡�
                   �Ƴ����з����Ա�֤�ַ���ֻ�����û�ʵ��������ı����ݡ�


    2.��ֹ������⣺
                ������Ƴ����з�����ʹ�� printf ���������������ӡ�ַ���ʱ������ֲ���Ҫ�Ļ��С�
                ���磬���Ҫ�������ַ���֮����������ı�����ÿ���ַ���ĩβ����һ�����з�����ô�ı�������ᱻ��ϣ���������������µ����С�


    3.��������
             ĳЩ�ַ������������ַ������ӻ��ʽ����������ı��ṹ�У�Ԥ���ַ����ǲ��������з��ġ������ַ���ĩβ�������з�ʹ����Щ��������ֱ�Ӻ�Ԥ�⡣


    4.�����ԣ�
            ��ĳЩ����£��ر����ַ���Ҫ�ڶ��ϵͳ֮�䴫��򱣴�ʱ���Ƴ����з��ܹ������ƽ̨�ļ��������⣬��Ϊ��ͬ�Ĳ���ϵͳ���ڻ��з��в�ͬ�Ĵ���ʽ��


    5.������Ч�ԣ�
               ��Щʱ���ַ����������ڱ����ļ��������������еı���ֵ����Щ������ͨ����������ڻ��з���
*/