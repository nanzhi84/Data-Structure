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

void destroy_SequentialList(SequentialList *sl)
{
  if(sl->list != NULL){
    free()
  }
}

int main()
{
  printf("hello world");
  return 0;
}