#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findSpaces(char *);
void replaceSpaces(char *, char *, int, int);

int main(int argc, char * argv[])
{
  if(argc < 2)
  {
    printf("Usage: %s <string>\n", argv[0]);
    return(EXIT_FAILURE);
  }

  int lengthOld = strlen(argv[1]);
  int lengthNew;

  char * newString;
  char * oldString;
    
  oldString = malloc(sizeof(char) * (lengthOld + 1));

  strncpy(oldString, argv[1], lengthOld);

  oldString[lengthOld] = '\0';

  lengthNew = lengthOld + (2 * findSpaces(oldString));

  newString = malloc(sizeof(char) * (lengthNew + 1));

  newString[lengthNew] = '\0';

  printf("Old String: %s\n", oldString);

  replaceSpaces(oldString, newString, lengthOld, lengthNew);

  printf("New String: %s\n", newString);

  free(oldString);
  free(newString);

  return(EXIT_SUCCESS);
}


int findSpaces(char * string)
{
  int i = 0;
  int retVal = 0;

  while(string[i] != '\0')
  {
    if(string[i] == ' ')
    {
      retVal++;
    }
    i++;
  }

  return(retVal);
}


void replaceSpaces(char * old, char * new, int oldIndex, int newIndex)
{
  oldIndex -= 1;
  newIndex -= 1;

  while(oldIndex >= 0)
  {
    if(old[oldIndex] == ' ')
    {
      new[newIndex - 2] = '%';
      new[newIndex - 1] = '2';
      new[newIndex] = '0';

      oldIndex--;
      newIndex -= 3;
    }
    else
    {
      new[newIndex] = old[oldIndex];

      newIndex--;
      oldIndex--;
    }
  }
}
