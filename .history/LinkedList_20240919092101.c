#include <stdio.h>
#include <stdlib.h>

#define ele_type int

// 单向链表节点定义
typedef struct LinkedNode {
  ele_type data;
  struct node* next;
}LinkedNode;

// 单向链表定义
typedef struct LinkedList {
  struct LinkedNode* head;
  size_t size;
}LinkedList;

// 单向链表的创建
void LinkedList_Init(LinkedList* list) {
  list->head = NULL;
  list->size = 0;
  return;
}

// 单向链表的销毁
void LinkedList_Destroy(LinkedList* list) {
  while (list->head) {
    LinkedNode* tmp = list->head;
    list->head = list->head->next;
    free(tmp);
  }
  list->size = 0;
  return;
}

// 单向链表的插入
void LinkedList_Insert(LinkedList* list, int index, ele_type value) {
  if (index < 0 || index > list->size) {
    printf("非法索引\n");
    return;
  }

  // 创建新节点
  LinkedNode* new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
  new_node->data = value;

  if (index == 0) {
    new_node->next = list->head;
    list->head = new_node;
  }
  else {
    // 找到第i-1个节点
    LinkedNode* current = list->head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    LinkedNode* next = current->next;

    // 更新节点
    current->next = new_node;
    new_node->next = next;
  }
  list->size++;
  return;
}

// 单向链表的元素删除
void LinkedList_Delete(LinkedList* list, int index) {
  if (index < 0 || index > list->size) {
    printf("非法索引\n");
    return;
  }

  if (index == 0) {
    LinkedNode* tmp = list->head;
    list->head = list->head->next;
    free(tmp);
  }
  else {
    LinkedNode* current = list->head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    LinkedNode* tmp = current->next;
    current->next = tmp->next;
    free(tmp);
  }
  list->size--;
  return;
}

// 单向链表的元素查找
LinkedNode* LinkedList_Find(LinkedList* list, ele_type value) {
  LinkedNode* current = list->head;
  while (current) {
    if (current->data == value) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// 单向链表的元素索引
LinkedNode* LinkedList_Get(LinkedList* list, int index) {
  if (index < 0 || index > list->size) {
    printf("非法索引\n");
    return;
  }

  LinkedNode* current = list->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current;
}

// 单向链表的元素修改
void LinkedList_Update(LinkedList* list, int index, ele_type value) {
  LinkedNode* node = LinkedList_Get(list, index);
  if (node != NULL) {
    node->data = value;
  }
  return;
}

// 单向链表的打印
void LinkedList_Printf(LinkedList* list) {
  LinkedNode* current = list->head;
  while (current) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL");
  return;
}

// 实验
int main() {
  // 创建一个单向链表
  LinkedList list;
  LinkedList_Init(&list);

  // 插入元素
  for (int i = 0; i < 5; i++) {
    LinkedList_Insert(list, i, i);
  }

  // 打印原始链表
  printf("原始链表:\n");
  LinkedList_Printf(&list);

  // 删除第2个节点
  LinkedList_Delete(&list, 2);

  // 更新第1个节点
  LinkedList_Update(&list, 1, 10);

  // 查找值为10和值为30的节点
  int Find_List = [10, 30];
  for (int i = 0; i < len(Find_List); i++) {
    LinkedNode* node = LinkedList_Find(&list, );
    if (node != NULL)
    {
      printf("找到值为10的节点\n");
    }
    else {
      printf("没有找到值为10的节点\n");
    }
  }
  
}