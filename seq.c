/*************************************************************************
	> File Name: seq.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年04月26日 星期五 18时12分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
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
    vector->size = vector->size * 2;
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

int leftmove(Vector *vector, int index) {
    if (index < 0) {
        return ERROR;
    }
    int *temp_data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < index; i++) {
        temp_data[i] = vector->data[i];
        
    }
    for (int i = 0; i < vector->length - index; i++) {
        vector->data[i] = vector->data[i + index];
    }
    for (int i = 0; i < index; i++) {
        vector->data[vector->length - index + i] = temp_data[i];
    }
    return OK;
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 100);
    int n, m, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        insert(a, i, m);
    }
    leftmove(a, k);
    print(a);
    return 0;
}
