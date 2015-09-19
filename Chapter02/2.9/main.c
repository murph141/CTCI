#include <stdio.h>
#include "../includes/LinkedList.h"

void reverse(List **);

int main(int argc, char * argv[])
{
  List * list = NULL;

  pushNodeFront(&list, 1);
  pushNodeFront(&list, 2);
  pushNodeFront(&list, 3);
  pushNodeFront(&list, 4);

  printList(list);

  reverse(&list);

  printList(list);

  return(0);
}

void reverse(List ** l)
{
  List * first;
  List * rest;

  if(*l == NULL)
  {
    return;
  }

  first = *l;
  rest = first->next;

  if(rest == NULL)
  {
    return;
  }

  reverse(&rest);

  first->next->next = first;
  first->next = NULL;

  *l = rest;
}
