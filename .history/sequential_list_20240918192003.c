#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* list;
  size_t size;
  // size_t是一种用于表示对象大小或数组索引的无符号整数类型
  size_t capacity;
} SequentialList;

// 初始化顺序表
void SequentialList_Init(SequentialList* sl, size_t capacity) {
  sl->list = (int*)malloc(sizeof(int) * capacity);
  sl->size = 0;
  sl->capacity = capacity;
  return;
}

// 销毁顺序表
void SequentialList_Destroy(SequentialList* sl) {
  if (sl->list != NULL) {
    free(sl->list);
    sl->list = NULL;
  }
  return;
}

// 返回顺序表的元素个数
size_t SequentialList_Size(const SequentialList* sl) {
  return sl->size;
}

// 往顺序表里插入元素
void SequentialList_Insert(SequentialList* sl, int index, int element) {
  if (index < 0 || index > sl->size) {
    printf("Invalid index\n");
    return;
  }

  if (sl->size == sl->capacity) {
    int* new_list = (int*)realloc(sizeof(int) * sl->capacity * 2);
    if (new_list == NULL) {
      printf("Failed to allocate memory\n");
      return;
    }
    sl->list = new_list;
    sl->capacity *= 2;
  }

  for (size_t i = sl->size; i > index; i--) {
    sl->list[i] = sl->list[i - 1];
  }
  sl->list[index] = element;
  sl->size++;

  return;
}

void SequentialList_Delete(SequentialList* sl, int index) {
  if (index < 0 || index >= sl->size) {
    printf("Invalid index\n");
    return;
  }

  for (size_t i = index; i < sl->size; i++) {
    sl->list[i] = sl->list[i + 1];
  }
  sl->size--;

  return;
}

int SequentialList_Find(SequentialList* sl, int element) {
  for (size_t i = 0; i < sl->size; i++) {
    
  }
}
int main() {
  printf("hello world");
  return 0;
}