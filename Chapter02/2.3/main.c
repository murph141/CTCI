#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  struct node * next;
  int index;
} List;

List * createList(int);
void addItem(List *, int);
void printList(List *);
void destroyList(List *);
void removeNode(List *);

int main(int argc, char * argv[])
{
  List * list;
  int index = 0;
  
  list = createList(index++);

  addItem(list, index++);
  addItem(list, index++);
  addItem(list, index++);
  addItem(list, index++);
  addItem(list, index++);
  addItem(list, index++);

  printList(list);

  removeNode(list->next->next->next);

  printList(list);

  destroyList(list);

  return(0);
}

List * createList(int index)
{
  List * list = malloc(sizeof(List));
  list->index = index;
  list->next = NULL;

  return(list);
}

void addItem(List * list, int index)
{
  List * l2 = malloc(sizeof(List));
  l2->index = index;
  l2->next = NULL;

  while(list->next)
  {
    list = list->next;
  }

  list->next = l2;
}

void printList(List * list)
{
  while(list)
  {
    printf("%d ", list->index);
    list = list->next;
  }
  printf("\n");
}

void destroyList(List * list)
{
  List * next;

  while(list)
  {
    next = list->next;
    free(list);
    list = next;
  }
}

void removeNode(List * list)
{
  if(list == NULL || list->next == NULL)
  {
    return;
  }

  List * list2 = list->next;
  list->index = list2->index;
  list->next = list2->next;

  free(list2);
}
