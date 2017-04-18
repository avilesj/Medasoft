#include "pricelist.h"

int currentPriceList = 0;

int addPriceList(int id, char name[MAX_NAME])
{
    if(searchPriceList(id) != -1)
    {
        return -1;
    }
    else
    {
        priceList[currentPriceList].id = id;
        memcpy(priceList[currentpriceLists].name, name, 50);
        currentpriceLists++;
        return 0;
    }
}

int searchPriceList(int id)
{
    for(int i =0; i < MAX_PRICELIST; i++)
    {
        if(priceLists[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

int deletePriceList(int id)
{
    priceLists[id] = emptypricelist;
    return 0;
}
