#ifndef PRODUCT_DATA_H_
#define PRODUCT_DATA_H_
#include "data.h"

void d_addProduct(int id, float basePrice, float sellingPrice, float upperPercentage, float lowerPercentage, char name[], char measureUnit[5], int category,
    char creationDate[10], int pricelist);

char *d_searchProductName(char *id);


#endif
