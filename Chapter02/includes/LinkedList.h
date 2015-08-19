#ifndef _LINKEDLIST
#define _LINKEDLIST

#include<stdlib.h>

typedef struct node
{
  struct node * next;
  int index;
} List;

void buildTestList(List **);
void pushNodeFront(List **, int);
void pushNodeBack(List **, int);
void printList(List *);
void freeList(List *);

void buildTestList(List ** listPtr)
{
  *listPtr = NULL;
  pushNodeFront(listPtr, 1);
  pushNodeFront(listPtr, 2);
  pushNodeFront(listPtr, 3);
  pushNodeFront(listPtr, 4);
}

void printList(List * list)
{
  while(list != NULL)
  {
    printf("%d ", list->index);
    list = list->next;
  }

  printf("\n");
}

void pushNodeFront(List ** listPtr, int val)
{
  if(listPtr == NULL)
  {
    return;
  }

  List * list = * listPtr;
  List * newList = malloc(sizeof(List));

  newList->index = val;

  newList->next = list;

  *listPtr = newList;
}

void freeList(List * list)
{
  List * temp = list;

  while(temp)
  {
    list = list->next;
    free(temp);
    temp = list;
  }
}

void pushNodeBack(List ** listPtr, int val)
{
  if(listPtr == NULL)
  {
    return;
  }

  List * list = * listPtr;

  if(list == NULL)
  {
    pushNodeFront(listPtr, val);
    return;
  }

  List * newList = malloc(sizeof(List));
  List * front = list;

  newList->index = val;
  newList->next = NULL;

  while(list->next != NULL)
  {
    list = list->next;
  }

  list->next = newList;

  *listPtr = front;
}

#endif
