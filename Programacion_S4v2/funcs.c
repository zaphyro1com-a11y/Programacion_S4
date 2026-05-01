#include "funcs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // para strTolower()

void pause(){

    printf("\nPresione ENTER para continuar...");
    getchar();

}

void drawMainMenu(int *option){
 
    printf("\nX---------------------------------------------X\n");
    printf("| (1) Ingresar Productos                      |\n");
    printf("| (2) Mostrar Inventario                      |\n");
    printf("| (3) Calcular el precio total del inventario |\n");
    printf("| (4) Producto mas caro/barato                |\n");
    printf("| (5) Calcular precio Promedio                |\n");
    printf("| (6) Buscar Producto por nombre              |\n");
    printf("| (7) SALIR                                   |\n");
    printf("X---------------------------------------------X\n");
    printf(" Opcion >>> ");
    scandVerify_int(option);
}

void presentation(){

    printf(" ===========================\n");
    printf("\t Bienvenido\n");
    printf(" ===========================\n");
    printf("Bienvenid@ a su gestor de inventario\n");
    printf("\nPor favor seleccione una opcion del menu\npara comenzar a gestionar su inventario.\n");
    printf("-----------------------------------------\n");
    pause();

}

void drawOpt1Menu(int *option){

    printf("\nX-------------------------------X\n");
    printf("| (1) Agregar nuevo Producto    |\n");
    printf("| (2) Editar Producto           |\n");
    printf("| (3) Eliminar Producto         |\n");
    printf("| (4) Volver al menu principal  |\n");
    printf("X-------------------------------X\n");
    printf(" Opcion >>> ");
    scandVerify_int(option);

}

void scandVerify_int(int *i){

    char aux[10];
    char *endptr;
    
    // leer numero como caracter
    fgets(aux, sizeof(aux), stdin);

    // convertir caracter a entero y guardar en la variable
    *i= (int) strtol(aux, &endptr, 10);

    //comprobar que se hayan ingresado numeros
    if (endptr == aux) {
        printf("ERROR: no ingresaste un numero valido.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_int(i);
    }

    // comprobar si el numero es mayor < 0
    if(*i<0){
        printf("ERROR: El programa solo acepta valores positivos.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_int(i);
    }

}

void scandVerify_float(float *f){

    char aux[10];
    char *endptr;
    
    // leer numero como caracter
    fgets(aux, sizeof(aux), stdin);

    // convertir caracter a entero y guardar en la variable
    *f= strtof(aux, &endptr);

    //comprobar que se hayan ingresado numeros
    if (endptr == aux) {
        printf("ERROR: no ingresaste un numero valido.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_float(f);
    }

    // comprobar si f es mayor a 0
    if(*f<0){
        printf("ERROR: El programa solo acepta valores positivos.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_float(f);
    }

}

void scanstr(char char_array[]){

    fgets(char_array, 25, stdin);
  
    //borrar salto de linea
    int length = strlen(char_array);
    if (length > 0 && char_array[length - 1] == '\n'){
        char_array[length - 1] = '\0';
    }

}

void addProduct(Productos **p, int *p_number){

    // redimensionar
    (*p_number)++;
    *p = realloc(*p, (*p_number) * (sizeof(Productos)));
    // evaluar
    if (*p == NULL) {
        printf("Error al redimensionar memoria.\n");
        exit(1);
    }

    //Ingresar datos
    printf("Nombre del Producto: ");
    scanstr((*p)[(*p_number)-1].name); // arreglo name dentro del arreglo de productos, no hace falta &.

    printf("Ingrese el Precio de Venta al Publico (PVP): ");
    scandVerify_float(&(*p)[(*p_number)-1].PVP); //direccion de memoria de la variable PVP en el arreglo de productos...

    printf("Ingrese el Stock del Producto: ");
    scandVerify_int(&(*p)[(*p_number)-1].stock); //lo mismo...

    printf("\n <<Productos Agregados Exitosamente>>\n");

}

void editProduct(Productos **p, int *p_number){

    int slct_product;
    int slct_field;

    //dibujar lista de productos
    printf("-------------------------\n");
    for(int i= 0; i<(*p_number); i++){

        printf("(%d) %s\n", i+1, (*p)[i].name);

    }
    printf("-------------------------\n");

    //seleccionar un producto y obtener su indice
    printf(" Seleccione un Producto >>> ");
    scandVerify_int(&slct_product);
    slct_product--;
    //comprobacion de valor
    if(slct_product >= *p_number){
        printf("ERROR: indice invalido.\n");
    return;
    }

    // sleccionar un dato a cambiar
    printf("X---------------------X\n");
    printf("|   (1) Nombre        |\n");
    printf("|   (2) PVP           |\n");
    printf("|   (3) Stock         |\n");
    printf("X---------------------X\n");
    printf(" Seleccione un Campo >>> ");
    scandVerify_int(&slct_field);

    switch(slct_field){
    case 1:
        printf("El nombre actual del producto es: %s\n", (*p)[slct_product].name);
        printf("Escriba el nuevo nombre del producto: ");
        scanstr((*p)[slct_product].name);    

        break;
    case 2:
        printf("El PVP actual del producto es: %.2f\n", (*p)[slct_product].PVP);
        printf("Ingrese el nuevo Precio de Venta: ");
        scandVerify_float(&(*p)[slct_product].PVP);

        break;
    case 3:
        printf("El Stock actual del producto es: %d\n", (*p)[slct_product].stock);
        printf("Ingrese el nuevo Stock: ");
        scandVerify_int(&(*p)[slct_product].stock);

        break;

    default:

        printf("\nOpcion Invalida\n");    

        break;
    }

    printf("\n <<Producto Editado Exitosamente>>\n");

}

void deleteProduct(Productos **p, int *p_number){

    int slct_product;

    //dibujar lista de productos
    printf("-------------------------\n");
    for(int i= 0; i<(*p_number); i++){

        printf("(%d) %s\n", i+1, (*p)[i].name);

    }
    printf("-------------------------\n");

    //seleccionar un producto y obtener su indice
    printf(" Seleccione un Producto >>> ");
    scandVerify_int(&slct_product);
    slct_product--;
    //comprobacion de valor
    if(slct_product >= *p_number){
        printf("ERROR: indice invalido.\n");
    return;
    }

    //reorganizar elementos
    for(int i= slct_product; i<(*p_number)-1; i++){

        (*p)[i]= (*p)[i+1];

    }

    // Reducir tamaño
    (*p_number)--;
    *p= realloc(*p, (*p_number) * sizeof(Productos));

    //verificar
    if (*p == NULL && *p_number > 0) {
        printf("Error al redimensionar memoria.\n");
        exit(1);
    }

    printf("\n <<Producto Eliminado Correctamente>>\n");

}

void showInventory(Productos **p, int *p_number){

    printf("\t=====================\n");
    printf("\t      INVENTARIO     \n");
    printf("\t=====================\n");

    //%-20s: cadena de caracteres con un ancho de 20 caracteres, (-)= alineada a la izquierda
    printf(" %-20s %-6s %-6s\n", "PRODUCTOS", "PVP", "STOCK");
    printf("---------------------------------\n");
    for (int i= 0; i<(*p_number); i++){

        printf(" %-20s %-6.2f  %-6d\n", (*p)[i].name, (*p)[i].PVP, (*p)[i].stock);

    }

}

void showInventoryValue(Productos **p, int *p_number){

    float ttl_value= 0.0;
    // calculaR VALOR TOTAL
    for(int i=0; i < *p_number; i++){

        ttl_value += ((*p)[i].PVP)*((*p)[i].stock);

    }
    printf(" ================================\n");
    printf("   VALOR TOTAL DEL INVENTARIO\n");
    printf(" ================================\n");
    printf("\nEl valor total del inventario es: $%.2f\n", ttl_value);

}

void showPriceExtremes(Productos **p, int *p_number){

    int most_expensive_product_index= 0, cheapest_product_index= 0;

    //calcular el producto mas caro y barato
    for(int i= 1; i< *p_number; i++){

        if( (*p)[i].PVP > (*p)[most_expensive_product_index].PVP ) most_expensive_product_index= i;
        if( (*p)[i].PVP < (*p)[cheapest_product_index].PVP ) cheapest_product_index= i;

    }

    printf(" ================================\n");
    printf("   PRODUCTOS EXTREMOS EN PRECIO\n");
    printf(" ================================\n");

    printf("Producto Mas Costoso: \n %-20s %-6.2f %-6d \n", 
        (*p)[most_expensive_product_index].name,
        (*p)[most_expensive_product_index].PVP,
        (*p)[most_expensive_product_index].stock);

    printf("\nProducto Mas Barato: \n %-20s %-6.2f %-6d \n",
        (*p)[cheapest_product_index].name,
        (*p)[cheapest_product_index].PVP,
        (*p)[cheapest_product_index].stock);

}

void ShowAveragePrice(Productos **p, int *p_number){

    float avrg_price= 0;
    float sum_prices= 0.0;

    // calculaR VALOR TOTAL
    for(int i=0; i < *p_number; i++){

        sum_prices += ((*p)[i].PVP);

    }

    //calcular Promedio
    avrg_price= sum_prices/(*p_number);

    printf(" ================================\n");
    printf("         PRECIO PROMEDIO\n");
    printf(" ================================\n");

    printf("\n\t\t%.2f\n", avrg_price);

}

void strTolower(char string[], char new_str[]) {
    int i = 0;
    // Convertir cada caracter a mayuscula y guardarlo en new_str
    while (string[i]) {
        new_str[i] = tolower((unsigned char)string[i]);
        i++;
    }
    // AGREGRAR al nuevo string el caracter '\0'
    new_str[i] = '\0'; 
}

void showProduct(Productos **p, int *p_number, int index){

    printf("\n=======================================");
    printf("\n\t%-25s\n", (*p)[index].name);
    printf("=======================================\n");
    printf("     PVP      STOCK\n");
    printf("---------------------------------------\n");
    printf("    %.2f      %d\n", (*p)[index].PVP, (*p)[index].stock);

}

void productShearch(Productos **p, int *p_number){

    // Variables
    char search[25]= "                         ";
    int results_index[10];  //lista de coincidencias
    int k= 0, differences; //despues de la comparacion: el numero de coincidencias
    char normalized_search[25];
    char normalized_product_name[25]; //copia y cambia del nombre de los productos
    int limit_of_differences;
    int option=0;

    printf("\n ============================\n");
    printf("     BUSQUEDA DE PRODUCTOS   \n");
    printf(" ============================\n\n");
    printf("Producto: _______________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    scanstr(search);
    strTolower(search, normalized_search); //normalizar la busqueda

    // buscar coincidencias entre subcadenas y por caracteres
    for(int i=0; i<*p_number; i++){

        differences= 0;
        strTolower((*p)[i].name, normalized_product_name); //normalizar

        // comparar subcadenas //
       if((strstr(normalized_product_name, normalized_search) != NULL) ||(strstr(normalized_search, normalized_product_name) != NULL) ){
            if(k < 10){
                    results_index[k++]= i;

            }
        }else{ // comparar por caracteres //
            limit_of_differences= strlen(normalized_search)*0.3;
            for(int i = 0; i < strlen(normalized_search); i++){

                if(normalized_product_name[i] != normalized_search[i]){
                    differences++;
                }
            }
            
            if(differences <= limit_of_differences && k < 10){

                results_index[k++]= i;

            }
        }
    }

    //Mostrar Resultados De Busqueda
    if(k == 0){

        printf("\nNo Se Encontraron Coincidencias.\n");

    } else{

        printf("Lista de Coincidencias: \n");
        for(int i= 0; i<k; i++ ){

            printf(" (%d) %-25s \n", results_index[i]+1,(*p)[results_index[i]].name);

        }
        printf(" Producto >>> ");
        scandVerify_int(&option);
        showProduct(p, p_number, --option); // -- para ajustar al indice del arreglo
    }
}
