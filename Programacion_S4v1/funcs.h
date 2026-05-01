#ifndef funcs
#define funcs

#define MAX_PRODUCTS 10
#define MAX_INPUT 25

void pause();
void presentation();
int drawMainMenu();
int scandVerify_int();
float scandVerify_float();
void scanstr(char array[]);
void strTolower(char string[], char new_str[]);
int drawOpt1Menu();
int addProduct(int stock[], float pvp[], char names[][MAX_INPUT], int p_number);
void showInventory(int stock[], float pvp[], char names[][MAX_INPUT], int p_number);
void showInventoryValue(int stock[], float pvp[], int p_number);
void showPriceExtremes(int stock[], float pvp[], char names[][MAX_INPUT], int p_number);
void ShowAveragePrice(float pvp[], int p_number);
void productShearch(int stock[], float pvp[], char names[][MAX_INPUT], int p_number);
void showProduct(int stock[], float pvp[], char names[][MAX_INPUT], int index);

#endif