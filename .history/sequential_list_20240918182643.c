#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* list;
  size_t size;
  // size_t是一种用于表示对象大小或数组索引的无符号整数类型
  size_t capacity;
} SequentialList;

void init_SequentialList(SequentialList* sl,  capacity) {
  sl->list = (int*)malloc(sizeof(int) * capacity);
  sl->size = 0;
  sl->capacity = capacity;
  return;
}

void destroy_SequentialList(SequentialList* sl) {
  if (sl->list != NULL) {
    free(sl->list);
    sl->list = NULL;
  }
  return;
}


int main() {
  printf("hello world");
  return 0;
}