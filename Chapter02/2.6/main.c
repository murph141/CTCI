#include<stdio.h>
#include "../includes/LinkedList.h"

int ListValue(List *);
int ListValue2(List *);
void checkPalindrome(List *);
void createPalindrome(List **);
void createNonPalindrome(List **);

int main(int argc, char * argv[])
{
  List * list = NULL;

  createPalindrome(&list);
  printList(list);
  checkPalindrome(list);
  freeList(list);

  list = NULL;

  createNonPalindrome(&list);
  printList(list);
  checkPalindrome(list);
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


void checkPalindrome(List * list)
{
  if(ListValue(list) == ListValue2(list))
  {
    printf("The list is a palindrome\n");
  }
  else
  {
    printf("The list is not a palindrome\n");
  }
}


void createPalindrome(List ** list)
{
  pushNodeFront(list, 1);
  pushNodeFront(list, 3);
  pushNodeFront(list, 2);
  pushNodeFront(list, 3);
  pushNodeFront(list, 1);
}


void createNonPalindrome(List ** list)
{
  pushNodeFront(list, 1);
  pushNodeFront(list, 4);
  pushNodeFront(list, 2);
  pushNodeFront(list, 3);
  pushNodeFront(list, 1);
}
