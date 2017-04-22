#include "inventory_data.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FIELDS 7
#define MAX_LINE_LENGTH 200
#define FILENAME "inventory.txt"
#include "product_data.h"

char inventory_fields[MAX_FIELDS][MAX_LINE_LENGTH] = {"ID", "IDPRODUCTO", "PRODUCTO", "OPERACION", "CANTIDAD", "UNIDAD", "FECHA"};

int d_addStock(int productId, char *operation, float amount, char *measureUnit, char *date)
{
    int id = d_getLastId();

    char chrId[sizeof(productId)];

    sprintf(chrId, "%d", productId);

    char *productName = d_searchProductName(chrId);
    id++;
    file = fopen(FILENAME, "a");
    fprintf(file,"%d\t%d\t%s\t%s\t%f\t%s\t%s\n", id, productId, productName, operation, amount, measureUnit, date);
    fclose(file);
}

int d_getLastId()
{
    file = fopen(FILENAME, "r");

    if(file== NULL)
    {
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    char *ret;
    char *end;
    int lastId;

    while( fgets(line, MAX_LINE_LENGTH, file) !=NULL )
    {
        // Searching for last line.
    }
    //Get the first string before \t (Must be the ID)
    ret = strtok(line, "\t");
    //Converts the string to INT
    lastId = strtol(ret, &end, 10);
    //END
    return lastId;


    fclose(file);
}

void d_getStockReport()
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
            printf("%s  ", inventory_fields[i]);
        }
        printf("\n");


      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            fputs(arr, stdout);
        }
        fclose(file);
        return 0;
}
