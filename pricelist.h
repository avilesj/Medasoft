#ifndef PRICELIST_H_
#define PRICELIST_H_
#define MAX_NAME 50
#define MAX_PRICELIST 50
struct priceList
{
      int id;
      char name[50];
}priceLists[MAX_PRICELIST];

struct priceList emptypricelist;

int currentpriceLists;

int addPriceList(int id, char name[MAX_NAME], char *error);
int searchPriceList(int index);
int printPricelists();
#endif

