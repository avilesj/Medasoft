#include "inventory.h"

int alterInventory(int productId, int transactionType, int productAmountSystem, int productAmountReal, int operation)
{
    invStock[inventoryCurrentStock].id = inventoryCurrentStock+1;
    invStock[inventoryCurrentStock].productId = productId;
    invStock[inventoryCurrentStock].transactionType = transactionType;
    invStock[inventoryCurrentStock].productAmountSystem = productAmountSystem;
    invStock[inventoryCurrentStock].productAmountReal = productAmountReal;
    invStock[inventoryCurrentStock].operation = operation;
    inventoryCurrentStock++;

    return 0;

}
