//programa Inventario tienda

#include "funcs.h"
#include <stdio.h>
 
int main(){

    #pragma VARIABLES
    //numero de productos limite
    int num_products= 0;
    //caracteristicas de cada producto
    char name_product[MAX_PRODUCTS][MAX_INPUT];
    float PVP[MAX_PRODUCTS];
    int stock[MAX_PRODUCTS];
    // opcion de los menus
    int menu_option= 0;

    #pragma endregion

    presentation();

    //Bucle del programa
    while(menu_option != 7){

        menu_option= drawMainMenu();
        
        switch(menu_option){
        case 1:

            num_products= addProduct(stock, PVP, name_product, num_products);
            pause();  

            
            break;
        case 2:
           showInventory(stock, PVP, name_product, num_products);
           pause();
            
            break;
        case 3:
            showInventoryValue(stock, PVP, num_products);
            pause();
            
            break;
        case 4:
            showPriceExtremes(stock, PVP, name_product, num_products);
            pause();
            
            break;
        case 5:
            ShowAveragePrice(PVP, num_products);
            pause();

            break;
        case 6:
            productShearch(stock, PVP, name_product, num_products);
            pause();
            
            break;
        case 7:
            printf("\nSALIENDO DEL PROGRAMA...\n");
            
            break;
        
        default:
            printf("Opcion Invalida\n");
            
            break;
        }
    }
    

    return 0;
}