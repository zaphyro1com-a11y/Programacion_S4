#ifndef funcs
#define funcs

// estructura productos
typedef struct{
   
    char name[25];
    float PVP;
    int stock;
   
} Productos;

// Funciones/Procesos //
void scandVerify_int(int *i);
void scandVerify_float(float *f);
void scanstr(char char_array[]);
void strTolower(char string[], char new_str[]);

void pause();
void presentation();
void drawMainMenu(int *option);
void drawOpt1Menu(int *option);
void addProduct(Productos **p, int *p_number);
void editProduct(Productos **p, int *p_number);
void deleteProduct(Productos **p, int *p_number);
void showInventory(Productos **p, int *p_number);
void showInventoryValue(Productos **p, int *p_number);
void showPriceExtremes(Productos **p, int *p_number);
void ShowAveragePrice(Productos **p, int *p_number);
void productShearch(Productos **p, int *p_number);
void showProduct(Productos **p, int *p_number, int index);

#endif