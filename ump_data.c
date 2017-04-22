#include "category_data.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FIELDS 3
#define MAX_LINE_LENGTH 200
#define MAX_ROWS 7
#define FILENAME "ump.txt"

char ump_fields[MAX_FIELDS][MAX_LINE_LENGTH] = {"UNIDAD", "SIMBOLO", "EQUIVALENCIA"};
char ump_values[MAX_ROWS][MAX_LINE_LENGTH] = {"Kilogramo\tkg\t1000", "Hectogramo\thg\t100", "Decagramo\tdag\t10", "Gramo\tg\t1",
                                               "Decigramo\tdg\t0.1", "Centigramo\tcg\t0.01", "Miligramo\tmg\t0.001" };
int d_generateUMP()
    {
        file = fopen(FILENAME, "w");
        for(int i = 0; i < MAX_ROWS; i++)
        {
         fprintf(file,"%s\n", ump_values[i]);
        }
        fclose(file);
    }

    int d_printUMP()
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
            printf("%s\t", ump_fields[i]);
        }
        printf("\n");


      while( fgets (arr, MAX_LINE_LENGTH, file)!=NULL )
        {
            fputs(arr, stdout);
        }
        fclose(file);
        return 0;
}


