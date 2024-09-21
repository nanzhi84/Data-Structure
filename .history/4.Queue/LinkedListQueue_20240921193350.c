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

// 实验部分：性能和正确性测试
int main() {
  Queue q;
  size_t initial_capacity = 1;
  Queue_Init(&q, initial_capacity);

  // 测试1：基础功能测试
  printf("==== 基础功能测试 ====\n");
  Queue_Push(&q, 10);
  Queue_Push(&q, 20);
  Queue_Push(&q, 30);
  printf("出队元素: %d\n", Queue_Pop(&q));
  printf("队头元素: %d\n", Queue_Head(&q));
  printf("队列大小: %zu\n", Queue_Size(&q));

  // 测试2：边界测试（空队列情况下的操作）
  printf("\n==== 边界测试 ====\n");
  while (Queue_Size(&q) > 0) {
    printf("出队元素: %d\n", Queue_Pop(&q));
  }
  // 试图从空队列出队，应当报错
  printf("尝试从空队列出队...\n");
  // Queue_Pop(&q); // 取消注释以测试异常处理

  // 测试3：扩容和压缩测试
  printf("\n==== 扩容和压缩测试 ====\n");
  size_t test_size = 1000000;  // 测试大量元素
  for (size_t i = 0; i < test_size; ++i) {
    Queue_Push(&q, i);
    if (i % (test_size / 10) == 0) {
      printf("插入元素 %zu, 当前队列大小: %zu, 容量: %zu\n", i, Queue_Size(&q), q.capacity);
    }
  }
  printf("队列扩容成功，当前容量: %zu\n", q.capacity);

  return 0;
}