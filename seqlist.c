/*************************************************************************
	> File Name: seqlist.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年04月21日 星期日 10时39分13秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

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

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int delete_node(Vector *vector, int index) {
    if (index < 0 || index >= vector->length) {
        return ERROR;
    }
    for (int i = index + 1; i < vector->length; i++) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length--;
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

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 100);
    printf("%d\n", insert(a, 1, 0));
    printf("%d\n", insert(a, 0, 1));
    printf("%d\n", insert(a, 2, 1));
    printf("%d\n", insert(a, 1, 2));
    printf("%d\n", insert(a, 0, 3));
    printf("%d\n", insert(a, 0, 1));
    printf("%d\n", insert(a, 0, 2));
    print(a);
    printf("%d\n", delete_node(a, 1));
    print(a);
    printf("%d\n", search(a, 0));
    printf("%d\n", search(a, 1));
    clear(a);
    return 0;
}
