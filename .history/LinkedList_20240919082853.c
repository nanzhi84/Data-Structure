#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 定义单向链表节点
typedef struct node {
  ele_type data;
  struct node* next;
}node;

// 定义单向链表
typedef struct 