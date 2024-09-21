#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* list;
  int size;
  int capacity;
} SequentialList;

void init_SequentialList(SequentialList *sl, int capacity) {
  sl->list = (int*)
}