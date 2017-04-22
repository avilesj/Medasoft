#include <stdio.h>
#include <stdlib.h>
#include "invtools.h"
#include "product.h"
#include "productcategory.h"
#include "menu.h"
#include "pricelist.h"
#include "supplier.h"
#include "ump.h"
#include "inventory.h"

char error[50];


void m_searchProduct()
{

    int product_id;
    printf("==================================================\n");
    printf("BUSQUEDA DE PRODUCTOS EN INVENTARIO");
    printf("\n==================================================\n");


    printf("Favor escriba el numero de ID del numero: ");
    scanf("%d", &product_id);

    if(printProduct(product_id, error) != 0)
    {

        printf("\n==================================================\n");
        printf("Hubo un error agregando la categoria: %s", error);
        printf("\n==================================================\n");
        printf("Presione una tecla para continuar");
        clear_newlines();
        getchar();

    }

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
    getchar();
    printf("\nNombre: ");
    fgets(name, 50, stdin);
    strtok(name, "\n");
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


void m_stockReport()
{
    clearScreen();

    int selection;

    printf("==================================================\n");
    printf("REPORTE DE MOVIMIENTOS DE INVENTARIO");
    printf("\n==================================================\n");

    getStockReport();
    clear_newlines();
    getchar();

    menu();
}
void m_negativeReport()
{
    clearScreen();


    printf("==================================================\n");
    printf("REPORTE DE CONTEO NEGATIVO DE INVENTARIO");
    printf("\n==================================================\n");

    printf("ESTA OPCION NO ESTA DISPONIBLE");
    clear_newlines();
    getchar();

    m_addStock();
}

void m_addStock()
{
    clearScreen();

    int selection;

    printf("==================================================\n");
    printf("MOVIMIENTO DE INVENTARIO");
    printf("\n==================================================\n");

    printf("Seleccione la operacion:\n");
    printf("1.  Realizar entrada\n");
    printf("2.  Realizar salida\n");
    printf("3.  Reporte Movimientos\n");
    printf("4.  Reporte Negativos\n");
    printf("0.  Volver\n");
    scanf("%d", &selection);

    while(selection < 0 || selection > 4)
    {
        m_addStock();
    }

    if(selection == 1)
    {
        m_addStockIn();
    }

    if(selection == 2)
    {
        m_addStockOut();
    }

    if(selection == 3)
    {
        m_stockReport();
    }

    if(selection == 4)
    {
        m_negativeReport();
    }


    if(selection == 0)
    {
        menu();
    }

}

void m_addStockIn()
{

    clearScreen();
    int productId;
    char operation[] = "ENTRADA";
    float amount;
    char measureUnit[5];
    char date[10];

    printf("==================================================\n");
    printf("ENTRADA DE INVENTARIO");
    printf("\n==================================================\n");

    printf("ID del producto: ");
    scanf("%d", &productId);
    getchar();
    printf("\nCantidad: ");
    scanf("%f", &amount);
    getchar();
    printf("\nUnidad de medida: ");
    fgets(measureUnit, 5, stdin);
    strtok(measureUnit, "\n");
    printf("\nFecha: ");
    scanf("%s", &date);


    if(addStock(productId, operation, amount, measureUnit, date, error) < 0)
    {
        printf("\n==================================================\n");
        printf("Hubo un error agregando el movimiento: %s", error);
        printf("\n==================================================\n");
        printf("Presione una tecla para continuar");
        clear_newlines();
        getchar();
    }

}


void m_addStockOut()
{


    clearScreen();
    int productId;
    char operation[] = "SALIDA";
    float amount;
    char measureUnit[5];
    char date[10];

    printf("==================================================\n");
    printf("SALIDA DE INVENTARIO");
    printf("\n==================================================\n");

    printf("ID del producto: ");
    scanf("%d", &productId);
    getchar();
    printf("\nCantidad: ");
    scanf("%f", &amount);
    getchar();
    printf("\nUnidad de medida: ");
    fgets(measureUnit, 5, stdin);
    strtok(measureUnit, "\n");
    printf("\nFecha: ");
    scanf("%s", &date);


    if(addStock(productId, operation, amount, measureUnit, date, error) < 0)
    {
        printf("\n==================================================\n");
        printf("Hubo un error agregando el movimiento: %s", error);
        printf("\n==================================================\n");
        printf("Presione una tecla para continuar");
        clear_newlines();
        getchar();
    }
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
        clear_newlines();
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

void m_searchSupplier()
{

    int supplier_id;
    printf("==================================================\n");
    printf("LISTADO DE SUPLIDORES");
    printf("\n==================================================\n");

    if(printSuppliers()<0)
    {
        printf("\n==================================================\n");
        printf("No se encuentran suplidores");
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
    printf("3.  Agregar Categoria\n");
    printf("4.  Mostrar Categorias\n");
    printf("5.  Agregar Lista de Precio\n");
    printf("6.  Mostrar Lista de Precio\n");
    printf("7.  Agregar Suplidor\n");
    printf("8.  Mostrar suplidor\n");
    printf("9.  Mostrar Plan de unidad de medida\n");
    printf("10. Reportes\n");
    printf("0.  Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &option);

    while(option < 0 || option > 10)
    {
        menu();
    }

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
        m_addProdCategory();
    }
    else if(option == 4)
    {
        clearScreen();
        m_searchProductCategory();
    }

    else if(option == 5)
    {
        clearScreen();
        m_addPriceList();
    }

    else if(option == 6)
    {
        clearScreen();
        m_searchPricelist();
    }
    else if(option == 7)
    {
        clearScreen();
        m_addSupplier();
    }

    else if(option == 8)
    {
        clearScreen();
        m_searchSupplier();

    }
    else if(option == 9)
    {
        clearScreen();
        m_printUMP();
    }


    else if(option == 10)
    {
        clearScreen();
        m_addStock();
    }


    else if(option == 99)
    {
        addStock(200, "ENTRADA", 5, "kg", "2017-01-01", error);

    }

    else if(option == 0)
    {
        exit(0);
    }
}
