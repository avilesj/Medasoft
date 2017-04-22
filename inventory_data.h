#ifndef INVENTORY_DATA_H_
#define INVENTORY_DATA_H_
#include "data.h"

int d_addStock(int productId, char *operation, float amount, char *measureUnit, char *date);
int d_getLastId();
void d_getStockReport();
#endif

