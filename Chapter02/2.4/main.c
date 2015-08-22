#include<stdio.h>
#include "../includes/LinkedList.h"

void partitionAround(List **, int);

int main(int argc, char * argv[])
{
  if(argc < 2)
  {
    printf("Usage: %s <partitioning integer>\n", argv[0]);
    return(EXIT_FAILURE);
  }

  List * list = NULL;

  pushNodeFront(&list, 1);
  pushNodeFront(&list, 3);
  pushNodeFront(&list, 10);
  pushNodeFront(&list, 4);
  pushNodeFront(&list, 6);
  pushNodeFront(&list, 8);
  pushNodeFront(&list, 2);
  pushNodeFront(&list, 0);

  printList(list);

  partitionAround(&list, atoi(argv[1]));

  printList(list);

  freeList(list);

  return(0);
}


void partitionAround(List ** listPtr, int val)
{
  List * list = * listPtr;

  List * temp = NULL;

  while(list)
  {
    if(list->index < val)
    {
      pushNodeFront(&temp, list->index);
    }

    list = list->next;
  }

  list = * listPtr;

  while(list)
  {
    if(list->index >= val)
    {
      pushNodeBack(&temp, list->index);
    }

    list = list->next;
  }

  list = * listPtr;
  freeList(list);

  * listPtr = temp;
} 
