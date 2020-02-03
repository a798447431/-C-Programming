/*************************************************************************
	> File Name: oj284.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月12日 星期一 22时15分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10000

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

struct Data {
    int p, d;
} arr[MAX_N + 5];

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0, q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q->cnt == q->size) return 0;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] < q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >> 1;
    }
    return 1;
}

int pop(priority_queue *q) {
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

void merge_sort(Data *num, int l, int r) { 
    if (r - l <= 1) { 
        if (r - l == 1 && num[l].d > num[r].d) {
            swap(num[l].d, num[r].d);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (Data *)malloc(sizeof(Data) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1].d <= num[p2].d)) {
            temp[k++].d = num[p1++].d;
        } else {
            temp[k++].d = num[p2++].d;
        }
    }
    memcpy(num + l, temp, sizeof(Data) * (r - l + 1));
    free(temp);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    priority_queue *q = init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", arr[i].p, arr[i].d);
    }
    merge_sort(arr, 0, n);
    for (int i = 0; i < n; i++) {
        if (arr[i].d > q->cnt) {
            push(q, arr[i].p);
        } else if (arr[i].p > top(q)) {
            pop(q);
            push(q, arr[i].p);
        }
    }
    int sum = 0;
    for ()
    return 0;
}

