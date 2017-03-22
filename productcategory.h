#ifndef PRODUCTCATEGORY_H_
#define PRODUCTCATEGORY_H_
#define MAX 50
struct productCategory
{
      int id;
      char name[50];
}productCategories[MAX];

static const struct productCategory CategoryProduct;

int currentProdCategories;

int addProdCategory(int id, char name[MAX]);
int searchProdCategory(int index);
#endif

