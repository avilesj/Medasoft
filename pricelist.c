#include "pricelist.h"
#include "pricelist_data.h"

int currentPriceList = 0;

int addPriceList(int id, char name[MAX_NAME], char *error)
{
    if(searchPriceList(id) > 0)
    {
        strcpy(error,"Lista de precio ya existe");
        return -1;
    }
    else
    {
     d_addPricelist(id, name);
        return 0;
    }
}

int printPricelists()
{
    if(d_printPricelists() >= 0)
    {
        return 0;
    }

    return -1;
}

int searchPriceList(int id)
{
    char chrId[sizeof(id)];
    sprintf(chrId, "%d", id);

    if(d_searchPricelists(chrId) < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
