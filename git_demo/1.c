#include<stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{
    int x = 10, y = 20;
    printf("x = %d, y = %d\r\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\r\n", x, y);

    return 0;
}