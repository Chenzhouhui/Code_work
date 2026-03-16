/*
 * 指针与结构体知识点示例
 * 文件: note/1.c
 * 包含：
 *  - 指针基础与运算
 *  - 指针与数组
 *  - 指针的指针
 *  - 通过指针修改函数外变量（swap）
 *  - 结构体定义、typedef
 *  - 结构体指针与 -> 运算符
 *  - 动态分配结构体
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- 指针基础 ---------- */
void pointer_basics(void) {
    int a = 10;
    int *p = &a; // p 存放变量 a 的地址

    printf("指针基础:\n");
    printf("a = %d, &a = %p\n", a, (void*)&a);
    printf("p = %p, *p = %d\n\n", (void*)p, *p);
}

/* ---------- 指针与数组 ---------- */
void pointer_and_array(void) {
    int arr[] = {1,2,3,4,5};
    int *p = arr; // 数组名在表达式中会退化为指向首元素的指针

    printf("指针与数组:\n");
    for (int i = 0; i < 5; ++i) {
        // 等价于 arr[i]
        printf("arr[%d]=%d, *(p+%d)=%d\n", i, arr[i], i, *(p+i));
    }
    printf("\n");
}

/* ---------- 指针的指针 ---------- */
void pointer_to_pointer(void) {
    int x = 100;
    int *p = &x;
    int **pp = &p; // 指向指针的指针

    printf("指针的指针:\n");
    printf("x=%d, *p=%d, **pp=%d\n\n", x, *p, **pp);
}

/* ---------- 通过指针修改外部变量（swap） ---------- */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- 结构体基础 ---------- */
// 定义一个学生结构体
struct Student {
    int id;
    char name[32];
    double score;
};

// 使用 typedef 简化类型名
typedef struct Student Student;

void struct_basics(void) {
    Student s1;
    s1.id = 1;
    strncpy(s1.name, "Alice", sizeof(s1.name)-1);
    s1.name[sizeof(s1.name)-1] = '\0';
    s1.score = 95.5;

    printf("结构体基础:\n");
    printf("Student: id=%d, name=%s, score=%.1f\n\n", s1.id, s1.name, s1.score);
}

/* ---------- 结构体指针与动态分配 ---------- */
void struct_pointer_and_malloc(void) {
    // 在堆上分配一个 Student
    Student *ps = (Student*)malloc(sizeof(Student));
    if (ps == NULL) {
        perror("malloc");
        return;
    }

    ps->id = 2;            // 使用 -> 访问结构体成员（通过指针）
    strncpy(ps->name, "Bob", sizeof(ps->name)-1);
    ps->name[sizeof(ps->name)-1] = '\0';
    ps->score = 88.0;

    printf("结构体指针与动态分配:\n");
    printf("Student*: id=%d, name=%s, score=%.1f\n\n", ps->id, ps->name, ps->score);

    free(ps); // 记得释放
}

/* ---------- 嵌套结构体与数组 ---------- */
struct Class {
    char name[32];
    Student students[3]; // 固定大小数组
    int count;
};

void nested_structs(void) {
    struct Class cls;
    strncpy(cls.name, "Class A", sizeof(cls.name)-1);
    cls.name[sizeof(cls.name)-1] = '\0';
    cls.count = 2;

    cls.students[0].id = 10;
    strncpy(cls.students[0].name, "Carol", sizeof(cls.students[0].name)-1);
    cls.students[0].score = 78.0;

    cls.students[1].id = 11;
    strncpy(cls.students[1].name, "Dave", sizeof(cls.students[1].name)-1);
    cls.students[1].score = 82.5;

    printf("嵌套结构体与数组:\n");
    printf("Class: %s, count=%d\n", cls.name, cls.count);
    for (int i = 0; i < cls.count; ++i) {
        printf("  student %d: id=%d, name=%s, score=%.1f\n", i, cls.students[i].id, cls.students[i].name, cls.students[i].score);
    }
    printf("\n");
}

int main(void) {
    pointer_basics();
    pointer_and_array();
    pointer_to_pointer();

    int a = 5, b = 7;
    printf("swap 前: a=%d, b=%d\n", a, b);
    swap(&a, &b); // 通过传入地址修改外部变量
    printf("swap 后: a=%d, b=%d\n\n", a, b);

    struct_basics();
    struct_pointer_and_malloc();
    nested_structs();

    return 0;
}