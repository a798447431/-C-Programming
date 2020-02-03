/*************************************************************************
	> File Name: seqlisttest.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年04月23日 星期二 09时29分29秒
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
    for (int i = 0; i < vector->size; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
    printf("expand\n");
}

int insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) {
        printf("failed\n");
        return ERROR;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->size; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    printf("success\n");
    return OK;
}


void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
    int n;
    scanf("%d", &n);
    while (n--) {
        int p, q;
        scanf("%d%d", &p, &q);
        insert(a, p, q);
    }
    return 0;
}
