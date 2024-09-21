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
  new_node->data = element;
  new_node->next = NULL;

  if (q->tail == NULL) {
    q->head = q->tail = new_node;
  }
  else {
    q->tail->next = new_node;
    q->tail = new_node;
  }
  q->size++;
  return;
}

// 出队
ele_type Queue_Pop(Queue* q) {
  if (q->head == NULL) {
    printf("队列为空\n");
    exit(1);
  }

  ele_type element = q->head->data;
  Node* tmp = q->head;
  q->head = q->head->next;
  free(tmp);
  q->size--;
  if (q->size == 0) {
    q->tail = NULL;
  }
  return element;
}

// 获取队首元素
ele_type Queue_head(Queue* q)