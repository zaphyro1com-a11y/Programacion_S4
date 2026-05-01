//programa Inventario tienda
 
#include "funcs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // para strTolower()
 
int main(){

    // variables locales //
    int num_pdts= 0;
    int selected_option= 0;

    // memoria dinamica //
    Productos *productos;
    productos= malloc(0*sizeof(Productos));
    // Comprobar la reservacion de la memoria
    if (productos == NULL) {
    printf("Error al reservar memoria.\n");
    exit(1);
    }

    presentation();

    //bucle del programa
    while(selected_option != 7){

        drawMainMenu(&selected_option);

        switch(selected_option){
        case 1:
            
            while(selected_option != 4){

                drawOpt1Menu(&selected_option);

                switch(selected_option){
                case 1:

                    addProduct(&productos, &num_pdts);
                    pause();

                    break;

                case 2:

                    editProduct(&productos, &num_pdts);
                    pause();
                    
                    break;

                case 3:

                    deleteProduct(&productos, &num_pdts);
                    pause();

                    break;

                default:
                    printf("Opcion Invalida\n");
                    break;
                }
            }

            break;
        
        case 2:

            showInventory(&productos, &num_pdts);
            pause();

            break;

        case 3:
            
            showInventoryValue(&productos, &num_pdts);
            pause();

            break;

        case 4: 

            showPriceExtremes(&productos, &num_pdts);
            pause();

            break;

        case 5:

            ShowAveragePrice(&productos, &num_pdts);
            pause();

            break;

        case 6:
                    
            productShearch(&productos, &num_pdts);
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
   
    //liberar memoria
    free(productos);

    return 0;
}

