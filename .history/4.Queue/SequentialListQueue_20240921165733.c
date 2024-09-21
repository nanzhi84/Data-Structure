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
    exit(1); // 内存分配失败,停止程序
  }
  q->elements = new_elements;
  q->capacity *= 2;
  return;
}

// 入队
void Queue_Push(Queue* q, ele_type element) {
  if (q->tail == q->capacity) {
    Queue_Resize(q);
  }
  q->elements[q->tail++] = element;
  return;
}

// 出队
ele_type Queue_Pop(Queue* q) {
  if (q->head == q->tail) {
    printf("队列为空\n");
    exit(1);
  }
  return q->elements[q->head++];
}

// 获取队首元素
ele_type Queue_Head(Queue* q) {
  if (q->head == q->tail) {
    printf("队列为空\n");
    exit(1);
  }
  return q->elements[q->head];
}

// 获取队列大小
size_t Queue_Size(Queue* q) {
  return q->tail - q->head;
}

// 实验
int main() {
  Queue q;
  Queue(&q);
  QueuePush(&q, 10);
  QueuePush(&q, 20);
  QueuePush(&q, 30);
  printf("出队元素: %d\n", QueuePop(&q));
  printf("队头元素: %d\n", QueueFront(&q));
  printf("队列大小: %zu\n", QueueSize(&q));
  QueueDestroy(&q);

  return 0;
}