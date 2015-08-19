#include<stdio.h>
#include "../includes/LinkedList.h"

int ListValue(List *);
int ListValue2(List *);

int main(int argc, char * argv[])
{
  List * list = NULL;

  buildTestList(&list);

  printf("%d\n", ListValue(list));
  printf("%d\n", ListValue2(list));

  freeList(list);

  return(0);
}


int ListValue(List * list)
{
  int val = 0;

  while(list != NULL)
  {
    val *= 10;
    val += list->index;

    list = list->next;
  }

  return(val);
}


int ListValue2(List * list)
{
  int val;

  if(!list)
  {
    return(0);
  }

  val = ListValue2(list->next);

  val *= 10;
  val += list->index;

  return(val);
}
