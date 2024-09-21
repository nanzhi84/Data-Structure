#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 节点定义
typedef struct Node {
  ele_type data;
  struct Node* next;
} Node;

// 栈的定义
typedef struct Stack {
  Node* head;
  size_t size;
} Stack;

void Stack_Init(Stack* stk, size_t sie) {
  
}

//实验
int main() {
  Stack stk;

  Stack_Init(&stk, 1);
  Stack_Push(&stk, 0);
  Stack_Push(&stk, 1);
  Stack_Push(&stk, 2);
  printf("栈顶元素: %d\n", Stack_Top(&stk));
  printf("出栈: %d\n", Stack_Pop(&stk));
  printf("栈的大小: %d\n", Stack_Size(&stk));
  Stack_Destroy(&stk);

  return 0;
}