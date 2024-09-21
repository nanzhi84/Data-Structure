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
void Stack_Push(Stack* stk, ele_type element) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = element;
  new_node->next = stk->head;
  stk->head = new_node;
  stk->size++;
  return;
}

// 出栈
ele_type Stack_Pop(Stack* stk) {
  if (stk->size == 0) {
    printf("栈下溢\n");
    exit(1); // 直接终止程序
  }
  Node* tmp = stk->head;
  ele_type result = tmp->data;
  stk->head = stk->head->next;
  free(tmp);
  stk->size--;

  return result;
}

// 获取栈顶元素
ele_type Stack_Top(Stack* stk) {
  if (stk->size == 0) {
    printf("栈为空\n");
    exit(1);
  }
  return stk->head->data;
}

// 获取栈元素个数
int
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