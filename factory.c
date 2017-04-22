#include "factory.h"
char error[50];
void factoryAddProduct()
{
addProduct(200, 500.00, 700.00, 5.00, 2.00, "BigMac", "oz", 300,
    "2017-01-01", 0, error);
}

void factoryAddProductCategory()
{
    addProdCategory(300, "Hamburguer", error);
}
