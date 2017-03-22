#include "invtools.h"
#include <stdio.h>
/*
Function to clear screen on Linux
*/
void clearScreen()
{
  printf("\033c");
}

void clear_newlines(void)
{
  int c;
  do
  {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
