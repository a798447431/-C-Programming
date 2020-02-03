/*************************************************************************
	> File Name: seqlisttest2.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年04月23日 星期二 10时17分20秒
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
    if (vector->length > vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; i++) {
        vector->data[i] = vector->data[i];
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
        if (i > 0) printf(" ");
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
    init(a, 20);
    int m;
    scanf("%d", &m);
    while (m--) {
        int t, p, q;
        scanf("%d", &t);
        switch (t) {
            case 1:
                scanf("%d%d", &p, &q);
                printf("%s\n", insert(a, p, q) == OK ? "success" : "failed ");
                break;
            case 2:
                scanf("%d", &p);
                printf("%s\n", delete_node(a, p) == OK ? "success" : "failed");
                break;
            case 3:
                scanf("%d", &p);
                printf("%s\n", search(a, p) == OK ? "success" : "failed");
                break;
            case 4:
                print(a);
                break;
            default :
                printf("ERROR\n");
			    break;
        }
    }
    clear(a);
    return 0;
}
