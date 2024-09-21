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
  struct node* head;
  size_t size;
}LinkedList;

// 单向链表