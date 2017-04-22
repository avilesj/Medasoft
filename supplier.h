#ifndef SUPPLIER_H_
#define SUPPLIER_H_
#define MAX_NAME 50
#define MAX_SUPPLIER 50
struct supplier
{
      int id;
      char namecompany[MAX_NAME];
      char RNC[9];
      char contac [12];
      int pricelist;

}suppliers[MAX_SUPPLIER];

struct supplier Emptysupplier;

int currentsupplier;

int addSupplier(int id, char namecompany[MAX_NAME], char RNC[9],char contact[12], int pricelist, char *error);
int searchSupplier(int index);
int printSuppliers();

#endif
