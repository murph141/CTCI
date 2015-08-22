#include<stdio.h>
#include "../includes/LinkedList.h"

List * returnKthToLast(List *, int);

int main(int argc, char * argv[])
{
  if(argc != 2)
  {
    return(EXIT_FAILURE);
  }

  int input = atoi(argv[1]);
  List * list = NULL;

  buildTestList(&list);

  printList(list);
  List * KthToLast = returnKthToLast(list, input);

  if(KthToLast == NULL)
  {
    return(EXIT_FAILURE);
  }

  printf("KthToLast: %d\n", KthToLast->index);

  return(0);
}


List * returnKthToLast(List * list, int index)
{
  if(index < 0)
  {
    printf("Input must be positive\n");
    return(NULL);
  }

  List * temp = list;

  while(list && index--)
  {
    list = list->next;
  }

  if(list == NULL && !index)
  {
    printf("List is not long enough for the given index\n");
    return(NULL);
  }

  while(list->next)
  {
    list = list->next;
    temp = temp->next;
  }

  return(temp);
}
