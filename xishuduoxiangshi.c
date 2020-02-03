/*************************************************************************
	> File Name: xishuduoxiangshi.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月12日 星期日 11时21分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int c, e;
} P;

typedef struct Vector {
    P *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    vector->size = n;
    vector->data = (P*)malloc(sizeof(P) * n);
    if (vector->data == NULL) {
        return 0;
    }
    vector->length = 0;
    return vector;
}

void expand(Vector *vector) {
    vector->size = vector->size * 2;
    vector->data = realloc(vector->data, vector->size * sizeof(P));
    return ;
}

int insert(Vector *vector, int loc, P value) {
    if (loc < 0 || loc > vector->size) {
        return 0;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return 1;
}

void output(Vector *vector, int x) {
    int result = 0;
    for (int i = 0; i < vector->length; i++) {
        result += vector->data[i].c * (int)pow(x, vector->data[i].e);
    }
    printf("%d\n", result);
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    P data;
    int m, x;
    scanf("%d", &m);
    Vector *vector = init(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &data.c, &data.e);
        insert(vector, i, data);
    }
    scanf("%d", &x);
    output(vector, x);
    clear(vector);
    return 0;
}
