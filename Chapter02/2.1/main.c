#include<stdio.h>
#include "../includes/LinkedList.h"

void removeDuplicates(List *);

int main(int argc, char * argv[])
{
  List * list = NULL;

  buildTestList(&list);
  buildTestList(&list);

  printList(list);

  removeDuplicates(list);

  printList(list);

  freeList(list);

  return(0);
}


void removeDuplicates(List * list)
{
  List * temp;
  List * prev;

  while(list)
  {
    prev = list;
    temp = list->next;

    while(temp)
    {
      if(temp->index == list->index)
      {
        prev->next = temp->next;
        free(temp);
        temp = NULL;
      }
      else
      {
        prev = temp;
        temp = temp->next;
      }
    }
    list = list->next;
  }
}
