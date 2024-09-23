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
  // 创建孩子结点
  ListNode* childNode = (ListNode*)malloc(sizeof(ListNode));
  childNode->next = NULL;
  childNode->data = child;

  if (parent->childrenHead == NULL) {
    // 如果父结点没有孩子结点，直接赋值给它
    parent->childrenHead = childNode;
  }
  else {
    // 如果父结点有孩子结点，让孩子结点的指针指向另外的孩子结点，再让父结点的指针指向新创建的孩子结点，
    childNode->next = parent->childrenHead;
    parent->childrenHead = childNode;
  }
}