//7-1
#include <stdio.h>

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    int a[10];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Selection Sort Algorithm
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i; // Assume current index has the maximum value
        for (int j = i + 1; j < n; j++) {
            // Find the actual maximum in the remaining unsorted part
            if (a[j] > a[max_idx]) {
                max_idx = j;
            }
        }
        // Swap the found maximum with the current element
        int temp = a[i];
        a[i] = a[max_idx];
        a[max_idx] = temp;
    }

    // Output the sorted array with required spacing
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" "); // Print space only between numbers
        }
    }
    printf("\n"); // Ensure a newline at the end

    return 0;
}

//7-2
#include <stdio.h>

int main() {
    int N, K;
    // 读取总个数 N 和需要执行的扫描次数 K
    if (scanf("%d %d", &N, &K) != 2) return 0;

    int a[105];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // 冒泡排序：只执行 K 遍扫描
    for (int i = 0; i < K; i++) {
        // 每一遍扫描的范围是 [0, N-1-i)
        // 因为每扫描一遍，末尾就会多出一个排好序的最大值
        for (int j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // 交换相邻元素
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // 输出执行 K 遍后的中间结果
    for (int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if (i < N - 1) {
            printf(" "); // 数字之间用空格分隔
        }
    }
    printf("\n"); // 行末回车

    return 0;
}


//7-3
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 创建链表的函数，读取输入直到遇到 -1
Node* readList() {
    Node *head = (Node*)malloc(sizeof(Node)); // 头结点
    head->next = NULL;
    Node *rear = head;
    int val;
    while (scanf("%d", &val) && val != -1) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }
    return head;
}

// 合并两个有序链表的函数
Node* mergeLists(Node *L1, Node *L2) {
    Node *p1 = L1->next;
    Node *p2 = L2->next;
    Node *L3 = (Node*)malloc(sizeof(Node));
    L3->next = NULL;
    Node *rear = L3;

    while (p1 && p2) {
        if (p1->data <= p2->data) {
            rear->next = p1;
            p1 = p1->next;
        } else {
            rear->next = p2;
            p2 = p2->next;
        }
        rear = rear->next;
    }
    
    // 连接剩余部分
    rear->next = p1 ? p1 : p2;
    
    return L3;
}

// 打印链表
void printList(Node *L) {
    Node *p = L->next;
    if (!p) {
        printf("NULL\n");
        return;
    }
    int first = 1;
    while (p) {
        if (!first) printf(" ");
        printf("%d", p->data);
        first = 0;
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node *L1 = readList();
    Node *L2 = readList();
    
    Node *L3 = mergeLists(L1, L2);
    
    printList(L3);
    
    return 0;
}


//7-4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[14];
    int score;
    int location_number;
    int local_rank;
    int final_rank;
} Student;

// 比较函数：成绩降序，考号升序
int cmp(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    if (s1->score != s2->score) {
        return s2->score - s1->score;
    }
    return strcmp(s1->id, s2->id);
}

Student all_students[30005]; // 总人数最大 N*K = 100*300 = 30000

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int total_count = 0;
    for (int i = 1; i <= N; i++) {
        int K;
        scanf("%d", &K);
        int start_index = total_count;
        for (int j = 0; j < K; j++) {
            scanf("%s %d", all_students[total_count].id, &all_students[total_count].score);
            all_students[total_count].location_number = i;
            total_count++;
        }

        // 1. 对当前考点的学生进行局部排序
        qsort(&all_students[start_index], K, sizeof(Student), cmp);

        // 2. 计算考点内排名
        all_students[start_index].local_rank = 1;
        for (int j = 1; j < K; j++) {
            if (all_students[start_index + j].score == all_students[start_index + j - 1].score) {
                all_students[start_index + j].local_rank = all_students[start_index + j - 1].local_rank;
            } else {
                all_students[start_index + j].local_rank = j + 1;
            }
        }
    }

    // 3. 对所有学生进行全局排序
    qsort(all_students, total_count, sizeof(Student), cmp);

    // 4. 计算总排名并输出结果
    printf("%d\n", total_count);
    int current_final_rank = 1;
    for (int i = 0; i < total_count; i++) {
        if (i > 0 && all_students[i].score < all_students[i - 1].score) {
            current_final_rank = i + 1;
        }
        printf("%s %d %d %d\n", all_students[i].id, current_final_rank, 
               all_students[i].location_number, all_students[i].local_rank);
    }

    return 0;
}