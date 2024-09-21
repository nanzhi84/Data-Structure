#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* list;
  size_t size;
  // size_t是一种用于表示对象大小或数组索引的无符号整数类型
  size_t capacity;
} SequentialList;

// 初始化顺序表
void Init_SequentialList(SequentialList* sl, size_t capacity) {
  sl->list = (int*)malloc(sizeof(int) * capacity);
  sl->size = 0;
  sl->capacity = capacity;
  return;
}

// 销毁顺序表
void Destroy_SequentialList(SequentialList* sl) {
  if (sl->list != NULL) {
    free(sl->list);
    sl->list = NULL;
  }
  return;
}

// 返回顺序表的元素个数
size_t SequentialListSize(const SequentialList* sl) {
  return sl->size;
}

// 往顺序表里插入元素

int main() {
  printf("hello world");
  return 0;
}