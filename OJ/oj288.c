/*************************************************************************
	> File Name: leetcode295.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月11日 星期日 14时05分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30000

#define swap(a, b) { \
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

int val[MAX_N + 5] = {0};

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init() {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->size = 100;
    q->data = (int *)malloc(sizeof(int) * q->size);
    q->cnt = 0;
    return q;
}

void expand(priority_queue *q) {
    q->data = realloc(q->data, 2 * q->size *sizeof(int));
    q->size *= 2;
    return ;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int big_push(priority_queue *q, int val) {
    if (q->size == q->cnt + 1) {
        expand(q);
    }
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind != 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int big_pop(priority_queue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

int small_push(priority_queue *q, int val) {
    if (q->size == q->cnt + 1) {
        expand(q);
    }
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind != 1 && q->data[ind] < q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int small_pop(priority_queue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[l] < q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] < q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    priority_queue *maxq = init();
    priority_queue *minq = init();
    for (int i = 1; i <= n; i++) {
        scanf("%d", val + i);
      //  printf("val[%d] = %d\n", i, val[i]);
    }
    for (int i = 1, j = 0; i <= m; i++) {
        int k;
        scanf("%d", &k);
       // printf("k = %d\n", k);
        while (j < k) {
            ++j;
           // printf("j = %d\n", j);
            if (empty(maxq) || top(maxq) > val[j]) {
                big_push(maxq, val[j]);
         //       printf("top(maxq) = %d\n", top(maxq));
            } else {
                small_push(minq, val[j]);
            }
        }
        while (maxq->cnt > i) {
            small_push(minq, top(maxq));
            big_pop(maxq);
        }
        while (maxq->cnt < i) {
            big_push(maxq, top(minq));
            small_pop(minq);
        }
        printf("%d\n", top(maxq));
    }
    return 0;
}
