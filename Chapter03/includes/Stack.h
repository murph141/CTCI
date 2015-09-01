#ifndef _STACK_H
#define _STACK_H

#include<stdlib.h>

typedef struct node
{
  struct node * next;
  int index;
} Stack;

void push(Stack **, int val);
int pop(Stack **);
int peek(Stack *);
int isEmpty(Stack *);
void printStack(Stack *);
void freeStack(Stack *);

void push(Stack ** stack, int val)
{
  Stack * temp = * stack;

  Stack * newItem = malloc(sizeof(Stack));
  newItem->index = val;

  newItem->next = temp;

  *stack = newItem;
}

int pop(Stack ** stack)
{
  if(isEmpty(* stack))
  {
    printf("Can't pop, stack is empty\n");
    return(0);
  }

  int returnVal;
  Stack * temp = * stack;

  * stack = temp->next;
  
  returnVal = temp->index;

  free(temp);

  return(returnVal);
}

void printStack(Stack * stack)
{
  while(!isEmpty(stack))
  {
    printf("%d\n", stack->index);
    stack = stack->next;
  }
}

int peek(Stack * stack)
{
  if(isEmpty(stack))
  {
    printf("Can't peek, stack is empty\n");
    return(0);
  }

  return(stack->index);
}

int isEmpty(Stack * stack)
{
  if(stack == NULL)
  {
    return(1);
  }

  return(0);
}

void freeStack(Stack * stack)
{
  Stack * temp;

  while(!isEmpty(stack))
  {
    temp = stack;
    stack = stack->next;
    free(temp);
  }
}

#endif
