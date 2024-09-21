#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 队列的定义
typedef struct {
  ele_type* elements;
  size_t head;
  size_t tail;
  size_t capacity;
} Queue;

// 队列的初始化
void Queue_Init(Queue* q, size_t capacity) {
  q->elements = (ele_type*)malloc(sizeof(ele_type) * capacity);
  q->head = 0;
  q->tail = 0;
  q->capacity = capacity;
  return;
}

// 队列的销毁
void Queue_Destroy(Queue* q) {
  free(q->elements);
  q->elements = NULL;
  q->head = 0;
  q->tail = 0;
  q->capacity = 0;
  return;
}

// 队列的扩容
void Queue_Resize(Queue* q) {
  ele_type new_elements = (ele_type*)realloc(q->elements, q->capacity * 2);
  if (new_elements == NULL) {
    exit(1) // 内存
  }
}