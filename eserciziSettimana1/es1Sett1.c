#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
//Pietro Siboni, esercizio1 settimana1
int main()
{
    //dichiaro ed inizializzo tutte le variabili
    char carattere = 'A';
    char stringa[] = "Ciao";
    int nInt = 123;
    short int nShortInt = 2345;
    long int nLongInt = 20000030;
    unsigned char nUnsignedChar = '250';
    unsigned int nUnsignedInt = 3;
    unsigned long int nUnsignedLongInt = 880;
    signed char signedCarattere = 'B';
    signed int nSignedInt = -2;
    signed long int nSignedLongInt = -100000;
    float nFloat = 2.50890;
    double nDouble = 29.345;
    long double nLongDouble = 39.9876;
    long long int nLongLongInt = 1838400234;
    int nCaratteriStampati;


    //Stampo con la funzione printf tutti i miei valori e byte per ogni variabile con aggiunta di modificatori e caratteri, stampo i caratteri stampati per ogni printf
    nCaratteriStampati= printf("\tcarattere char valore:%c; byte:%d\n", carattere, sizeof(char));
    printf("Numero di caratteri stampati per char: %d\n\n", nCaratteriStampati);

    nCaratteriStampati= printf("stringa valore: %s; byte:%d\n", stringa, sizeof(char));
    printf("Numero di caratteri stampati per char stringa: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("\bnumero int valore:%10d; \bbyte:%d\n", nInt, sizeof(int));
    printf("Numero di caratteri stampati per int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("\'short int valore:%05d; byte:%d\'\n", nShortInt, sizeof(short int));
    printf("Numero di caratteri stampati per short int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("\\long int valore:%-10d; byte:%d\\\n", nLongInt, sizeof(long int));
    printf("Numero di caratteri stampati per long int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("\?unsigned char valore:%c; byte:%d\?\n", nUnsignedChar, sizeof(unsigned char));
    printf("Numero di caratteri stampati per unsigned char: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("\"unsigned int valore:%d; byte:%d\"\n", nUnsignedInt, sizeof(unsigned int));
    printf("Numero di caratteri stampati per unsigned int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("\aunsigned long int valore:%d; byte:%d\n", nUnsignedLongInt, sizeof(unsigned long int));
    printf("Numero di caratteri stampati per unsigned long int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("signed char valore:%c; byte:%d\n", signedCarattere, sizeof(signed char));
    printf("Numero di caratteri stampati per signed char: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("signed int valore:%d; byte:%d\n", nSignedInt, sizeof(signed int));
    printf("Numero di caratteri stampati per signed int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("\aunsigned long int valore:%d; byte:%d\n", nSignedLongInt, sizeof(signed long int));
    printf("Numero di caratteri stampati per signed long int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati= printf("long long int valore:%d; byte:%d\n", nLongLongInt, sizeof(long long int));
    printf("Numero di caratteri stampati per long long int: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("float valore:%.5f; byte:%d\n", nFloat, sizeof(float));
    printf("Numero di caratteri stampati per float: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("double valore:%.2f; byte:%d\n", nDouble, sizeof(double));
    printf("Numero di caratteri stampati per double: %d\n\n", nCaratteriStampati);

    nCaratteriStampati = printf("long double valore:%8f; byte:%d\n", nLongDouble, sizeof(long double));
    printf("Numero di caratteri stampati per long double: %d\n\n", nCaratteriStampati);




    //stampo i valori massimi e minimi per ogni variabile
    printf("\nchar: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX); 
    printf("short int: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("long int: %d to %d\n", LONG_MIN, LONG_MAX);
    printf("unsigned char: 0 to %e\n", UCHAR_MAX);
    printf("unsigned int: 0 to %e\n", UINT_MAX);
    printf("unsigned long int: 0 to %e\n", ULONG_MAX);
    printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double: %e to %e\n", LDBL_MIN, LDBL_MAX);





    return 0;
}
