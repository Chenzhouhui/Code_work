#include<stdio.h>
#include<stdlib.h>
/* 二级指针 */

/*
  示例说明：
  - 该程序演示“二级指针”（指向指针的指针）的用法。
  - 函数 `test` 接收 `int **`，在堆上分配一个 `int`，并通过二级指针修改调用者的指针。
  - 主函数负责传入指针地址、使用值并释放内存。
*/
void test(int **pp)
{
    /* 为调用者分配一个 int 大小的内存，并让 *pp 指向它 */
    *pp = (int *)malloc(sizeof(int));
    if(*pp == NULL)
    {
        /* 分配失败时提示并返回，调用者的指针保持不变（仍可能为 NULL） */
        printf("内存分配失败\n");
        return;
    }
    /* 给分配的内存赋值（通过二级指针解引用两次获得实际的 int） */
    **pp = 100;
}

int main(void)
{
    int *p = NULL; /* 初始化为 NULL，表明当前不指向任何有效内存 */
    test(&p);      /* 传入 `p` 的地址，使 `test` 能修改 `p` 的值 */
    printf("p的值%p，*p的值%d\n", p, *p); /* 打印指针地址与指向的整数值 */
    free(p);       /* 释放之前分配的内存，避免内存泄漏 */
    return 0;
}