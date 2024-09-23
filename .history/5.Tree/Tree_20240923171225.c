#include <stdio.h>
#include <stdlib.h>

#define eleType char
struct TreeNode; //

typedef struct ListNode {
  struct TreeNode* data;
  struct ListNode* next;
}ListNode;

typedef struct TreeNode {
  eleType data;
  ListNode* childrenHead;
}TreeNode;