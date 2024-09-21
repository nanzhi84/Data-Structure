#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 单向链表节点定义
typedef struct LinkedNode {
  ele_type data;
  struct node* next;
}LinkedNode;

// 单向链表定义
typedef struct LinkedList {
  struct LinkedNode* head;
  size_t size;
}LinkedList;

// 单向链表的创建
void LinkedList_Init(LinkedList* list) {
  list->head = NULL;
  list->size = 0;
  return;
}

// 单向链表的销毁
void LinkedList_Destroy(LinkedList* list) {
  while (list->head) {
    LinkedNode* tmp = list->head;
    LinkedList* next = list->head->next;
    list->head = next;
    free(tmp);
  }
  list->size = 0;
  return
}