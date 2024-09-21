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
  size_t size;
} Queue;

// 队列的初始化
void Queue_Init(Queue* q) {
  q->head = q->tail = NULL;
  q->size = 0;
  return;
}

// 队列的销毁
void Queue_Destroy(Queue* q) {
  while (q->head) {
    Node* tmp = q->head;
    q->head = q->head->next;
    free(tmp);
  }
  q->tail = NULL;
  q->size = 0;
  return;
}

// 入队
void Queue_Push(Queue* q, ele_type element) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = el
}