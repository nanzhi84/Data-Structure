#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 节点定义
typedef struct Node {
  ele_type data;
  struct Node* next;
} Node;

// 栈的定义
typedef struct Stack {
  Node* head;
  size_t size;
} Stack;

v