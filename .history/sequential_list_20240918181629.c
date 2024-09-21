#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *list;
  int size;
  int capacity;
} SequentialList;

void init_SequentialList(SequentialList *sl, int capacity)
{
  sl->list = (int *)malloc(sizeof(int) * capacity);
  sl->size = 0;
  sl->capacity = capacity;
  return;
}

int main()
{
  
}