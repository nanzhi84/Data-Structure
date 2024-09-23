#include <stdio.h>
#include <stdlib.h>

#define eleType char
struct TreeNode; // 先声明树的结点

typedef struct ListNode {
  struct TreeNode* data; /
  struct ListNode* next;
}ListNode;

typedef struct TreeNode {
  eleType data;
  ListNode* childrenHead;
}TreeNode;