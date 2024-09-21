#include <stdio.h>
#include <stdlib.h>

#define ele_type int

typedef struct {
  ele_type* element;
  size_t head;
  size_t tail;
  size_t capacity;
}Queu
