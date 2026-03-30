/*7-1重排链表*/

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
