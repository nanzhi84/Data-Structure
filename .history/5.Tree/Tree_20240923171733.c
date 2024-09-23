#include <stdio.h>
#include <stdlib.h>

#define eleType char
struct TreeNode; // 先声明树的结点

// 链表节点定义
typedef struct ListNode {
  struct TreeNode* data; // 数据域
  struct ListNode* next; // 指针域
} ListNode;

// 树结点定义
typedef struct TreeNode {
  eleType data; // 结点的数据
  ListNode* childrenHead; // 孩子结点
} TreeNode;

// 添加孩子结点
void AddTreeChild(TreeNode* parent, TreeNode* child) {
  // 创建一个新
  ListNode* childNode = (ListNode*)malloc(sizeof(ListNode));
  childNode->next = NULL;
  childNode->data = child;

  if (parent->childrenHead == NULL) {
    parent->childrenHead = childNode;
  }
  else {
    childNode->next = parent->childrenHead;
    parent->childrenHead = childNode;
  }
}