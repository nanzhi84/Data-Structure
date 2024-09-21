#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 定义栈结构体
typedef struct Stack {
  ele_type* element;
  size_t size;
  size_t capacity;
} Stack;

// 初始化栈
void Stack_Init(Stack* stk, size_t capacity) {
  stk->element = (ele_type*)malloc(sizeof(ele_type) * stk->capacity);

}