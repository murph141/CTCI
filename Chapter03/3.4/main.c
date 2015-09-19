#include <stdio.h>
#include "../includes/Stack.h"

typedef struct
{
  Stack * enq;
  Stack * deq;
} Queue;

void freeQueue(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);

int main(int argc, char * argv[])
{
  Queue * que = malloc(sizeof(Queue));
  que->enq = NULL;
  que->deq = NULL;

  enqueue(que, 1);
  enqueue(que, 2);
  enqueue(que, 3);
  enqueue(que, 4);
  enqueue(que, 5);

  int temp = dequeue(que);
  printf("%d\n", temp);

  temp = dequeue(que);
  printf("%d\n", temp);

  temp = dequeue(que);
  printf("%d\n", temp);

  temp = dequeue(que);
  printf("%d\n", temp);

  temp = dequeue(que);
  printf("%d\n", temp);

  enqueue(que, 6);
  temp = dequeue(que);
  printf("%d\n", temp);

  freeQueue(que);
  
  return(0);
}

void freeQueue(Queue * que)
{
  freeStack(que->enq);
  freeStack(que->deq);

  free(que);
}

void enqueue(Queue * que, int val)
{
  Stack ** enq = &que->enq;

  push(enq, val);
}

int dequeue(Queue * que)
{
  if(que->deq == NULL)
  {
    if(que->enq == NULL)
    {
      return(-1);
    }

    while(que->enq != NULL)
    {
      int temp = pop(&que->enq);
      push(&que->deq, temp);
    }
  }

  return(pop(&que->deq));
}
