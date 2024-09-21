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
ele_type Queue_head(Queue* q) {
  if (q->head == NULL) {
    printf("队列为空\n");
    exit(1);
  }
  return q->head->data;
}

// 获取队列大小
size_t Queue_Size(Queue* q) {
  return q->size;
}

#include <stdio.
int main() {
  Queue q;

  // 初始化队列
  Queue_Init(&q);

  // 测试入队
  printf("入队 10, 20, 30\n");
  Queue_Push(&q, 10);
  Queue_Push(&q, 20);
  Queue_Push(&q, 30);

  // 测试队首元素
  printf("队首元素: %d\n", Queue_head(&q));  // 应该输出 10

  // 测试队列大小
  printf("队列大小: %zu\n", Queue_Size(&q));  // 应该输出 3

  // 测试出队
  printf("出队: %d\n", Queue_Pop(&q));  // 应该输出 10
  printf("出队: %d\n", Queue_Pop(&q));  // 应该输出 20

  // 再次检查队首元素
  printf("队首元素: %d\n", Queue_head(&q));  // 应该输出 30

  // 检查队列大小
  printf("队列大小: %zu\n", Queue_Size(&q));  // 应该输出 1

  // 出队剩余的元素
  printf("出队: %d\n", Queue_Pop(&q));  // 应该输出 30

  // 检查队列是否为空
  printf("队列大小: %zu\n", Queue_Size(&q));  // 应该输出 0

  // 销毁队列
  Queue_Destroy(&q);

  return 0;
}