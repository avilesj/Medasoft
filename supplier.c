#include "supplier.h"
#include "pricelist.h"
#include <string.h>
#include "supplier_data.h"

currentsupplier = 0;


int searchSupplier(int id)
{
    char chrId[sizeof(id)];
    sprintf(chrId, "%d", id);

    if(d_searchSupplier(chrId) < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int addSupplier(int id, char namecompany[MAX_NAME], char RNC[9],char contact[12], int pricelist, char *error)
{
  if(searchSupplier(id) > -1)
  {
    strcpy(error,"Suplidor ya existe.");
    return -1;
  }

  if(searchPriceList(pricelist) < 0)
  {
    strcpy(error,"Lista de precio no existe");
    return -2;
  }

  else
  {


    d_addSupplier(id, namecompany, RNC, contact, pricelist);

    return 0;
  }
}

int printSuppliers()
{
    if(d_printSuppliers() >= 0)
    {
        return 0;
    }

    return -1;
}
