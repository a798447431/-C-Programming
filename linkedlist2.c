/*************************************************************************
	> File Name: linkedlist2.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年04月23日 星期二 16时13分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) return head;
        head = node;
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
    }
    return head;
}

void output(LinkedList head) {
    if (head == NULL) {
szt@szt-PC:/home/szt/haizei/Homework/123        return ;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d "szt@szt-PC:/home/szt/haizei/Homework/123, current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList delete_node(LinkedList head, int index) {
szt@szt-PC:/home/szt/haizei/Homework/123    if (head == NULL) {
        return head;
    }
    Node *current_node = head;
    int count = 0;
    if (index == 0) {
        head= head->next;
        free(current_node);
        return head;
    }
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
    }
    return head;
}

LinkedList reverse(LinkedList head) {
    if (head == NULL) {
        return head;
    }
    Node *next_node, *current_node;
    current_node = head->next;
    head->next = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d", &n);
    while (n--) {
        int p, q;
        scanf("%d%d", &p, &q);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = q;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, p);
    }
    output(linkedlist);
    linkedlist = delete_node(linkedlist, 3);
    output(linkedlist);
    linkedlist = reverse(linkedlist);
    output(linkedlist);
    clear(linkedlist);
    return 0;
}
