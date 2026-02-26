#include<stdio.h>
#include<string.h>

typedef struct
{
    int id;
    char name[20];
    int age;
}Student;

int main(void)
{
    Student stu1, stu2, stu3;
    Student stu[3];
    stu1.id = 1001;
    strcpy(stu1.name, "Alice");
    stu1.age = 18;

    stu2.id = 1002;
    strcpy(stu2.name, "Bob");
    stu2.age = 20;

    stu3.id = 1003;
    strcpy(stu3.name, "Charlie");
    stu3.age = 22;
    stu[0] = stu1;
    stu[1] = stu2;
    stu[2] = stu3;
    for(int i = 0; i < 3; i++)
    {
        printf("stu[%d]: id = %d, name = %s, age = %d\r\n", i, stu[i].id, stu[i].name, stu[i].age);
    }

    return 0;
}