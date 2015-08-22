#include<stdio.h>
#include "../includes/LinkedList.h"

int printKthToLast(List *, int);

int main(int argc, char * argv[])
{
  if(argc < 2)
  {
    printf("Usage: %s <desired index>\n", argv[0]);
  }

  int desiredIndex = atoi(argv[1]) + 1;

  List * list = NULL;

  buildTestList(&list);
  buildTestList(&list);

  printList(list);

  printKthToLast(list, desiredIndex);

  freeList(list);

  return(0);
}

int printKthToLast(List * list, int desiredIndex)
{
  if(list == NULL)
  {
    return(0);
  }

  int currentIndex = printKthToLast(list->next, desiredIndex) + 1;

  if(currentIndex == desiredIndex)
  {
    printf("Kth to last node is: %d\n", list->index);
  }

  return(currentIndex);
}
