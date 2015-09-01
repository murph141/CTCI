#include<stdio.h>
#include<stdlib.h>

#define ARRSIZE 12

void push(char **, char, char, char);
void pop(char **);
void printStack(char *);

int main(int argc, char * argv[])
{
  char * arr = malloc(sizeof(char) * (ARRSIZE + 1));
  arr[ARRSIZE] = 0;

  push(&arr, 'a', 'b', 'c');

  printStack(arr);

  push(&arr, 'd', 'e', 'f');

  printStack(arr);

  pop(&arr);

  printStack(arr);

  free(arr);

  return(0);
}

void push(char ** stack, char a, char b, char c)
{
  char * s = * stack;

  if(s[ARRSIZE] == ARRSIZE)
  {
    printf("Stack is full\n");
    return;
  }

  int i;

  for(i = ARRSIZE - 1; i >= 5; i -= 3)
  {
    s[i] = s[i - 3];
    s[i - 1] = s[i - 4];
    s[i - 2] = s[i - 5];
  }

  s[ARRSIZE] += 3;
  s[0] = a;
  s[1] = b;
  s[2] = c;

  * stack = s;
}

void printStack(char * stack)
{
  int i;
  
  for(i = 0; i < stack[ARRSIZE]; i++)
  {
    printf("arr[%d] = %c\n", i, stack[i]);
  }
  printf("\n");
}

void pop(char ** stack)
{
  char * s = * stack;
  if(s[ARRSIZE] == 0)
  {
    printf("Stack is empty\n");
    return;
  }

  char a = s[0];
  char b = s[1];
  char c = s[2];
  s[ARRSIZE] -= 3;

  int i;

  for(i = 0; i < s[ARRSIZE]; i+= 3)
  {
    s[i] = s[i + 3];
    s[i + 1] = s[i + 4];
    s[i + 2] = s[i + 5];
  }

  printf("Values popped: %c %c %c\n", a, b, c);

  * stack = s;
}
