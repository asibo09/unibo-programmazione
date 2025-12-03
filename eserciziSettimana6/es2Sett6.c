#include <stdio.h>

int main() {
    int integerVar = 0;
    float floatVar = 0.0;
    double doubleVar = 0.0;
    char charVar = '\0';
    int intArray[5] = { 10, 20, 30, 40, 50 };

    int* intPtr = &integerVar;
    float* floatPtr = &floatVar;
    double* doublePtr = &doubleVar;
    char* charPtr = &charVar;
    int* intArrayPtr = intArray;

    //inizializzazione delle variabili tramite scanf
    printf("Inserisci un intero: ");
    scanf("%d", intPtr);
    printf("Inserisci un numero con la virgola: ");
    scanf("%f", floatPtr);
    printf("Inserisci un numero con due decimali: ");
    scanf("%lf", doublePtr);
    printf("Inserisci un carattere: ");
    scanf(" %c", charPtr);

    //visualizzazione dei valori con accesso diretto e delle posizioni in memoria prima delle modifiche
    printf("\n\nValore dell'intero(accesso diretto pre-modifica): %d\n", integerVar);
    printf("Valore del float(accesso diretto pre-modifica): %f\n", floatVar);
    printf("Valore del double(accesso diretto pre-modifica): %lf\n", doubleVar);
    printf("Valore del carattere(accesso diretto pre-modifica): %c\n", charVar);
    printf("Valore dell'array di interi(accesso diretto pre-modifica): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");


    //visualizzazione dei valori con accesso indiretto pre modifica
    printf("\nValore dell'intero(accesso indiretto pre-modifica): %d\n", *intPtr);
    printf("Valore del float(accesso indiretto pre-modifica): %f\n", *floatPtr);
    printf("Valore del double(accesso indiretto pre-modifica): %lf\n", *doublePtr);
    printf("Valore del carattere(accesso indiretto pre-modifica): %c\n", *charPtr);
    printf("Valore dell'array di interi(accesso indiretto pre-modifica): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", intArrayPtr[i]);
    }
    printf("\n");


    //posizione in memoria accesso diretto
    printf("\nPosizione in memoria dell'intero(accesso diretto pre-modifica): %p\n", (void*)&integerVar);
    printf("Posizione in memoria del float(accesso diretto pre-modifica): %p\n", (void*)&floatVar);
    printf("Posizione in memoria del double(accesso diretto pre-modifica): %p\n", (void*)&doubleVar);
    printf("Posizione in memoria del carattere(accesso diretto pre-modifica): %p\n", (void*)&charVar);
    printf("Posizione in memoria dell'array di interi(accesso diretto pre-modifica): %p\n\n", (void*)intArray);

    //posizione in memoria accesso indiretto
    printf("Posizione in memoria dell'intero(accesso indiretto pre-modifica): %p\n", (void*)intPtr);
    printf("Posizione in memoria del float(accesso indiretto pre-modifica): %p\n", (void*)floatPtr);
    printf("Posizione in memoria del double(accesso indiretto pre-modifica): %p\n", (void*)doublePtr);
    printf("Posizione in memoria del carattere(accesso indiretto pre-modifica): %p\n", (void*)charPtr);
    printf("Posizione in memoria dell'array di interi(accesso indiretto pre-modifica): %p\n", (void*)intArrayPtr);


    //posizione in memoria dei puntatori pre modifica
    printf("\nPosizione in memoria del puntatore all'intero(pre-modifica): %p\n", (void*)&intPtr);
    printf("Posizione in memoria del puntatore al float(pre-modifica): %p\n", (void*)&floatPtr);
    printf("Posizione in memoria del puntatore al double(pre-modifica): %p\n", (void*)&doublePtr);
    printf("Posizione in memoria del puntatore al carattere(pre-modifica): %p\n", (void*)&charPtr);
    printf("Posizione in memoria del puntatore all'array di interi(pre-modifica): %p\n", (void*)&intArrayPtr);

    //modifica dei valori
    *intPtr = 100;
    *floatPtr = 3.14;
    *doublePtr = 2.71828;
    *charPtr = 'X';
    for (int i = 0; i < 5; i++) {
        intArrayPtr[i] *= 2;
    }

    //visualizzazione dei valori e delle posizioni in memoria dopo le modifiche
    printf("\nDopo le modifiche:\n");
    printf("Valore dell'intero(accesso diretto post-modifica): %d\n", integerVar);
    printf("Valore del float(accesso diretto post-modifica): %f\n", floatVar);
    printf("Valore del double(accesso diretto post-modifica): %lf\n", doubleVar);
    printf("Valore del carattere(accesso diretto post-modifica): %c\n", charVar);
    printf("Valore dell'array di interi(accesso diretto post-modifica): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    //visualizzazione dei valori tramite accesso indiretto dopo la modifica
    printf("\nValore dell'intero(accesso indiretto post-modifica): %d\n", *intPtr);
    printf("Valore del float(accesso indiretto post-modifica): %f\n", *floatPtr);
    printf("Valore del double(accesso indiretto post-modifica): %lf\n", *doublePtr);
    printf("Valore del carattere(accesso indiretto post-modifica): %c\n", *charPtr);
    printf("Valore dell'array di interi(accesso indiretto post-modifica): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", intArrayPtr[i]);
    }
    printf("\n");


    //posizione in memoria accesso diretto dopo modifica
    printf("\nPosizione in memoria dell'intero(accesso diretto post-modifica): %p\n", (void*)&integerVar);
    printf("Posizione in memoria del float(accesso diretto post-modifica): %p\n", (void*)&floatVar);
    printf("Posizione in memoria del double(accesso diretto post-modifica): %p\n", (void*)&doubleVar);
    printf("Posizione in memoria del carattere(accesso diretto post-modifica): %p\n", (void*)&charVar);
    printf("Posizione in memoria dell'array di interi(accesso diretto post-modifica): %p\n\n", (void*)intArray);

    //posizione in memoria accesso indiretto dopo modifica
    printf("Posizione in memoria dell'intero(accesso indiretto post-modifica): %p\n", (void*)intPtr);
    printf("Posizione in memoria del float(accesso indiretto post-modifica): %p\n", (void*)floatPtr);
    printf("Posizione in memoria del double(accesso indiretto post-modifica): %p\n", (void*)doublePtr);
    printf("Posizione in memoria del carattere(accesso indiretto post-modifica): %p\n", (void*)charPtr);
    printf("Posizione in memoria dell'array di interi(accesso indiretto post-modifica): %p\n\n", (void*)intArrayPtr);


    //posizione in memoria dei puntatori post modifica
    printf("\nPosizione in memoria del puntatore all'intero(post-modifica): %p\n", (void*)&intPtr);
    printf("Posizione in memoria del puntatore al float(post-modifica): %p\n", (void*)&floatPtr);
    printf("Posizione in memoria del puntatore al double(post-modifica): %p\n", (void*)&doublePtr);
    printf("Posizione in memoria del puntatore al carattere(post-modifica): %p\n", (void*)&charPtr);
    printf("Posizione in memoria del puntatore all'array di interi(post-modifica): %p\n", (void*)&intArrayPtr);
    return 0;
}
