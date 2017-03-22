#ifndef MENU_H_
#define MENU_H_

void menu();
/*Product menu*/
int printProduct(int id);
void m_addProduct();
void m_searchProduct();
void m_deleteProduct();

/*Product Category menu */
int printProdCategory(int id);
void m_addProdCategory();
void m_listProdCategories();
void m_deleteProdCategory();

#endif
