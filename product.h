#ifndef PRODUCT_H_
#define PRODUCT_H_
#define MAX_NAME 50
#define MAX_STOCK 50
#define MAX_CATEGORY 50
struct product
{
      int id;
      char name[MAX_NAME];
      char measureUnit[5];
      char category[MAX_CATEGORY];
      char creationDate[10];
      float basePrice;
      float sellingPrice;
      float upperPercentage;
      float lowerPercentage;
}stock[MAX_STOCK];

static const struct product EmptyProduct;

int currentProducts;

int addProduct(int id, float basePrice, float sellingPrice, float upperPercentage, float lowerPercentage, char name[MAX_NAME], char measureUnit[5], char category[MAX_CATEGORY],
    char creationDate[10]);
int searchProduct(int index);
int validateUpperPercentage(float percentage);
int validateLowerPercentage(float percentage);
int validatePrice(float basePrice, float sellingPrice);
#endif
