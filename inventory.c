#include "inventory.h"
#include "product.h"
#include <time.h>

void setDateNow(int id)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(invStock[id].createDate, sizeof(invStock[id].createDate), "%c", tm);

}

int alterInventory(int productId, int transactionType, int productAmountSystem, int productAmountReal, int operation)
{
    if(searchProduct(productId) < 0)
    {
        return -1;
    }
    invStock[inventoryCurrentStock].id = inventoryCurrentStock+1;
    invStock[inventoryCurrentStock].productId = productId;
    invStock[inventoryCurrentStock].transactionType = transactionType;
    invStock[inventoryCurrentStock].productAmountSystem = productAmountSystem;
    invStock[inventoryCurrentStock].productAmountReal = productAmountReal;
    invStock[inventoryCurrentStock].operation = operation;
    setDateNow(inventoryCurrentStock);
    inventoryCurrentStock++;

    return 0;
}
