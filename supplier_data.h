#ifndef SUPPLIER_DATA_H_
#define SUPPLIER_DATA_H_
#include "data.h"
#define NAME_MAX 50

void d_addSupplier(int id, char *name, char *rnc, char *contact, int pricelist);
int d_printSuppliers();
int d_searchSupplier(char *id);
#endif

