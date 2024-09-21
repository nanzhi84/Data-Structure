#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 定义节点
typedef struct Node {
  ele_type data;
  struct Node* next;
} Node;

// ding'y
typedef struct {
  Node* head;
  Node* tail;
} Queue;

