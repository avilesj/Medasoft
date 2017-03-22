#include "invtools.h"
#include <stdio.h>

/*Different implementations of the clearScreen functions depending on the OS*/
#ifdef _WIN32
void clearScreen()
{
 system("cls");
}
#else
void clearScreen()
{
  //printf("\033c"); <- LINUX ONLY
}
#endif

void clear_newlines()
{
  int c;
  do
  {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
