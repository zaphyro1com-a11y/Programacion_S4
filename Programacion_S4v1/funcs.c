#include "funcs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // para strTolower()

void pause(){

    printf("\nPresione ENTER para continuar...");
    getchar();

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

int scandVerify_int(){

    char aux[MAX_INPUT];
    char *endptr;
    int var= 0;
    
    // leer numero como caracter
    fgets(aux, MAX_INPUT, stdin);

    // convertir caracter a entero y guardar en la variable
    var= (int) strtol(aux, &endptr, 10);

    //comprobar que se hayan ingresado numeros
    if (endptr == aux) {
        printf("ERROR: no ingresaste un numero valido.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_int();
    }

    // comprobar si el numero es mayor < 0
    if(var<0){
        printf("ERROR: El programa solo acepta valores positivos.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_int();
    }

    return var;

}

int drawMainMenu(){
 
    printf("\nX---------------------------------------------X\n");
    printf("| (1) Ingresar Producto                       |\n");
    printf("| (2) Mostrar Inventario                      |\n");
    printf("| (3) Calcular el precio total del inventario |\n");
    printf("| (4) Producto mas caro/barato                |\n");
    printf("| (5) Calcular precio Promedio                |\n");
    printf("| (6) Buscar Producto por nombre              |\n");
    printf("| (7) SALIR                                   |\n");
    printf("X---------------------------------------------X\n");
    printf(" Opcion >>> ");
    return scandVerify_int();
}

float scandVerify_float(){

    char aux[MAX_INPUT];
    char *endptr;
    float var;
    
    // leer numero como caracter
    fgets(aux, MAX_INPUT, stdin);

    // convertir caracter a entero y guardar en la variable
    var= strtof(aux, &endptr);

    //comprobar que se hayan ingresado numeros
    if (endptr == aux) {
        printf("ERROR: no ingresaste un numero valido.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_float();
    }

    // comprobar si f es mayor a 0
    if(var<0){
        printf("ERROR: El programa solo acepta valores positivos.\n");
        printf("Ingrese un nuevo valor: ");
        scandVerify_float();
    }

    return var;
}

void scanstr(char char_array[]){

    fgets(char_array, MAX_INPUT, stdin);
  
    //borrar salto de linea
    int length = strlen(char_array);
    if (length > 0 && char_array[length - 1] == '\n'){
        char_array[length - 1] = '\0';
    }

}

void strTolower(char string[], char new_str[]) {
    int i = 0;
    // Convertir cada caracter a minuscula y guardarlo en new_str
    while(string[i]) {
        new_str[i] = tolower((unsigned char)string[i]);
        i++;
    }
    // AGREGRAR al nuevo string el caracter '\0'
    new_str[i] = '\0'; 
}

int addProduct(int stock[], float pvp[], char names[][MAX_INPUT], int p_number){

    // redimensionar
    p_number++;

    //Ingresar datos
    printf("Nombre del Producto: ");
    scanstr(names[p_number-1]); 

    printf("Ingrese el Precio de Venta al Publico (PVP): ");
    pvp[p_number-1]= scandVerify_float(); 

    printf("Ingrese el Stock del Producto: ");
    stock[p_number-1]= scandVerify_int(); 

    printf("\n <<Productos Agregados Exitosamente>>\n");

    return p_number;

}

void showInventory(int stock[], float pvp[], char names[][MAX_INPUT], int p_number){

    printf("\t=====================\n");
    printf("\t      INVENTARIO     \n");
    printf("\t=====================\n");

    //%-20s: cadena de caracteres con un ancho de 20 caracteres, (-)= alineada a la izquierda
    printf(" %-20s %-6s %-6s\n", "PRODUCTOS", "PVP", "STOCK");
    printf("---------------------------------\n");
    for (int i= 0; i<(p_number); i++){

        printf(" %-20s %-6.2f  %-6d\n", names[i], pvp[i], stock[i]);

    }

}

void showInventoryValue(int stock[], float pvp[], int p_number){

    float ttl_value= 0.0;
    // calculaR VALOR TOTAL
    for(int i=0; i < p_number; i++){

        ttl_value += (pvp[i])*(stock[i]);

    }
    printf(" ================================\n");
    printf("   VALOR TOTAL DEL INVENTARIO\n");
    printf(" ================================\n");
    printf("\nEl valor total del inventario es: $%.2f\n", ttl_value);

}

void showPriceExtremes(int stock[], float pvp[], char names[][MAX_INPUT], int p_number){

    int most_expensive_product_index= 0, cheapest_product_index= 0;

    //calcular el producto mas caro y barato
    for(int i= 1; i< p_number; i++){

        if( pvp[i] > pvp[most_expensive_product_index] ) most_expensive_product_index= i;
        if( pvp[i] < pvp[cheapest_product_index] ) cheapest_product_index= i;

    }

    printf(" ================================\n");
    printf("   PRODUCTOS EXTREMOS EN PRECIO\n");
    printf(" ================================\n");

    printf("Producto Mas Costoso: \n %-20s %-6.2f %-6d \n", 
        names[most_expensive_product_index],
        pvp[most_expensive_product_index],
        stock[most_expensive_product_index]);

    printf("\nProducto Mas Barato: \n %-20s %-6.2f %-6d \n",
        names[cheapest_product_index],
        pvp[cheapest_product_index],
        stock[cheapest_product_index]);

}

void ShowAveragePrice(float pvp[], int p_number){

    float avrg_price= 0;
    float sum_prices= 0.0;

    // calculaR VALOR TOTAL
    for(int i=0; i < p_number; i++){

        sum_prices += (pvp[i]);

    }

    //calcular Promedio
    avrg_price= sum_prices/(p_number);

    printf(" ================================\n");
    printf("         PRECIO PROMEDIO\n");
    printf(" ================================\n");

    printf("\n\t\t%.2f\n", avrg_price);

}

void productShearch(int stock[], float pvp[], char names[][MAX_INPUT], int p_number){

    // Variables
    char search[MAX_INPUT]= "                         ";
    int results_index[10];  //lista de coincidencias
    int k= 0, differences; //numero de productos coincidentes //despues de la comparacion: el numero de coincidencias
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
    for(int i=0; i<p_number; i++){

        differences= 0;
        strTolower(names[i], normalized_product_name); //normalizar

        // comparar subcadenas //
       if((strstr(normalized_product_name, normalized_search) != NULL) ||(strstr(normalized_search, normalized_product_name) != NULL) ){
            if(k < 10){
                    results_index[k++]= i;

            }
        }else{ // comparar por caracteres //
            limit_of_differences= strlen(normalized_search)*0.3;
            if (limit_of_differences <= 0) limit_of_differences=1;
            
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

            printf(" (%d) %-25s \n", results_index[i]+1,names[results_index[i]]);

        }
        printf(" Producto >>> ");
        option= scandVerify_int();
        showProduct(stock, pvp, names, --option); // -- para ajustar al indice del arreglo
    }
}

void showProduct(int stock[], float pvp[], char names[][MAX_INPUT], int index){

    printf("\n=======================================");
    printf("\n\t%-25s\n", names[index]);
    printf("=======================================\n");
    printf("     PVP      STOCK\n");
    printf("---------------------------------------\n");
    printf("    %.2f      %d\n", pvp[index], stock[index]);

}