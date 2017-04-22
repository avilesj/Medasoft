#include "inventory_data.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FIELDS 7
#define MAX_LINE_LENGTH 200
#define FILENAME "inventory.txt"

char inventory_fields[MAX_FIELDS][MAX_LINE_LENGTH] = {"ID", "IDPRODUCTO", "PRODUCTO", "OPERACION", "CANTIDAD", "UNIDAD", "FECHA"};

int d_addStock(int productId, char *productName, char *operation, float amount, char *measureUnit, char *date)
    {
        file = fopen(FILENAME, "a");
        //fprintf(file,"%d\t%s\t%s\t%s\t%d\n", id, name, rnc, contact, pricelist);
        fclose(file);
    }

int d_getLastId()
{
    file = fopen("inventory.txt", "r");

    if(file== NULL)
        {
            return -1;
        }
}
