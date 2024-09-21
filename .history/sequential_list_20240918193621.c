#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义顺序表的结构
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

// 删除顺序表中的某个元素
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

// 查找顺序表中的某个元素
int SequentialList_Find(SequentialList* sl, int element) {
  for (size_t i = 0; i < sl->size; i++) {
    if (sl->list[i] == element) {
      return i;
    }
  }
  return -1;
}

// 查找顺序表某个索引对应的元素
int SequentialList_Index(SequentialList* sl, int index) {
  if (index < 0 || index >= sl->size) {
    printf("Invalid index\n");
    return -1;
  }
  return sl->list[index];
}

// 修改顺序表中的元素
void SequentialList_Change(SequentialList* sl, int index, int element) {
  if (index < 0 || index >= sl->size) {
    printf("Invalid index\n");
    return;
  }
  sl->list[index] = element;
  return;
}

// 打印目前顺序表中的内容
void SequentialList_printf(SequentialList* sl) {
  printf("Size: %zu\n", sl->size);
  printf("Capacity: %zu\n", sl->capacity);
  printf("Element: \n");
  for (size_t i = 0; i < sl->size; i++) {
    printf("%d ", sl->list[i]);
  }
  printf("\n");
  printf("内容打印完毕");
}

// 实验
int main() {
  // 初始化
  SequentialList* sl;
  SequentialList_Init(&sl, 10);
  SequentialList_printf(&sl);

  // 插入元素
  for (int i = 0; i < 15; i++) {
    SequentialList_Insert(sl, i, i);
  }
  SequentialList_printf(&sl);

  // 随机删除某些元素
  srand(time(NULL));
  int random_number = (rand() % 50) + 1;
  return 0;
}