#include <stdio.h>
#include <stdlib.h>
#include "../includes/Stack.h"

int min(Stack *);
int popNew(Stack **, Stack **);
void pushNew(Stack **, Stack **, int);

int main(int argc, char * argv[])
{
  Stack * s = NULL;
  Stack * minStack = NULL;
  pushNew(&s, &minStack, 2);
  pushNew(&s, &minStack, 1);
  pushNew(&s, &minStack, 4);
  pushNew(&s, &minStack, 6);
  pushNew(&s, &minStack, 8);
  pushNew(&s, &minStack, 7);
  pushNew(&s, &minStack, 0);

  printStack(s);
  printStack(minStack);

  int temp;

  temp = popNew(&s, &minStack);
  printf("%d\n", temp);

  printf("\n");
  printStack(minStack);

  freeStack(s);
  freeStack(minStack);

  return(0);
}

void pushNew(Stack ** stack, Stack ** minStack, int val)
{
  push(stack, val);

  if(* minStack == NULL)
  {
    push(minStack, val);
  }
  else if(val < min(* minStack))
  {
    push(minStack, val);
  }
  else
  {
    push(minStack, min(* minStack));
  }
}

int min(Stack * s)
{
  return(s->index);
}

int popNew(Stack ** stack, Stack ** minStack)
{
  int a = pop(minStack);
  a = pop(stack);

  return(a);
}
