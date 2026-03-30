/*7-1银行业务队列模拟
#include <stdio.h>

int main() {
	int n;
	if (scanf("%d", &n) != 1) {
		return 0;
	}

	int a[1005], b[1005];
	int na = 0, nb = 0;

	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d", &id);
		if (id % 2 == 1) {
			a[na++] = id;
		} else {
			b[nb++] = id;
		}
	}

	int ia = 0, ib = 0;
	int turn = 0;
	int first = 1;

	while (ia < na || ib < nb) {
		int out;
		int ok = 0;

		if (turn == 0 || turn == 1) {
			if (ia < na) {
				out = a[ia++];
				ok = 1;
			} else if (ib < nb) {
				out = b[ib++];
				ok = 1;
			}
		} else {
			if (ib < nb) {
				out = b[ib++];
				ok = 1;
			} else if (ia < na) {
				out = a[ia++];
				ok = 1;
			}
		}

		if (ok) {
			if (!first) {
				printf(" ");
			}
			printf("%d", out);
			first = 0;
		}

		turn = (turn + 1) % 3;
	}

	printf("\n");
	return 0;
}
*/
/*7-2window消息队列
#include <stdio.h>
#include <string.h>

#define MAX_N 100005

typedef struct {
    char name[15];
    int priority;
} Message;

Message heap[MAX_N];
int size = 0;

// 向上调整堆
void push(char* name, int priority) {
    size++;
    int i = size;
    // 寻找插入位置（小顶堆）
    while (i > 1 && heap[i / 2].priority > priority) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    strcpy(heap[i].name, name);
    heap[i].priority = priority;
}

// 向下调整堆
void pop() {
    if (size == 0) {
        printf("EMPTY QUEUE!\n");
        return;
    }
    printf("%s\n", heap[1].name);

    Message last = heap[size--];
    int parent = 1, child;
    while (parent * 2 <= size) {
        child = parent * 2;
        if (child < size && heap[child + 1].priority < heap[child].priority) {
            child++;
        }
        if (last.priority <= heap[child].priority) break;
        heap[parent] = heap[child];
        parent = child;
    }
    if (size >= 0) heap[parent] = last;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[5];
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "PUT") == 0) {
            char name[15];
            int p;
            scanf("%s %d", name, &p);
            push(name, p);
        } else {
            pop();
        }
    }
    return 0;
}
*/
/*7-3银行排队问题之单队列多窗口服务
#include <stdio.h>

int main() {
    int N, K;
    if (scanf("%d", &N) != 1) return 0;

    int T[1005], P[1005];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &T[i], &P[i]);
        if (P[i] > 60) P[i] = 60; 
    }
    scanf("%d", &K);

    int win_finish[15] = {0}; // 窗口空闲时间
    int win_count[15] = {0};  // 窗口服务人数
    int total_wait = 0;
    int max_wait = 0;

    for (int i = 0; i < N; i++) {
        int target_win = -1;
        int min_finish_time = 2e9; // 找最早结束时间

        // 1. 优先找序号最小且已经空闲的窗口
        for (int j = 0; j < K; j++) {
            if (win_finish[j] <= T[i]) {
                target_win = j;
                break;
            }
        }

        // 2. 如果都在忙，找最早结束的窗口
        if (target_win == -1) {
            for (int j = 0; j < K; j++) {
                if (win_finish[j] < min_finish_time) {
                    min_finish_time = win_finish[j];
                    target_win = j;
                }
            }
        }

        // 3. 计算等待和更新
        int start_time;
        if (win_finish[target_win] <= T[i]) {
            start_time = T[i];
        } else {
            start_time = win_finish[target_win];
            int wait = start_time - T[i];
            total_wait += wait;
            if (wait > max_wait) max_wait = wait;
        }

        win_finish[target_win] = start_time + P[i];
        win_count[target_win]++;
    }

    // 4. 计算最后完成时间
    int last_finish = 0;
    for (int j = 0; j < K; j++) {
        if (win_finish[j] > last_finish) last_finish = win_finish[j];
    }

    // 输出结果
    printf("%.1f %d %d\n", (double)total_wait / N, max_wait, last_finish);
    for (int j = 0; j < K; j++) {
        printf("%d%c", win_count[j], (j == K - 1 ? '\n' : ' '));
    }

    return 0;
}
*/
/*7-4列车调度*/
#include <stdio.h>

int main() {
    int n;
    // 读取列车总数
    if (scanf("%d", &n) != 1) return 0;

    // tails 数组记录每条轨道末尾火车的编号
    // 在贪心替换的过程中，tails 数组会自然保持升序
    int tails[100005];
    int count = 0; // 当前开启的轨道总数

    for (int i = 0; i < n; i++) {
        int train;
        scanf("%d", &train);

        // 使用二分查找在 tails 中找到第一个大于 train 的数
        int low = 0, high = count - 1;
        int pos = count; // 初始假设找不到（需要开新轨道）

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tails[mid] > train) {
                pos = mid;    // 找到了一个候选轨道
                high = mid - 1; // 继续向左找更小的“大于 train 的数”
            } else {
                low = mid + 1;
            }
        }

        if (pos == count) {
            // 没找到大于 train 的数，必须新开一条轨道
            tails[count++] = train;
        } else {
            // 找到了，更新该轨道的末尾值为这辆更小的火车
            tails[pos] = train;
        }
    }

    // 最后 count 的值就是所需的最少轨道数
    printf("%d\n", count);

    return 0;
}