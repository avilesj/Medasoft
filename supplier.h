#ifndef SUPPLIER_H_
#define SUPPLIER_H_
#define MAX_NAME 50
#define MAX_SUPPLIER 50
#define MAX_PRICELIST
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

int addsupplier(int id, char namecompany[MAX_NAME], char RNC[9],char contac[12], int pricelist);
int searchsupplier(int index);

#endif
