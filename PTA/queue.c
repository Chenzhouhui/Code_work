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
/*7-2window消息队列*/

#include <stdio.h>
#include <string.h>

typedef struct {
	char name[12];
	int priority;
	int order;
} Msg;

void swap(Msg *a, Msg *b) {
	Msg t = *a;
	*a = *b;
	*b = t;
}

void heap_push(Msg heap[], int *size, Msg x) {
	int i = ++(*size);
	heap[i] = x;
	while (i > 1) {
		int p = i / 2;
		if (heap[p].priority < heap[i].priority ||
			(heap[p].priority == heap[i].priority && heap[p].order < heap[i].order)) {
			break;
		}
		swap(&heap[p], &heap[i]);
		i = p;
	}
}

Msg heap_pop(Msg heap[], int *size) {
	Msg top = heap[1];
	heap[1] = heap[*size];
	(*size)--;

	int i = 1;
	while (1) {
		int l = i * 2;
		int r = l + 1;
		int best = i;

		if (l <= *size && (heap[l].priority < heap[best].priority ||
			(heap[l].priority == heap[best].priority && heap[l].order < heap[best].order))) {
			best = l;
		}
		if (r <= *size && (heap[r].priority < heap[best].priority ||
			(heap[r].priority == heap[best].priority && heap[r].order < heap[best].order))) {
			best = r;
		}
		if (best == i) {
			break;
		}
		swap(&heap[i], &heap[best]);
		i = best;
	}

	return top;
}

int main() {
	int n;
	if (scanf("%d", &n) != 1) {
		return 0;
	}

	Msg heap[100005];
	int size = 0;
	int timer = 0;

	for (int i = 0; i < n; i++) {
		char cmd[8];
		scanf("%s", cmd);

		if (strcmp(cmd, "PUT") == 0) {
			Msg x;
			scanf("%s %d", x.name, &x.priority);
			x.order = timer++;
			heap_push(heap, &size, x);
		} else {
			if (size == 0) {
				printf("EMPTY QUEUE!\n");
			} else {
				Msg x = heap_pop(heap, &size);
				printf("%s %d\n", x.name, x.priority);
			}
		}
	}

	return 0;
}
