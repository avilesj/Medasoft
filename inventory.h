#ifndef INVENTORY_H_
#define INVENTORY_H_
#define INVENTORY_MAX 250
struct inventory{

    int id;
    int productId;
    int transactionType;
    int productAmountSystem;
    int productAmountReal;
    int operation;


}invStock[INVENTORY_MAX];

int inventoryCurrentStock = 0;

int alterInventory(int productId, int transactionType, int productAmountSystem, int productAmountReal, int operation);

#endif

