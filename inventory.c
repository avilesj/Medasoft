#include "inventory.h"
#include "inventory_data.h"
#include "product.h"
int getLastId()
{
    d_getLastId();
}

int addStock(int productId, char *operation, float amount, char *measureUnit, char *date, char *error)
{
    if(searchProduct(productId) > -1)
    {
        d_addStock(productId, operation, amount, measureUnit, date);
        return 0;
    }
    else
    {
        strcpy(error,"Producto no existe.");
        return -1;
    }
}

void getStockReport()
{
    d_getStockReport();
}
