#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *list;
  int size;
  int capacity;
} SequentialList;

void S