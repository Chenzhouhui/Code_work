/*7-1重排链表
#include <stdio.h>

#define MAX_ADDR 100000

typedef struct {
	int data;
	int next;
	int exists;
} Node;

int main() {
	int start, n;
	if (scanf("%d %d", &start, &n) != 2) {
		return 0;
	}

	Node nodes[MAX_ADDR] = {0};
	for (int i = 0; i < n; i++) {
		int addr, data, next;
		scanf("%d %d %d", &addr, &data, &next);
		nodes[addr].data = data;
		nodes[addr].next = next;
		nodes[addr].exists = 1;
	}

	int order[MAX_ADDR];
	int len = 0;
	int p = start;
	while (p != -1 && p >= 0 && p < MAX_ADDR && nodes[p].exists) {
		order[len++] = p;
		p = nodes[p].next;
	}

	int rearr[MAX_ADDR];
	int left = 0, right = len - 1, idx = 0;
	while (left <= right) {
		rearr[idx++] = order[right--];
		if (left <= right) {
			rearr[idx++] = order[left++];
		}
	}

	for (int i = 0; i < len; i++) {
		int addr = rearr[i];
		int next = (i == len - 1) ? -1 : rearr[i + 1];
		if (next == -1) {
			printf("%05d %d -1\n", addr, nodes[addr].data);
		} else {
			printf("%05d %d %05d\n", addr, nodes[addr].data, next);
		}
	}

	return 0;
}
*/
/*7-2链表去重
#include <stdio.h>
#include <stdlib.h>

#define MAX_ADDR 100000
#define MAX_ABS 10000

typedef struct {
	int key;
	int next;
	int exists;
} Node;

void print_list(int arr[], int len, Node nodes[]) {
	for (int i = 0; i < len; i++) {
		int addr = arr[i];
		int next = (i == len - 1) ? -1 : arr[i + 1];
		if (next == -1) {
			printf("%05d %d -1\n", addr, nodes[addr].key);
		} else {
			printf("%05d %d %05d\n", addr, nodes[addr].key, next);
		}
	}
}

int main() {
	int start, n;
	if (scanf("%d %d", &start, &n) != 2) {
		return 0;
	}

	Node nodes[MAX_ADDR] = {0};
	for (int i = 0; i < n; i++) {
		int addr, key, next;
		scanf("%d %d %d", &addr, &key, &next);
		nodes[addr].key = key;
		nodes[addr].next = next;
		nodes[addr].exists = 1;
	}

	int kept[MAX_ADDR], removed[MAX_ADDR];
	int kept_len = 0, removed_len = 0;
	int seen[MAX_ABS + 1] = {0};

	int p = start;
	while (p != -1 && p >= 0 && p < MAX_ADDR && nodes[p].exists) {
		int v = abs(nodes[p].key);
		if (!seen[v]) {
			seen[v] = 1;
			kept[kept_len++] = p;
		} else {
			removed[removed_len++] = p;
		}
		p = nodes[p].next;
	}

	print_list(kept, kept_len, nodes);
	print_list(removed, removed_len, nodes);

	return 0;
}
*/
/*两个有序链表序列的合并
#include <stdio.h>
#include <stdlib.h>

int main() {
	int cap_a = 16, cap_b = 16;
	int *a = (int *)malloc(sizeof(int) * cap_a);
	int *b = (int *)malloc(sizeof(int) * cap_b);
	int n = 0, m = 0;
	int x;

	if (a == NULL || b == NULL) {
		free(a);
		free(b);
		return 0;
	}

	while (scanf("%d", &x) == 1) {
		if (x == -1) {
			break;
		}
		if (n == cap_a) {
			cap_a *= 2;
			int *tmp = (int *)realloc(a, sizeof(int) * cap_a);
			if (tmp == NULL) {
				free(a);
				free(b);
				return 0;
			}
			a = tmp;
		}
		a[n++] = x;
	}

	while (scanf("%d", &x) == 1) {
		if (x == -1) {
			break;
		}
		if (m == cap_b) {
			cap_b *= 2;
			int *tmp = (int *)realloc(b, sizeof(int) * cap_b);
			if (tmp == NULL) {
				free(a);
				free(b);
				return 0;
			}
			b = tmp;
		}
		b[m++] = x;
	}

	if (n == 0 && m == 0) {
		printf("NULL\n");
		free(a);
		free(b);
		return 0;
	}

	int i = 0, j = 0;
	int first = 1;
	while (i < n && j < m) {
		int out;
		if (a[i] <= b[j]) {
			out = a[i++];
		} else {
			out = b[j++];
		}

		if (!first) {
			printf(" ");
		}
		printf("%d", out);
		first = 0;
	}

	while (i < n) {
		if (!first) {
			printf(" ");
		}
		printf("%d", a[i++]);
		first = 0;
	}

	while (j < m) {
		if (!first) {
			printf(" ");
		}
		printf("%d", b[j++]);
		first = 0;
	}

	printf("\n");
	free(a);
	free(b);
	return 0;
}
*/
/*两个有序链表序列的交集
#include <stdio.h>
#include <stdlib.h>

int main() {
	int cap_a = 16, cap_b = 16;
	int *a = (int *)malloc(sizeof(int) * cap_a);
	int *b = (int *)malloc(sizeof(int) * cap_b);
	int n = 0, m = 0;
	int x;

	if (a == NULL || b == NULL) {
		free(a);
		free(b);
		return 0;
	}

	while (scanf("%d", &x) == 1) {
		if (x == -1) {
			break;
		}
		if (n == cap_a) {
			cap_a *= 2;
			int *tmp = (int *)realloc(a, sizeof(int) * cap_a);
			if (tmp == NULL) {
				free(a);
				free(b);
				return 0;
			}
			a = tmp;
		}
		a[n++] = x;
	}

	while (scanf("%d", &x) == 1) {
		if (x == -1) {
			break;
		}
		if (m == cap_b) {
			cap_b *= 2;
			int *tmp = (int *)realloc(b, sizeof(int) * cap_b);
			if (tmp == NULL) {
				free(a);
				free(b);
				return 0;
			}
			b = tmp;
		}
		b[m++] = x;
	}

	int i = 0, j = 0;
	int printed = 0;
	while (i < n && j < m) {
		if (a[i] == b[j]) {
			if (printed) {
				printf(" ");
			}
			printf("%d", a[i]);
			printed = 1;
			i++;
			j++;
		} else if (a[i] < b[j]) {
			i++;
		} else {
			j++;
		}
	}

	if (!printed) {
		printf("NULL");
	}
	printf("\n");

	free(a);
	free(b);
	return 0;
}
*/
