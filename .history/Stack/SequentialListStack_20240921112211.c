#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 定义栈
typedef struct Stack {
  ele_type* element;
  size_t size;
  size_t capacity;
} Stack;



