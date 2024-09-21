#include <stdio.h>
#include <stdlib.h>
#define size_t int

typedef struct {
  siz* list;
  int size;
  int capacity;
} SequentialList;

void init_SequentialList(SequentialList* sl, int capacity) {
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