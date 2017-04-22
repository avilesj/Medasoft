#include "pricelist_data.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FIELDS 2
#define MAX_LINE_LENGTH 200

char pricelist_fields[MAX_FIELDS][MAX_LINE_LENGTH] = {"ID", "DESCRIPCION"};

void d_addPricelist(int id, char *name)
    {
        file = fopen("pricelists.txt", "a");
        fprintf(file,"%d\t%s\n", id, name);
        fclose(file);
    }

int d_printPricelists()
{
        file = fopen("pricelists.txt", "r");

        if(file== NULL)
        {
            return -1;
        }

        char arr[MAX_LINE_LENGTH];
        int i;

        for(i = 0; i < MAX_FIELDS; i++)
        {
            printf("%s\t", pricelist_fields[i]);
        }
        printf("\n");


      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            fputs(arr, stdout);
        }
        fclose(file);
        return 0;
}

int d_searchPricelists(char *id)
    {
         file = fopen("pricelists.txt", "r");

        if(file== NULL)
        {
            return -1;
        }


        char arr[MAX_LINE_LENGTH];

        const char delim[1] = "\t";
        char *ret;

      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            ret = strtok(arr, "\t");
            if(strcmp(ret, id) == 0)
            {
                fclose(file);
                return 1;
            }
        }
        fclose(file);
        return -1;


    }
