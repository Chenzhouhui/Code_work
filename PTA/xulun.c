/*7-1素数
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 10000  // 题目给定的最大范围

// 埃氏筛法：预处理[0, MAX_N]的素数标记
void sieve(bool is_prime[]) {
    // 初始化：默认所有数都是素数，0和1除外
    memset(is_prime, true, sizeof(bool) * (MAX_N + 1));
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            // 标记i的所有倍数为非素数
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    bool is_prime[MAX_N + 1];
    sieve(is_prime);  // 一次性预处理所有素数  
    int a, b;
    // 多组输入：直到EOF（输入结束）
    while (scanf("%d %d", &a, &b) != EOF) {
        // 处理a > b的情况（题目未明确，但兼容输入）
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }       
        bool first = true;  // 控制空格：第一个数不输出前导空格
        for (int i = a; i <= b; i++) {
            if (is_prime[i]) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", i);
                first = false;
            }
        }
        printf("\n");  // 每组输出换行
    }   
    return 0;
}
*/
/*7-2句子首字母变大写

#include <stdio.h>

int main() {
    int c;
    int first = 1;

    while ((c = getchar()) != '\n') {
        if (c == '?' || c == '.' || c == '!') {
            putchar(c);
            first = 1;
        }
        else if (c == ' ') {
            putchar(c);
        }
        else {
            if (first == 1) {
                if (c >= 'a' && c <= 'z') {
                    c += 'A' - 'a';
                }
                first = 0;
            }
            putchar(c); 
        }
    }

    printf(" \n");
    return 0;
}
*/

/*7-3输出时间格式

#include <stdio.h>

int main() {
    long long ms;
    if (scanf("%lld", &ms) != 1) {
        return 0;
    }

    long long total_seconds = ms / 1000;
    if (ms < 0 && ms % 1000 != 0) {
        total_seconds--;
    }

    long long seconds_in_day = ((total_seconds % 86400) + 86400) % 86400;

    long long hour = seconds_in_day / 3600;
    long long minute = (seconds_in_day % 3600) / 60;
    long long second = seconds_in_day % 60;

    printf("%lld:%lld:%lld\n", hour, minute, second);
    
    return 0;
}
*/
/*7-4判断一个数是否为回文数

#include <stdio.h>
#include <string.h>

int main() {
    char num[105];
    if (scanf("%104s", num) != 1) {
        return 0;
    }

    int left = 0;
    int right = (int)strlen(num) - 1;
    int is_palindrome = 1;

    while (left < right) {
        if (num[left] != num[right]) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (is_palindrome) {
        printf("%s 是回文数\n", num);
    } else {
        printf("%s 不是回文数\n", num);
    }

    return 0;
}
*/
/*7-5整数A+B*/

#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        return 0;
    }

    printf("%d\n", a + b);
    return 0;
}

