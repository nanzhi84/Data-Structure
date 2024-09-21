#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 节点
typedef struct Node {
  ele_type data;
  struct Node* next;
} Node;

typedef struct Stack {
  Node* head;
  size_t size;
} Stack;

