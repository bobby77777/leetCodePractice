#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n) {
    while(n != NULL) {
        if (n->next != NULL) printf("%2d --> ", n->data);
        else printf("%2d\n", n->data);
        n = n->next;
    }
}

void insertAfter(struct Node* prev_node, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void push(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void append(struct Node* n, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    while(n->next != NULL) {
        n = n->next;
    }
    n->next = new_node;
    new_node->next = NULL;
}

int main() {
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    append(head, 1);
    printList(head);
    append(head->next, 2);
    printList(head);
    insertAfter(head->next, 3);
    printList(head);
    return 0;
}