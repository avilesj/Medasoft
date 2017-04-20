#include "product_data.h"
#include <stdio.h>
#define MAX_FIELDS 10
#define MAX_LINE_LENGTH 200

const char fields[MAX_FIELDS][MAX_LINE_LENGTH] = {"ID", "NOMBRE", "UNIDAD DE MEDIDA", "CATEGORIA", "FECHA CREACION",
"LISTA DE PRECIO", "PRECIO BASE", "PRECIO VENTA", "PORCENTAJE SUPERIOR", "PORCENTAJE INFERIOR"};

void d_addProduct(int id, float basePrice, float sellingPrice, float upperPercentage, float lowerPercentage, char *name, char *measureUnit, int category,
    char *creationDate, int pricelist)
    {
        file = fopen("products.txt", "a");
        fprintf(file,"%d\t%s\t%s\t%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n", id, name, measureUnit, category, creationDate, pricelist, basePrice, sellingPrice, upperPercentage, lowerPercentage);
        fclose(file);
    }

int d_searchProduct(char *id)
    {
        file = fopen("products.txt", "r");

        char arr[MAX_LINE_LENGTH];

        const char delim[1] = "\t";
        char *ret;

      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            ret = strtok(arr, "\t");
            if(strcmp(ret, id) == 0)
            {
                return 1;
            }
        }
        return -1;


    }

int d_printProducts(char *id)
{
        file = fopen("products.txt", "r");

        char arr[MAX_LINE_LENGTH];
        char printArr[MAX_LINE_LENGTH];
        const char delim[1] = "\t";
        char *ret;

      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            memcpy(printArr, arr, strlen(arr+1));
            ret = strtok(arr, "\t");
            if(strcmp(ret, id) == 0)
            {
                formatPrint(printArr);
                return 1;
            }
        }
        return -1;
}

void formatPrint(char *arr)
{
    char localArr[MAX_FIELDS][50];

    for(int i = 0; i < MAX_FIELDS; i++)
    {
        if(i==0)
        {
            strcpy(localArr[i],strtok(arr, "\t"));
        }
        else
        {
            strcpy(localArr[i],strtok(NULL, "\t"));
        }

    }

    for(int i = 0; i< MAX_FIELDS; i++)
    {
        printf("\t%s: %s\n", fields[i], localArr[i]);
    }


}
