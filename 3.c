#include<stdio.h>
#include<string.h>
/*
    结构体指针
    1. 定义一个结构体变量stu
    2. 定义一个结构体指针变量p，指向stu
    3. 通过结构体指针变量p给结构体变量stu的成员赋值
    4. 输出结构体变量stu的成员值
  */
typedef struct
{
    int id;
    char name[20];
    int age;
}Student;

int main(void)
{
    Student stu;
    Student *p = &stu;
    (*p).id = 1900;                                     /*p->id = 1900;*/              
    (*p).age = 20;                                      /*p->age = 20;*/
    strcpy((*p).name, "xiaoming");                      /*p->name = "xiaoming";*/
    printf("%d--%s--%d\n", stu.id, stu.name, stu.age);
    return 0;
}