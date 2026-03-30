/*7-1汉诺塔的非递归实现

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	char from;
	char aux;
	char to;
	int state;
} Frame;

int main() {
	int n;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	Frame *stack = (Frame *)malloc((n + 5) * sizeof(Frame));
	if (stack == NULL) {
		return 0;
	}

	int top = -1;
	stack[++top] = (Frame){n, 'a', 'b', 'c', 0};

	while (top >= 0) {
		Frame *cur = &stack[top];

		if (cur->n == 1) {
			printf("%c -> %c\n", cur->from, cur->to);
			top--;
			continue;
		}

		if (cur->state == 0) {
			cur->state = 1;
			stack[++top] = (Frame){cur->n - 1, cur->from, cur->to, cur->aux, 0};
		} else if (cur->state == 1) {
			printf("%c -> %c\n", cur->from, cur->to);
			cur->state = 2;
			stack[++top] = (Frame){cur->n - 1, cur->aux, cur->from, cur->to, 0};
		} else {
			top--;
		}
	}

	free(stack);
	return 0;
}
*/
/*7-2出栈序列的合法性
#include <stdio.h>

int main() {
	int m, n, k;
	if (scanf("%d %d %d", &m, &n, &k) != 3) {
		return 0;
	}

	int stack[1005];
	int seq[1005];

	for (int t = 0; t < k; t++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &seq[i]);
		}

		int top = -1;
		int next_push = 1;
		int ok = 1;

		for (int i = 0; i < n; i++) {
			int target = seq[i];

			while ((top == -1 || stack[top] != target) && next_push <= n) {
				if (top + 1 >= m) {
					ok = 0;
					break;
				}
				stack[++top] = next_push++;
			}

			if (!ok) {
				break;
			}

			if (top >= 0 && stack[top] == target) {
				top--;
			} else {
				ok = 0;
				break;
			}
		}

		if (ok) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
*/
/*7-3简单计数器
#include <stdio.h>

int main() {
	int n;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	long long s1[1005];
	char s2[1005];
	int top1 = -1, top2 = -1;

	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		s1[++top1] = x;
	}

	for (int i = 0; i < n - 1; i++) {
		char op;
		scanf(" %c", &op);
		s2[++top2] = op;
	}

	while (top2 >= 0) {
		long long n1 = s1[top1--];
		long long n2 = s1[top1--];
		char op = s2[top2--];

		long long res;
		if (op == '+') {
			res = n2 + n1;
		} else if (op == '-') {
			res = n2 - n1;
		} else if (op == '*') {
			res = n2 * n1;
		} else {
			if (n1 == 0) {
				printf("ERROR: %lld/0\n", n2);
				return 0;
			}
			res = n2 / n1;
		}

		s1[++top1] = res;
	}

	printf("%lld\n", s1[top1]);
	return 0;
}
*/
/*7-4盲盒包装流水线
#include <stdio.h>

#define MAX_CODE 100000
#define MAX_N 100000

int main() {
	int n, s;
	if (scanf("%d %d", &n, &s) != 2) {
		return 0;
	}

	int box[MAX_N];
	for (int i = 0; i < n; i++) {
		scanf("%d", &box[i]);
	}

	int badge_of_code[MAX_CODE];
	int exist[MAX_CODE] = {0};
	for (int i = 0; i < MAX_CODE; i++) {
		badge_of_code[i] = -1;
	}

	int in_batch[105];
	int batches = n / s;
	for (int b = 0; b < batches; b++) {
		for (int i = 0; i < s; i++) {
			scanf("%d", &in_batch[i]);
		}

		for (int i = 0; i < s; i++) {
			int code = box[b * s + i];
			int badge = in_batch[s - 1 - i];
			if (code >= 0 && code < MAX_CODE) {
				badge_of_code[code] = badge;
				exist[code] = 1;
			}
		}
	}

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int q;
		scanf("%d", &q);
		if (q >= 0 && q < MAX_CODE && exist[q]) {
			printf("%d\n", badge_of_code[q]);
		} else {
			printf("Wrong Number\n");
		}
	}

	return 0;
}
*/