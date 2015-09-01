#ifndef _QUEUE_H
#define _QUEUE_H

#include<stdlib.h>

typedef struct node
{
  struct node * next;
  int index;
} List;

typedef struct que
{
  List * first;
  List * last;
  int size;
} Queue;

void enqueue(Queue **, int);
int dequeue(Queue **);

void enqueue(Queue ** que, int val)
{
  Queue * temp;
  List * buffer;

  temp = *que;

  if(temp == NULL)
  {
    temp = malloc(sizeof(Queue));
    buffer = malloc(sizeof(List));
    buffer->next = NULL;
    buffer->index = val;
    temp->size = 1;
    temp->first = buffer;
    temp->last = buffer;

    *que = temp;
    return;
  }

  buffer = malloc(sizeof(List));
  buffer->next = temp->first;
  buffer->index = val;
  temp->first = buffer;
  temp->size++;
  *que = temp;
}

int dequeue(Queue ** que)
{
  Queue * temp = *que;

  if(temp->size == 0)
  {
    printf("Queue size is 0\n");
    return(-1);
  }

  temp->size--;

  int iterator = temp->size;
  int returnVal;

  List * prev, * end;

  end = temp->last;

  returnVal = temp->last->index;

  prev = temp->first;

  if(iterator == 0)
  {
    temp->first = NULL;
    temp->last = NULL;

    free(prev);

    *que = temp;
    return(returnVal);
  }

  while(--iterator)
  {
    prev = prev->next;
  }

  prev->next = NULL;

  temp->last = prev;

  free(end);

  *que = temp;

  return(returnVal);
}


#endif
