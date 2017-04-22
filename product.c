#include "product.h"
#include "productcategory.h"
#include <string.h>
#include "product_data.h"
currentProducts = 0;

int validateUpperPercentage(float percentage)
{
  if(percentage <=15)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int validateLowerPercentage(float percentage)
{
  if(percentage <=10)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int validatePrice(float basePrice, float sellingPrice)
{
  if(basePrice < sellingPrice)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int validateNegative(float basePrice, float sellingPrice)
{
  if(basePrice < 0 || sellingPrice < 0)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int searchProduct(int id)
{
    char chrId[sizeof(id)];
    sprintf(chrId, "%d", id);

    if(d_searchProduct(chrId) > 0)
    {
        return 0;
    }

    return -1;
}

int addProduct(int id, float basePrice, float sellingPrice, float upperPercentage, float lowerPercentage, char name[MAX_NAME], char measureUnit[5], int category,
    char creationDate[10], int pricelist, char *error)
{
  if(searchProduct(id) > -1)
  {
    strcpy(error,"Producto ya existe.");
    return -1;
  }

  if(validateUpperPercentage(upperPercentage) != 0)
  {
    strcpy(error,"Porcentaje superior invalido.");
    return -2;
  }
  if(validateLowerPercentage(lowerPercentage) !=0)
  {
    strcpy(error,"Porcentaje inferior invalido.");
    return -3;
  }

  if(validatePrice(basePrice, sellingPrice) !=0)
  {
    strcpy(error,"El precio de venta debe ser mayor al precio base");
    return -4;
  }
    if(validateNegative(basePrice, sellingPrice) !=0)
  {
    strcpy(error,"Los precios no pueden tener valores negativos");
    return -5;
  }

  if(searchProdCategory(category) < 0)
  {
    strcpy(error,"Categoria no existe");
    return -6;
  }

  else
  {
    stock[currentProducts].id = id;
    memcpy(stock[currentProducts].name, name, 50);
    memcpy(stock[currentProducts].measureUnit, measureUnit, 50);
    stock[currentProducts].category = category;
    memcpy(stock[currentProducts].creationDate, creationDate, 50);
    stock[currentProducts].basePrice = basePrice;
    stock[currentProducts].sellingPrice = sellingPrice;
    stock[currentProducts].upperPercentage = upperPercentage;
    stock[currentProducts].lowerPercentage = lowerPercentage;

    currentProducts++;

    d_addProduct(id, basePrice, sellingPrice, upperPercentage, lowerPercentage, name, measureUnit, category,
    creationDate, pricelist);

    return 0;
  }
}


void tprintProduct(int id)
{
    char chrId[sizeof(id)];
    sprintf(chrId, "%d", id);

    d_printProducts(chrId);
}
