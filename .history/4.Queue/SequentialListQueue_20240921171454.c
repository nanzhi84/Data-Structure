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

// 获取队列大小
size_t Queue_Size(Queue* q) {
  return q->tail - q->head;
}

// 队列压缩
void Queue_Compress(Queue* q) {
  if (q->head > 0) {
    size_t size = Queue_Size(q);
    for (size_t i = 0; i < size; ++i) {
      q->elements[i] = q->elements[q->head + i];
    }
    q->head = 0;
    q->tail = size;
  }
}
// 顺序表实现才写了队列压缩，不然似乎每次取出队头元素前面的位置会空出来dao

// 队列的扩容
void Queue_Resize(Queue* q) {
  ele_type* new_elements = (ele_type*)realloc(q->elements, sizeof(ele_type) * q->capacity * 2);
  if (new_elements == NULL) {
    printf("内存分配失败\n");
    exit(1); // 内存分配失败,停止程序
  }
  q->elements = new_elements;
  q->capacity *= 2;
  return;
}

// 入队
void Queue_Push(Queue* q, ele_type element) {
  if (q->tail == q->capacity) {
    if (q->head > 0) {
      printf("有空位置,压缩队列\n");
      Queue_Compress(q);
    }
    else {
      Queue_Resize(q);  // 队列满了，扩容
    }
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