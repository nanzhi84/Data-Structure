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

// 栈的初始化
void Stack_Init(Stack* stk) {
  stk->head = NULL;
  stk->size = 0;
  return;
}

// 栈的销毁
void Stack_Destroy(Stack* stk) {
  while (stk->head) {
    Node* tmp = stk->head;
    stk->head = stk->head->next;
    free(tmp);
  }
  stk->size = 0;
  return;
}

// 入栈
void
//实验
int main() {
  Stack stk;

  Stack_Init(&stk);
  Stack_Push(&stk, 0);
  Stack_Push(&stk, 1);
  Stack_Push(&stk, 2);
  printf("栈顶元素: %d\n", Stack_Top(&stk));
  printf("出栈: %d\n", Stack_Pop(&stk));
  printf("栈的大小: %d\n", Stack_Size(&stk));
  Stack_Destroy(&stk);

  return 0;
}