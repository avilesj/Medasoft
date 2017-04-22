#ifndef PRODUCT_H_
#define PRODUCT_H_
#define MAX_NAME 50
#define MAX_STOCK 50
#define MAX_CATEGORY 50

int addProduct(int id, float basePrice, float sellingPrice, float upperPercentage, float lowerPercentage, char name[MAX_NAME], char measureUnit[5], int category,
    char creationDate[10], int pricelist, char *error);
int searchProduct(int index);
int searchProductName(char *id);
#endif
