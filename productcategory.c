#include "productcategory.h"

int currentProdCategories = 0;

int addProdCategory(int id, char name[MAX_NAME])
{
    if(searchProdCategory(id) != -1)
    {
        return -1;
    }
    else
    {
        productCategories[currentProdCategories].id = id;
        memcpy(productCategories[currentProdCategories].name, name, 50);
        currentProdCategories++;
        return 0;
    }
}

int searchProdCategory(int id)
{
    for(int i =0; i < MAX_CATEGORIES; i++)
    {
        if(productCategories[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

int deleteProdCategory(int id)
{
    productCategories[id] = emptyProductCategory;
    return 0;
}
