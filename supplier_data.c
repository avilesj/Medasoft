#include "category_data.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FIELDS 5
#define MAX_LINE_LENGTH 200
#define FILENAME "suppliers.txt"

char supplier_fields[MAX_FIELDS][MAX_LINE_LENGTH] = {"ID", "EMPRESA", "RNC", "CONTACTO", "LISTA DE PRECIO"};

void d_addSupplier(int id, char *name, char *rnc, char *contact, int pricelist)
    {
        file = fopen(FILENAME, "a");
        fprintf(file,"%d\t%s\t%s\t%s\t%d\n", id, name, rnc, contact, pricelist);
        fclose(file);
    }

int d_printSuppliers()
{
        file = fopen(FILENAME, "r");

        if(file== NULL)
        {
            return -1;
        }

        char arr[MAX_LINE_LENGTH];
        int i;

        for(i = 0; i < MAX_FIELDS; i++)
        {
            printf("%s\t", supplier_fields[i]);
        }
        printf("\n");


      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            fputs(arr, stdout);
        }
        fclose(file);
        return 0;
}

int d_searchSupplier(char *id)
    {
         file = fopen(FILENAME, "r");

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

