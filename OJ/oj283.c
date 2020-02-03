/*************************************************************************
	> File Name: oj283.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月22日 星期四 08时38分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 10
#define MAX_N 100000
#define BASE_LETTER '0'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
}Node;

Node tree[MAX_N + 5];

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, char *str) {
    Node *p = root;
    int i = 0;
    while (str[i]) {
        int ind = str[i] - BASE_LETTER;
        if (str[i + 1]) {
            if (p->next[ind] == NULL) p->next[ind] = getNewNode();
            else {
                if (p->next[ind]->flag == 1) {
                    return 0;
                }
            }
        }
        else {
            if (p->next[ind] != NULL) return 0;
            if (p->next[ind] == NULL) {
                p->next[ind] = getNewNode();
                p->next[ind]->flag = 1;
            } else {
                if (p->next[ind]->flag == 1) return 0;
            }
        }
        p = p->next[ind];
        ++i;
    }
    return 1;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    char str[MAX_N];
    int n;
    Node *root = getNewNode();
    int sign = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (insert(root, str) == 0) {
            sign = 0;
        }
    }
    if (sign != 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    clear(root);
    return 0;
}
