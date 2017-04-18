#include "supplier.h"
#include "pricelist.h"
#include <string.h>

currentsupplier = 0;
int i =0;


int searchsupplier(int id)
{
  for(int i =0 ; i < MAX_SUPPLIER; i++)
  {
    if(suppliers[i].id == id)
    {
      return i;
    }
  }

  return -1;
}

int addsupplier(int id,  char namecompany[MAX_NAME], char contac[12], char RNC[9], int pricelist)
{
  if(searchsupplier(id) != -1)
  {
    return -1;
  }


  if(searchsupplier(pricelist) < 0)
  {
    return -5;
  }
  else
  {
    suppliers[currentsupplier].id = id;
    memcpy(suppliers[currentsupplier].namecompany, namecompany, 50);
    memcpy(suppliers[currentsupplier].RNC, RNC, 9);
    memcpy(suppliers[currentsupplier].contac, contac, 12);
    suppliers[currentsupplier].pricelist = pricelist;
    currentsupplier++;
    return 0;
  }
}
