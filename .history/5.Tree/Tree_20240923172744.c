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
    // 如果父结点有孩子结点，让孩子结点的指针指向另外的孩子结点，再让父结点的指针指向新创建的孩子结点。
    childNode->next = parent->childrenHead;
    parent->childrenHead = childNode;
  }
  return;
}

// 树结构体的定义
typedef struct Tree {
  TreeNode* nodes; // 树结点的集合
  TreeNode* root; // 根结点的指针
} Tree;

// 树的创建
void TreeCreate(Tree* t, int size) {
  // 创建树的结点集合，大小为size
  t->nodes = (TreeNode*)malloc(sizeof(TreeNode) * size);
  t->root = NULL;
  return;
}

// 树的销毁
void TreeDestroy(Tree* t) {
  free(t->nodes);
  t->nodes = NULL;
  t->root = NULL;
  return;
}

// huo'qu
TreeNode* TreeGetNode(Tree* t, int id) {
  
}