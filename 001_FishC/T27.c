#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void insertNode(struct Node **, int);

void printNode(struct Node *);

void insertNode(struct Node **head, int value) {
    struct Node *pre;
    struct Node *current;
    struct Node *new;
    current = *head;
    pre = NULL;
    while (current != NULL && current->value < value) {
        pre = current;
        current = current->next;
    }
    new = (struct Node *) malloc(sizeof(struct Node));
    if (new == NULL) {
        exit(1);
    }
    new->value = value;
    new->next = current;
    if (pre == NULL) {
        *head = new;
    } else {
        pre->next = new;
    }
}

void printNode(struct Node *head) {
    struct Node *current;
    current = head;
    while (current != NULL) {
        printf("%d-", current->value);
        current = current->next;
    }
    putchar('\n');
}

// 单链表
int main() {
    struct Node *head = NULL;
    int input;

    while (1) {
        printf("input num:");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        insertNode(&head, input);
        printNode(head);
    }

    return 0;
}
