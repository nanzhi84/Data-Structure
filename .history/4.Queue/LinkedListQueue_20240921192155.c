#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// Din
typedef struct Node {
  ele_type data;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
  Node* tail;
} Queue;

