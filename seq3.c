/*************************************************************************
	> File Name: seq3.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年04月27日 星期六 10时00分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define ERROR 1
#define OK 0

typedef struct Vector{
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size *= 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

void print(Vector *vector) {
    for (int i = 0; i < vector->length; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

void jiaoji(Vector *v1, Vector *v2, Vector *v3) {
    int i = 0, j = 0, k = 0;
    while (i < v1->length && j < v2->length) {
        if (v1->data[i] < v2->data[j]) {
            ++i;
        } else if (v1->data[i] > v2->data[j]) {
            ++j;
        } else {
            insert(v3, k++, v1->data[i]);
            ++i, ++j;
        }
    }
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    Vector *b = (Vector *)malloc(sizeof(Vector));
    Vector *c = (Vector *)malloc(sizeof(Vector));
    init(a, 100);
    init(b, 100);
    init(c, 100);
    int n, m, j, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        insert(a, i, m);
    }
    scanf("%d", &j);
    for (int i = 0; i < j; i++) {
        scanf("%d", &k);
        insert(b, i, k);
    }
    jiaoji(a, b, c);
    printf("%d\n", c->length);
    print(c);
    clear(a);
    clear(b);
    clear(c);
    return 0;
}
