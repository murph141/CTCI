#include<stdio.h>
#include<stdlib.h>

#define ARRSIZE 3

int rotate(int **, int, int);
void rotate90(int **, int);
void rotate180(int **, int);
void rotate270(int **, int);
void transpose(int **, int);
void printArray(int **, int);
void flipRows(int **, int);
void flipColumns(int **, int);
void swap(int *, int *);

int main(int argc, char * argv[])
{
  int ** arr = malloc(sizeof(int *) * ARRSIZE);
  int i, j;

  for(i = 0; i < ARRSIZE; i++)
  {
    arr[i] = malloc(sizeof(int) * ARRSIZE);
  }

  for(i = 0; i < ARRSIZE; i++)
  {
    for(j = 0; j < ARRSIZE; j++)
    {
      arr[i][j] = i * ARRSIZE + j;
    }
  }

  int degrees;

  if(argc != 2)
  {
    printf("Usage: %s <angle>\n", argv[0]);
    return(0);
  }

  degrees = atoi(argv[1]);

  printf("Before:\n");
  printArray(arr, ARRSIZE);
  printf("\n");

  int status = rotate(arr, degrees, ARRSIZE);

  if(status == -1)
  {
    return(status);
  }

  printf("After:\n");
  printArray(arr, ARRSIZE);

  for(i = 0; i < ARRSIZE; i++)
  {
    free(arr[i]);
  }

  free(arr);

  return(0);
}


int rotate(int ** arr, int degrees, int size)
{
  if(degrees % 90 != 0)
  {
    printf("Rotation must be a positive factor of 90.\n");
    return(-1);
  }

  while(degrees > 270)
  {
    degrees -= 360;
  }

  switch(degrees)
  {
    case 90:
      rotate90(arr, size);
      break;
    case 180:
      rotate180(arr, size);
      break;
    case 270:
      rotate270(arr, size);
      break;
  }

  return(0);
}


void rotate90(int ** arr, int size)
{
  transpose(arr, size);
  flipColumns(arr, size);
}


void rotate180(int ** arr, int size)
{
  flipRows(arr, size);
  flipColumns(arr, size);
}


void rotate270(int ** arr, int size)
{
  transpose(arr, size);
  flipRows(arr, size);
}


void transpose(int ** arr, int size)
{
  int i;
  int j;

  for(i = 0; i < size; i++)
  {
    for(j = i; j < size; j++)
    {
      if(i != j)
      {
        swap(&arr[i][j], &arr[j][i]);
      }
    }
  }
}

void printArray(int ** arr, int size)
{
  int i;
  int j;

  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void flipRows(int ** arr, int size)
{
  int i, j;

  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size / 2; j++)
    {
      swap(&arr[i][j], &arr[i][size - j - 1]);
    }
  }
}

void flipColumns(int ** arr, int size)
{
  int i, j;

  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size / 2; j++)
    {
      swap(&arr[j][i], &arr[size - j - 1][i]);
    }
  }
}

void swap(int * a, int * b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
