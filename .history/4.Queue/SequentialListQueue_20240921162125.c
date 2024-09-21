#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 队列的定义
typedef struct {
  ele_type* element;
  size_t head;
  size_t tail;
  size_t capacity;
} Queue;

// 队列的初始化
void Queue_Init(Queue* q, size_t capacity) {
  q->element = (ele_type*)malloc(sizeof(ele_type) * capacity);
  q->head = 0;
  q->tail = 0;
  q->capacity = capacity;
  return;
}

// 队列的销毁
void Queue_Destroy(Queue)