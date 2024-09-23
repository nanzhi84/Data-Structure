#include <stdio.h>
#include <stdlib.h>

#define eleType char
struct TreeNode; // 先声明树的结点

// 链表节点定义
typedef struct ListNode {
  struct TreeNode* data; // 数据域
  struct ListNode* next; // 指针域
}ListNode;

// 树jie'dian
typedef struct TreeNode {
  eleType data;
  ListNode* childrenHead;
}TreeNode;