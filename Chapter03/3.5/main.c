#include <stdio.h>
#include "../includes/Stack.h"

void sort(Stack **);

int main(int argc, char * argv[])
{
  Stack * stack = NULL;

  push(&stack, 2);
  push(&stack, 1);
  push(&stack, 4);
  push(&stack, 3);

  printStack(stack);
  sort(&stack);
  printStack(stack);

  freeStack(stack);
  return(0);
}

void sort(Stack ** st)
{
  Stack * tempStack = NULL;
  Stack * stack = * st;
  int temp;

  while(stack)
  {
    temp = pop(&stack);

    if(tempStack == NULL || (temp < tempStack->index))
    {
      push(&tempStack, temp);
    }
    else
    {
      while(tempStack && tempStack->index < temp)
      {
        push(&stack, pop(&tempStack));
      }

      push(&tempStack, temp);
    }
  }

  *st = tempStack;
}
