#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 定义节点
typedef struct Node {
  ele_type data;
  struct Node* next;
} Node;

// 定义队列
typedef struct {
  Node* head;
  Node* tail;
  size_t 
} Queue;

// 队列的初始化
void Queue_Init(Queue* q) {
  q->head = q->tail = NULL;
  q->size = 0;
  return;
}