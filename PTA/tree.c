//7-1
#include <stdio.h>

#define MaxTree 10
#define Null -1

struct TreeNode {
    char data;
    int left;
    int right;
} T1[MaxTree], T2[MaxTree];

// 构建树并返回根节点下标
int BuildTree(struct TreeNode T[]) {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) return Null;

    int check[MaxTree] = {0}; // 用于标记是否有父节点指向该节点
    char cl, cr;
    for (int i = 0; i < n; i++) {
        // 使用 " %c" 来跳过可能的空格或换行符
        scanf(" %c %c %c", &T[i].data, &cl, &cr);
        
        if (cl != '-') {
            T[i].left = cl - '0';
            check[T[i].left] = 1;
        } else {
            T[i].left = Null;
        }

        if (cr != '-') {
            T[i].right = cr - '0';
            check[T[i].right] = 1;
        } else {
            T[i].right = Null;
        }
    }

    // 寻找没有父节点的那个节点作为根
    for (int i = 0; i < n; i++) {
        if (!check[i]) return i;
    }
    return Null;
}

// 递归判断同构
int Isomorphic(int R1, int R2) {
    if (R1 == Null && R2 == Null) return 1; // 均为空
    if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null)) return 0; // 一空一不空
    if (T1[R1].data != T2[R2].data) return 0; // 根节点数据不同

    // 如果左子树都为空
    if (T1[R1].left == Null && T2[R2].left == Null)
        return Isomorphic(T1[R1].right, T2[R2].right);

    // 如果左子树不为空且数据相同，则无需交换
    if (((T1[R1].left != Null) && (T2[R2].left != Null)) &&
        (T1[T1[R1].left].data == T2[T2[R2].left].data)) {
        return (Isomorphic(T1[R1].left, T2[R2].left) &&
                Isomorphic(T1[R1].right, T2[R2].right));
    } else {
        // 否则，尝试左右交换判断
        return (Isomorphic(T1[R1].left, T2[R2].right) &&
                Isomorphic(T1[R1].right, T2[R2].left));
    }
}

int main() {
    int R1 = BuildTree(T1);
    int R2 = BuildTree(T2);

    if (Isomorphic(R1, R2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}

//7-2

#include <stdio.h>

int N;
int post_order[35]; // 存储输入的后序遍历序列
int tree[35];       // 存储构建好的树（层序下标）
int current = 0;    // 用于读取 post_order 的计数器

// 后序遍历填充函数
void build(int root) {
    if (root > N) return;

    // 递归左子树
    build(2 * root);
    // 递归右子树
    build(2 * root + 1);
    
    // 填充根节点：按照后序遍历的顺序从输入序列取值
    tree[root] = post_order[current++];
}

int main() {
    // 读取节点总数
    if (scanf("%d", &N) != 1) return 0;

    // 读取后序序列
    for (int i = 0; i < N; i++) {
        scanf("%d", &post_order[i]);
    }

    // 从根节点(下标1)开始构建
    build(1);

    // 输出层序遍历结果
    for (int i = 1; i <= N; i++) {
        printf("%d", tree[i]);
        if (i < N) {
            printf(" "); // 数字间用空格分隔，行末无空格
        }
    }
    printf("\n");

    return 0;
}

//7-3
#include <stdio.h>

int post[35], in[35];
int N;

// 递归函数：rootIdx为当前子树在后序中的根位置，inL/inR为当前子树在中序中的范围
void solve(int rootIdx, int inL, int inR) {
    if (inL > inR) return;

    // 后序序列的最后一个是根
    int rootVal = post[rootIdx];
    printf(" %d", rootVal); // 前序：根 -> 左 -> 右

    // 在中序中找到根节点的位置
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == rootVal) break;
    }

    // 计算右子树的节点个数
    int numRight = inR - k;

    // 递归左子树：
    // 后序中左子树根的位置 = 当前根位置 - 右子树节点数 - 1
    solve(rootIdx - numRight - 1, inL, k - 1);

    // 递归右子树：
    // 后序中右子树根的位置 = 当前根位置 - 1
    solve(rootIdx - 1, k + 1, inR);
}

int main() {
    if (scanf("%d", &N) != 1) return 0;

    for (int i = 0; i < N; i++) scanf("%d", &post[i]);
    for (int i = 0; i < N; i++) scanf("%d", &in[i]);

    printf("Preorder:");
    // 调用递归：初始根在后序序列的 N-1 位置，中序范围 0 到 N-1
    solve(N - 1, 0, N - 1);
    printf("\n");

    return 0;
}
