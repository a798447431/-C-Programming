/*************************************************************************
	> File Name: master.h
	> Author: 
	> Mail: 
	> Created Time: 2019年03月09日 星期六 18时08分59秒
 ************************************************************************/
#include "common.h"

typedef struct Node{
    struct sockaddr_in client_addr;
    struct Node *next;
}Node, *LinkedList;

int transip(char *sip, int *ip) {
    if (sip == NULL) return -1;
    
    cahr temp[4];
    int count = 0;
    while (1) {
        int index = 0;
        while(*sip != '\0' && *sip != '.' && count < 4) {
            temp[index++] = *sip;
            sip++;
        }
        if (index == 4) return -1;
        temp[index] = '\0';
        ip[count] = atoi(temp);
        count++;
        if (*sip == '\0') {
            if (count != 4) return -1;
        } else {
            sip++;
        }
    }
    return 0;
}


int insert(LinkedList head, Node *node) {
    Node *p;
    p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;
    return 1;
}

int find_min(int *sum, int ins) {
    int ans = 0;
    for (int i = 0; i < ins; i++) {
        if (*(sum + i) < *(sum + ans)){
            ans = i;
        }
    }
    return ans;
} 

void 


