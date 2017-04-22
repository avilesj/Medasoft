#include <stdio.h>
#include <stdlib.h>
#include "invtools.h"
#include "product.h"
#include "productcategory.h"
#include "menu.h"
#include "pricelist.h"
#include "supplier.h"

char error[50];

//int printProduct(int index)
//{
//  printf("\n");
//  printf("\tID: %d\n", stock[index].id);
//  printf("\tNombre: %s", stock[index].name);
//  printf("\tUnidad de medida: %s", stock[index].measureUnit);
//  printf("\tCategoria: %d", stock[index].category);
//  printf("\tFecha de registro: %s", stock[index].creationDate);
//  printf("\t\nPrecio de adquisicion: %.2f\n", stock[index].basePrice);
//  printf("\tPrecio de ventas: %.2f\n", stock[index].sellingPrice);
//  printf("\tPorcentaje superior: %f\n", stock[index].upperPercentage);
//  printf("\tPorcentaje inferior: %f\n\n", stock[index].lowerPercentage);
//}

//int printPriceList(int index)
//{
//  printf("\n");
//  printf("\tID: %d\n", priceLists[index].id);
//  printf("\t Nombre: %s", priceLists[index].name);
//}
//int printSupplier(int index)
//{
//  printf("\n");
//  printf("\tID: %d\n", suppliers[index].id);
//  printf("\t Nombre: %s", suppliers[index].namecompany);
//  printf("\tID lista de precio: %d\n", suppliers[index].pricelist);
//  printf("\t RNC: %s", suppliers[index].RNC);
//  printf("\t Contactos: %s", suppliers[index].contac);
//}


void m_deleteProductCategory()
{

  int productCategory_id;
  char decision;

  printf("==================================================\n");
  printf("ELIMINACION DE CATEGORIAS DE PRODUCTOS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el ID de la categoria de producto a eliminar: ");
  scanf("%d", &productCategory_id);


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();

}

void m_deleteProduct()
{

  int product_id;
  char decision;
  printf("==================================================\n");
  printf("ELIMINACION DE PRODUCTOS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el ID del producto a eliminar: ");
  scanf("%d", &product_id);


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();

}

void m_searchProduct()
{

  int product_id;
  printf("==================================================\n");
  printf("BUSQUEDA DE PRODUCTOS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el numero de ID del numero: ");
  scanf("%d", &product_id);

    tprintProduct(product_id);


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();


}


void m_searchProductCategory()
{

  printf("==================================================\n");
  printf("BUSQUEDA DE CATEGORIAS EN INVENTARIO");
  printf("\n==================================================\n");

  if(printProductCategory()<0)
  {
    clearScreen();
    printf("No hay categorias en el sistema\n\n");

  }


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();


}

void m_searchPricelist()
{

  printf("==================================================\n");
  printf("BUSQUEDA DE LISTAS DE PRECIO EN INVENTARIO");
  printf("\n==================================================\n");

  if(printPricelists()<0)
  {
    clearScreen();
    printf("No hay listas de precio en el sistema\n\n");

  }


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();


}

void m_printUMP()
{

  printf("==================================================\n");
  printf("PLAN DE UNIDAD DE MEDIDA");
  printf("\n==================================================\n");

  if(printUMP()<0)
  {
    clearScreen();
    printf("No existe plan de unidad de medida\n\n");

  }


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();


}

void m_addProduct()
{
  clearScreen();

  int id;
  char name[MAX_NAME];
  float basePrice;
  char measureUnit[5];
  int category;
  char creationDate[10];
  int pricelist;
  float sellingPrice;
  float upperPercentage;
  float lowerPercentage;

  printf("==================================================\n");
  printf("ADICION DE PRODUCTOS A INVENTARIO");
  printf("\n==================================================\n");

  printf("ID: ");
  scanf("%d", &id);
  printf("\nNombre: ");
  scanf("%s", name);
  printf("Unidad de medida: ");
  scanf("%s", measureUnit);
  printf("Fecha de registro(yyyy-mm-dd): ");
  scanf("%s", &creationDate);
  printf("Lista de precio: ");
  fscanf(stdin,"%d", &pricelist);
  printf("Precio de adquisicion: ");
  scanf("%f", &basePrice);
  printf("Precio de venta: ");
  scanf("%f", &sellingPrice);
  printf("Porcentaje superior: ");
  scanf("%f", &upperPercentage);
  printf("Porcentaje inferior: ");
  scanf("%f", &lowerPercentage);
  printf("Categoria: ");
  scanf(" %d", &category);

  if(addProduct(id,basePrice, sellingPrice, upperPercentage, lowerPercentage, name, measureUnit, category, creationDate, pricelist, error) < 0)
  {
    printf("\n==================================================\n");
    printf("Hubo un error agregando el producto: %s", error);
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  else
  {
    printf("\n==================================================\n");
    printf("Producto agregado exitosamente!");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  menu();
}

void m_addProdCategory()
{
  clearScreen();

  int id;
  char name[MAX_NAME];

  printf("==================================================\n");
  printf("ADICION DE CATEGORIAS A INVENTARIO");
  printf("\n==================================================\n");

  printf("ID: ");
  scanf("%d", &id);
  clear_newlines();
  printf("\nNombre: ");
  scanf("%s", &name);

  if(addProdCategory(id,name, error) < 0)
  {
    printf("\n==================================================\n");
    printf("Hubo un error agregando la categoria: %s", error);
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  else
  {
    printf("\n==================================================\n");
    printf("Categoria agregada exitosamente!");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  menu();
}

void m_addPriceList()
{
  clearScreen();

  int id;
  char name[MAX_NAME];

  printf("==================================================\n");
  printf("ADICION DE LISTAS DE PRECIO");
  printf("\n==================================================\n");

  printf("ID: ");
  scanf("%d", &id);
  clear_newlines();
  printf("\nNombre: ");
  scanf("%s", &name);

  if(addPriceList(id,name, error) < 0)
  {
    printf("\n==================================================\n");
    printf("Hubo un error agregando la lisa de precio: %s", error);
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  else
  {
    printf("\n==================================================\n");
    printf("Lista agregada exitosamente!");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  menu();
}

void m_deletePriceList()
{

  int priceList_id;
  char decision;

  printf("==================================================\n");
  printf("ELIMINACION DE lISTAS DE PRECIOS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el ID de la lista de precio que desea eliminar: ");
  scanf("%d", &priceList_id);

  int search = searchPriceList(priceList_id);


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();

}

void m_addSupplier()
{
  clearScreen();

  int id;
  char namecompany[50];
  int pricelist;
  char RNC[9];
  char contact[12];

  printf("==================================================\n");
  printf("ADICION DE SUPLIDORES");
  printf("\n==================================================\n");

  printf("ID: ");
  scanf("%d", &id);
  getchar();
  printf("\nNombre de la compañía: ");
  fgets(namecompany, 50, stdin);
  strtok(namecompany, "\n");
    printf("ID Lista De Precio: ");
  scanf("%d", &pricelist);
  getchar();
  printf("\nRNC: ");
  scanf("%s", &RNC);
  printf("\nContactos: ");
  scanf("%s", &contact);

  if(addSupplier(id,namecompany,RNC,contact,pricelist,error) < 0)
  {
    printf("\n==================================================\n");
    printf("Hubo un error agregando el suplidor: %s", error);
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    getchar();
  }
  else
  {
    printf("\n==================================================\n");
    printf("Suplidor agregado exitosamente!");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  menu();
}

void m_deleteSupplier()
{

  int supplier_id;
  char decision;

  printf("==================================================\n");
  printf("ELIMINACION DE SUPLIDORES EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el ID del supplidor que desea eliminar: ");
  scanf("%d", &supplier_id);

  int search = searchSupplier(supplier_id);

  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();

}

void m_searchSupplier()
{

  int id;
  printf("==================================================\n");
  printf("LISTADO DE SUPLIDORES");
  printf("\n==================================================\n");


    if(printSuppliers()<0)
    {
    printf("\n==================================================\n");
    printf("No se encuentran suplidres");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();

    }

clear_newlines();
getchar();
  menu();


}


void menu()
{
  int option;

  clearScreen();
  printf("==================================================\n");
  printf("\t\tInventario MEDASOFT\n");
  printf("==================================================\n");
  printf("1.  Agregar producto\n");
  printf("2.  Buscar producto\n");
  printf("3.  Eliminar producto\n");
  printf("4.  Agregar Categoria\n");
  printf("5.  Mostrar Categorias\n");
  printf("6.  Eliminar Categoria\n");
  printf("7.  Agregar Lista de Precio\n");
  printf("8.  Mostrar Lista de Precio\n");
  printf("9.  Agregar Suplidor\n");
  printf("10. Mostrar suplidor\n");
  printf("11. Mostrar Plan de unidad de medida\n");
  printf("12. Eliminar suplidor\n");
  printf("13. Test\n");
  printf("0.  Salir\n");
  scanf("%d", &option);

  if(option == 1)
  {
    clearScreen();
    m_addProduct();
  }
  else if(option == 2)
  {
    clearScreen();
    m_searchProduct();
  }
   else if(option == 3)
  {
    clearScreen();
    m_deleteProduct();
  }
  else if(option == 4)
  {
    clearScreen();
    m_addProdCategory();
  }

  else if(option == 5)
  {
    clearScreen();
    m_searchProductCategory();
  }

  else if(option == 6)
  {
    clearScreen();
    m_deleteProductCategory();
  }
  else if(option == 7)
  {
    clearScreen();
    m_addPriceList();
  }

   else if(option == 8)
  {
      clearScreen();
      m_searchPricelist();

  }
else if(option == 9)
  {
    clearScreen();
    m_addSupplier();
  }


else if(option == 10)
  {
    clearScreen();
    m_searchSupplier();
  }


else if(option == 11)
  {
    clearScreen();
    m_printUMP();
  }

  else if(option == 0)
  {
    exit(0);
  }
}
