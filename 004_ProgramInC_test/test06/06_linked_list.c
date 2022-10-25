#include <stdio.h>
#include <stdlib.h>
#include "include/io_utils.h"

// 定义节点结构体
typedef struct ListNode {
    // 节点的值
    int value;
    // 指向下一个节点的指针
    struct ListNode *next;
} ListNode;

// 创建节点
ListNode *CreateNode(int value) {
    // 节点分配内存空间
    ListNode *node = malloc(sizeof(ListNode));
    // 节点分配内存失败，直接退出
    if (!node) {
        exit(1);
    }
    // 初始化节点
    node->value = value;
    node->next = NULL;
    return node;
}

// 销毁节点
void DestroyNode(ListNode **node_ptr) {
    (*node_ptr)->next = NULL;
    free(*node_ptr);
    *node_ptr = NULL;
}

// 创建链表
ListNode *CreatList(int array[], int length) {
    if (length <= 0) {
        return NULL;
    }
    ListNode *head = CreateNode(array[0]);
    ListNode *current = head;
    for (int i = 1; i < length; ++i) {
        current->next = CreateNode(array[i]);
        current = current->next;
    }
    return head;
}

// 销毁链表
void DestroyList(ListNode **head) {
    if (!head || !(*head)) {
        return;
    }
    ListNode *current = *head;
    while (current) {
        ListNode *to_be_des = current;
        current = current->next;
        DestroyNode(&to_be_des);
    }
    *head = NULL;
}

void PrintList(ListNode *head) {
    while (head) {
        printf("%d-->", head->value);
        head = head->next;
    }
    printf("\n");
}

// 单链表的基本实现
int main() {
    int array[] = {0, 1, 2, 3, 4};
    ListNode *head = CreatList(array, 5);
    PrintList(head);
    DestroyList(&head);
    PRINT_HEX(head);
    return 0;
}
