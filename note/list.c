/*
 * C语言数据结构：线性表（List）章节示例
 * 文件名：list.c
 *
 * 线性表核心知识点总结：
 * 1) 定义：线性表是具有相同数据类型的 n (n>=0) 个数据元素的有限序列。
 * 2) 特点：
 *    - 逻辑上“前驱-后继”一对一（首元素无前驱，尾元素无后继）。
 *    - 可以为空表（n=0）。
 * 3) 常见存储结构：
 *    - 顺序存储（顺序表）：地址连续，支持随机访问，插删需要移动元素。
 *    - 链式存储（链表）：地址可不连续，插删方便，访问第 i 个元素需要遍历。
 * 4) 常见基本操作：
 *    - 初始化、判空、求长度
 *    - 按位查找、按值查找
 *    - 插入、删除、遍历输出
 * 5) 时间复杂度（典型）：
 *    - 顺序表：按位访问 O(1)，插入/删除平均 O(n)
 *    - 单链表：按位访问 O(n)，已知结点后插入/删除 O(1)
 */

#include <stdio.h>
#include <stdlib.h>

/* =========================
 * 一、顺序表（静态数组实现）
 * ========================= */

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;  // 当前元素个数
} SqList;

// 初始化顺序表
void InitSqList(SqList *L) {
    L->length = 0;
}

// 判空：空返回1，非空返回0
int EmptySqList(const SqList *L) {
    return L->length == 0;
}

// 在第 i 个位置插入元素 e（i 从 1 开始计数）
int ListInsertSq(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return 0;  // 插入位置非法
    }
    if (L->length >= MAXSIZE) {
        return 0;  // 表满
    }

    // 从后往前移动，为新元素腾位置
    for (int k = L->length; k >= i; --k) {
        L->data[k] = L->data[k - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return 1;
}

// 删除第 i 个元素，并通过 e 返回被删除值
int ListDeleteSq(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) {
        return 0;  // 删除位置非法
    }
    *e = L->data[i - 1];

    // 删除后前移补位
    for (int k = i; k < L->length; ++k) {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
    return 1;
}

// 按位查找：获取第 i 个元素值
int GetElemSq(const SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) {
        return 0;
    }
    *e = L->data[i - 1];
    return 1;
}

// 按值查找：返回首次出现的位置（从1开始），不存在返回0
int LocateElemSq(const SqList *L, ElemType e) {
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

void PrintSqList(const SqList *L) {
    printf("顺序表(length=%d): ", L->length);
    for (int i = 0; i < L->length; ++i) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

/* =========================
 * 二、单链表（带头结点）
 * ========================= */

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化单链表：创建头结点
int InitLinkList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL) {
        return 0;
    }
    (*L)->next = NULL;
    return 1;
}

// 在第 i 个位置插入元素 e（i 从1开始，指第1个数据结点位置）
int ListInsertL(LinkList L, int i, ElemType e) {
    if (i < 1) {
        return 0;
    }

    LNode *p = L;
    int j = 0;

    // 找到第 i-1 个结点（头结点记作第0个）
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return 0;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return 0;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

// 删除第 i 个数据结点，并返回被删值
int ListDeleteL(LinkList L, int i, ElemType *e) {
    if (i < 1) {
        return 0;
    }

    LNode *p = L;
    int j = 0;

    // 找到第 i-1 个结点
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL) {
        return 0;
    }

    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 按位查找：获取第 i 个数据结点的值
int GetElemL(LinkList L, int i, ElemType *e) {
    if (i < 1) {
        return 0;
    }

    LNode *p = L->next;
    int j = 1;

    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return 0;
    }

    *e = p->data;
    return 1;
}

// 按值查找：返回首次出现的位置（从1开始），不存在返回0
int LocateElemL(LinkList L, ElemType e) {
    LNode *p = L->next;
    int pos = 1;

    while (p != NULL) {
        if (p->data == e) {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return 0;
}

void PrintLinkList(LinkList L) {
    printf("单链表: ");
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void DestroyLinkList(LinkList *L) {
    LNode *p = *L;
    while (p != NULL) {
        LNode *temp = p;
        p = p->next;
        free(temp);
    }
    *L = NULL;
}

/* =========================
 * 三、测试与示例
 * ========================= */

int main(void) {
    // ---------- 顺序表示例 ----------
    SqList sq;
    InitSqList(&sq);

    ListInsertSq(&sq, 1, 10);
    ListInsertSq(&sq, 2, 20);
    ListInsertSq(&sq, 3, 30);
    ListInsertSq(&sq, 2, 15);  // 在第2位插入15

    PrintSqList(&sq);

    ElemType x;
    if (GetElemSq(&sq, 3, &x)) {
        printf("顺序表第3个元素 = %d\n", x);
    }
    printf("元素20在顺序表中的位置 = %d\n", LocateElemSq(&sq, 20));

    if (ListDeleteSq(&sq, 2, &x)) {
        printf("顺序表删除第2个元素，删除值 = %d\n", x);
    }
    PrintSqList(&sq);

    printf("\n");

    // ---------- 单链表示例 ----------
    LinkList L;
    if (!InitLinkList(&L)) {
        printf("单链表初始化失败\n");
        return 1;
    }

    ListInsertL(L, 1, 100);
    ListInsertL(L, 2, 200);
    ListInsertL(L, 3, 300);
    ListInsertL(L, 2, 150);  // 在第2位插入150

    PrintLinkList(L);

    if (GetElemL(L, 3, &x)) {
        printf("单链表第3个元素 = %d\n", x);
    }
    printf("元素200在单链表中的位置 = %d\n", LocateElemL(L, 200));

    if (ListDeleteL(L, 2, &x)) {
        printf("单链表删除第2个元素，删除值 = %d\n", x);
    }
    PrintLinkList(L);

    DestroyLinkList(&L);
    return 0;
}
