#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0, carry = 0;
    struct ListNode *head, *current, *newNode;
    current = (struct ListNode*)malloc(sizeof(struct ListNode));
    head = current;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        sum = carry + (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);
        carry = sum / 10;
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        current->next = newNode;
        current = current->next;
        l1 = (l1 == NULL ? NULL : l1->next);
        l2 = (l2 == NULL ? NULL : l2->next);
    }
    current->next = NULL;
    current = head->next;
    free(head);
    return current;
}

int main() {
    struct ListNode* one = NULL;
    one = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* two = NULL;
    two = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* three = NULL;
    three = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* four = NULL;
    four = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* five = NULL;
    five = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* six = NULL;
    six = (struct ListNode*)malloc(sizeof(struct ListNode));

    one->next = two; two->next = three; three->next = NULL;
    four->next = five; five->next = six; six->next = NULL;
    one->val = 2; two->val = 4; three->val = 3; four->val = 5; five->val = 6; six->val = 4;
    addTwoNumbers(one, four);
    return 0;
}