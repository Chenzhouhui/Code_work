#include<stdio.h>
int main(void)
{
    int a;
    int *p;
    a = 10;
    p = &a;
    printf("%d  %p\n",a, &a);   
    printf("%p  %p\n", p, &p);
    return 0;
}