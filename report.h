#ifndef PRICELIST_H_
#define PRICELIST_H_
struct inventoryTransactions
{
      int id;
      char name[50];
}

struct priceList emptypricelist;

int currentpriceLists;

int addPriceList(int id, char name[MAX_NAME]);
int searchPriceList(int index);
int deletePriceList(int index);
#endif


