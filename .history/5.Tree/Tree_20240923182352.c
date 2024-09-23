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
  // 释放所有结点
  free(t->nodes);
  t->nodes = NULL;
  t->root = NULL;
  return;
}

// 获取树的结点
TreeNode* TreeGetNode(Tree* t, int id) {
  // 拿到t
  return &t->nodes[id];
}

// 设置树的根结点
void TreeSetRoot(Tree* t, int id) {
  t->root = TreeGetNode(t, id);
  return;
}

// 设置树的边
void TreeAddChild(Tree* t, int parentId, int childId) {
  // 获取父亲结点Id
  TreeNode* parentNode = TreeGetNode(t, parentId);
  // 获取孩子结点Id
  TreeNode* childNode = TreeGetNode(t, childId);
  // 添加树的边
  AddTreeChild(parentNode, childNode);
  return;
}

// 设置树的结点值
void TreeAssignData(Tree* t, int id, eleType data) {
  // 设置树结点的值
  TreeGetNode(t, id)->data = data;
  return;
}

// 树的深度优先遍历
void TreePrint(Tree* t, TreeNode* node) {
  // 如果node为空,则从根结点开始搜索
  if (node == NULL) {
    node = t->root;
  }
  // 打印搜索到的结点的数据
  printf("%c", node->data);
  // 获取到结点的孩子结点
  ListNode* tmp = node->childrenHead;
  // 循环搜索孩子结点列表直到为空
  while (tmp) {
    // 继续遍历下一棵以孩子结点为根结点的子树
    TreePrint(t, tmp->data);
    // 列表中的孩子结点更新
    tmp = tmp->next;
  }
  // 直到遇到叶子结点会直接return
  return;
}