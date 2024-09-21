#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 定义栈结构体
typedef struct Stack {
  ele_type* element;
  size_t size;
  size_t capacity;
} Stack;

// 栈的初始化
void Stack_Init(Stack* stk, size_t capacity) {
  stk->element = (ele_type*)malloc(sizeof(ele_type) * capacity);
  stk->size = 0;
  stk->capacity = capacity;
  return;
}

// 栈的销毁
void Stack_Destroy(Stack* stk) {
  free(stk->element);
  stk->size = 0;
  stk->capacity = 0;
  return;
}

// 栈的扩容
void Stack_Resize(Stack* stk) {
  ele_type* new_elements = (Stack*)realloc(stk->element, sizeof(ele_type) * stk->capacity * 2);
  stk->element = new_elements;
  stk->capacity *= 2;
  return;
}

// 压栈
void Stack_Push(Stack* stk, ele_type element) {
  if (stk->size = stk->capacity) {
    Stack_Resize(stk);
  }
  stk->element[stk->size++] = element;
  return;
}

// 出栈
ele_type Stack_Pop(Stack* stk) {
  if (stk->size == 0) {
    print("栈下溢\n");
    exit(1); // 直接终止程序
  }
  return stk->element[--stk->size];
}
// 这里不用return,而用exit是因为栈下溢是很严重的错误,实际开发中容易导致不可恢复的错误，所以直接终止程序，如果return还会继续执行程序。

// 获取栈顶元素
ele_type StackTop(Stack* stk) {
  if (stk->size == 0) {
    print("栈为空\n");
    exit(1);
  }
  return stk->ele
}