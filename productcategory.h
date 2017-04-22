#ifndef PRODUCTCATEGORY_H_
#define PRODUCTCATEGORY_H_
#define MAX_NAME 50
#define MAX_CATEGORIES 50
struct productCategory
{
      int id;
      char name[50];
}productCategories[MAX_CATEGORIES];

struct productCategory emptyProductCategory;

int currentProdCategories;

int addProdCategory(int id, char name[MAX_NAME], char *error);
int searchProdCategory(int id);
int deleteProdCategory(int index);
int printProductCategory();
#endif

