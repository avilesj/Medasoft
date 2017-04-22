#ifndef INVENTORY_H_
#define INVENTORY_H_

int addStock(int productId, char *operation, float amount, char *measureUnit, char *date, char *error);
void getStockReport();
#endif


