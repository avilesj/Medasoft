#include "productcategory.h"
#include "category_data.h"

int addProdCategory(int id, char name[MAX_NAME], char *error)
{
    if(searchProdCategory(id) > 0)
    {
        strcpy(error,"Categoria ya existe");
        return -1;
    }
    else
    {
     d_addProductCategory(id, name);
        return 0;
    }
}

int printProductCategory()
{
    if(d_printProductCategories() >= 0)
    {
        return 0;
    }

    return -1;
}

int searchProdCategory(int id)
{
    char chrId[sizeof(id)];
    sprintf(chrId, "%d", id);

    if(d_searchProductCategory(chrId) < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int deleteProdCategory(int id)
{
    productCategories[id] = emptyProductCategory;
    return 0;
}
