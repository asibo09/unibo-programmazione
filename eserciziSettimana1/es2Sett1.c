#define _CRT_SECURE_NO_WARNINGS
#define MIGLIA_TO_KM 1.60934 //costante conversione miglia a km
#define GALLONI_TO_LITRI 3.78541 //costante conversione galloni a litri
#include <stdio.h>

int main()
{
    //dichiaro le variabili
    float miglia;
    float galloni;
    float mpg;

    //chiedo all'utente le miglia percorse e i galloni usati e poi con la funzione scanf per memorizzare i due input
    printf("Inserire il numero di miglia percorse: \n");
    scanf("%f", &miglia);
    printf("Inserire il numero di galloni di benzina consumati: \n");
    scanf("%f", &galloni);

    //inizializzo la variabile miglia per galloni con una divisione tra le due variabili, poi la stampo con due caratteri decimali
    mpg = miglia / galloni;
    printf("Consumo in miglia per gallone: %.2f\n", mpg);

    //dichiaro la variabile per i litri utilizzati ogni 100km e poi con un espressione la inizializzo per portarla alla misura europea tramite le costanti definite sopra per poi stamparla con tre caratteri decimali
    float litriPer100km;
    litriPer100km = (galloni * GALLONI_TO_LITRI) / (miglia * MIGLIA_TO_KM) * 100;
    printf("Consumo in litri per 100km: %.3f\n", litriPer100km);

    return 0;
}