/*************************************************************************
	> File Name: oj287.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月12日 星期一 21时22分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * n + 1);
    q->cnt = 0, q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt = 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

void push(priority_queue *q, int val) {
    if (q->size == q->cnt) return ;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind != 1 && q->data[ind] < q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

void pop(priority_queue *q) {
    if (empty(q)) return ;
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
    return ;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    int n, a, sum = 0;
    scanf("%d", &n);
    priority_queue *q = init(n - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        push(q, a);
        printf("%d ", a);
    }
    for (int i = 1; i < n; i++) {
        int val1 = top(q); pop(q);
        printf("%d\n", top(q));
        printf("val1 = %d\n", val1);
        int val2 = top(q); pop(q);
        printf("val2 = %d\n", val2);
        push(q, (val1 + val2));
        sum += val1 + val2;
    }
    printf("%d\n", sum);
    clear(q);
    return 0;
}

