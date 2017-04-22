#include "category_data.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FIELDS 2
#define MAX_LINE_LENGTH 200

char category_fields[MAX_FIELDS][MAX_LINE_LENGTH] = {"ID", "DESCRIPCION"};

void d_addProductCategory(int id, char *name)
    {
        file = fopen("categories.txt", "a");
        fprintf(file,"%d\t%s\n", id, name);
        fclose(file);
    }

int d_printProductCategories()
{
        file = fopen("categories.txt", "r");

        if(file== NULL)
        {
            return -1;
        }

        char arr[MAX_LINE_LENGTH];
        int i;

        for(i = 0; i < MAX_FIELDS; i++)
        {
            printf("%s\t", category_fields[i]);
        }
        printf("\n");


      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            fputs(arr, stdout);
        }
        fclose(file);
        return 0;
}

int d_searchProductCategory(char *id)
    {
         file = fopen("categories.txt", "r");

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
