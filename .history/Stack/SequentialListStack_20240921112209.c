#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// d
typedef struct Stack {
  ele_type* element;
  size_t size;
  size_t capacity;
} Stack;



