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


    FILE *file = fopen("Student.dat", "w");

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

    printf("学生数据保存成功\n");

}

#endif //KESHE_DOCPROCESS_H

/*在第一次调用 fgets 之后，用户输入的换行符已经被读取，标志着输入行的结束。
 * 这样，输入缓冲区被清空了，或者更准确地说，它被 fgets 处理了。
 * 因此，当您进行下一次 fgets 调用时，它会等待新的输入，因为上一行的内容（包括换行符）已经被第一次 fgets 读取了。

    这里是关键点：只要缓冲区大小被设置得足够大以容纳用户可能输入的最大行，每次 fgets 调用都会读取一整行，并在字符串的末尾保留换行符。
                之后，该函数会在字符串末尾加上空字符 \0，表示字符串的结束。

    只有在读取的行超过了 fgets 指定的缓冲区大小时，或者在 fgets 调用之间有其他类型的输入函数调用（如 scanf），这些函数可能不读取换行符，才需要清空输入缓冲区。
    由于 fgets 已经包括了读取换行符的动作，所以在两次 fgets 之间通常不需要手动清空缓冲区。
*/


/*移除 fgets 读取字符串末尾的换行符是一种常见的实践，原因如下：


    1.纯净的字符串数据：
                   通常，我们使用字符串来表示文本数据，可能会存储、比较或输出它们。
                   换行符通常被视为输入过程中的副产品，而不是字符串内容的一部分。
                   移除换行符可以保证字符串只包含用户实际输入的文本内容。


    2.防止输出问题：
                如果不移除换行符，当使用 printf 或其他输出函数打印字符串时，会出现不必要的换行。
                例如，如果要在两个字符串之间加入其他文本，但每个字符串末尾都有一个换行符，那么文本输出将会被打断，看起来会出现在新的行中。


    3.后续处理：
             某些字符串操作，如字符串连接或格式化到更大的文本结构中，预期字符串是不包含换行符的。保持字符串末尾不带换行符使得这些操作更加直接和预测。


    4.兼容性：
            在某些情况下，特别是字符串要在多个系统之间传输或保存时，移除换行符能够避免跨平台的兼容性问题，因为不同的操作系统对于换行符有不同的处理方式。


    5.数据有效性：
               有些时候字符串数据用于比如文件名、命令或代码中的变量值，这些场合中通常不允许存在换行符。
*/