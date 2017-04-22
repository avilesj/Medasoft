#include <stdio.h>

int main ()
{
   char line[200]={0,}; // Initialize memory! You have to do this (as for your question)
   int n2=0;
   int n3=0;
FILE *sync = fopen("ump.txt", "r");
   if( sync ) {
      while( fgets(line, 200, sync) !=NULL ) {
      // Just search for the latest line, do nothing in the loop
      }
      printf("Last line %s\n", line); //<this is just a log... you can remove it
      fclose(sync);
      // This will look for Time and it will discard it collecting the number you are looking for in n2 and n3
      if (sscanf(line, "%*[^T]Time: %d.%d", &n2, &n3) ) {
          printf( "%d.%d\n", n2, n3);
      }
   }
}
