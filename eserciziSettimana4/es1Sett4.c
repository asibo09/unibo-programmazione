
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* leggiVettore(int lunghezza) {
    int* vettore = (int*)malloc(sizeof(int) * lunghezza);

    for (int i = 0; i < lunghezza; i++) {
        printf("Inserisci il valore %d: ", i + 1);
        scanf("%d", &vettore[i]);
    }

    return vettore;
}

int* generaVettoreCasuale(int lunghezza) {
    int* vettore = (int*)malloc(sizeof(int) * lunghezza);

    for (int i = 0; i < lunghezza; i++) {
        vettore[i] = rand() % 100; //genera numeri casuali tra 0 e 99
    }

    return vettore;
}

int* unione(int* vettore1, int lunghezza1, int* vettore2, int lunghezza2, int* dimensioneRisultato) {
    int* risultato = (int*)malloc(sizeof(int) * (lunghezza1 + lunghezza2));

    for (int i = 0; i < lunghezza1; i++) {
        risultato[(*dimensioneRisultato)++] = vettore1[i];
    }

    for (int i = 0; i < lunghezza2; i++) {
        int presente = 0;
        for (int j = 0; j < lunghezza1; j++) {
            if (vettore2[i] == vettore1[j]) {
                presente = 1;
                break;
            }
        }
        if (!presente) {
            risultato[(*dimensioneRisultato)++] = vettore2[i];
        }
    }

    return risultato;
}



int* intersezione(int* vettore1, int lunghezza1, int* vettore2, int lunghezza2, int* dimensioneRisultato) {
    int* risultato = 0;

    *dimensioneRisultato = 0;
    risultato = (int*)malloc(sizeof(int) * lunghezza1); //l'intersezione pu� avere al massimo dimensione1 elementi
    int indice1 = 0;
    //per ogni valore di vettore2, controllo se � presente in vettore1
    for (int i = 0; i < lunghezza2; i++) {
        while (indice1 < lunghezza1 && vettore1[indice1] != vettore2[i]) {
            indice1++;
        }

        //se il valore � presente, aggiungo al risultato
        if (indice1 < lunghezza1) {
            risultato[(*dimensioneRisultato)++] = vettore1[indice1];
        }
    }
    return risultato;
}



int main() {
    int lunghezza1, lunghezza2;

    printf("Inserisci la lunghezza del primo vettore: ");
    scanf("%d", &lunghezza1);
    int* vettore1;
    int* vettore2;
    printf("Inserisci la lunghezza del secondo vettore: ");
    scanf("%d", &lunghezza2);


    int scelta;
    printf("Generazione valori:\n1=Random;\n2=Manuale:\n ");
    scanf("%d", &scelta);
    

    if (scelta == 1) {
        //genera i vettori casualmente
        srand(time(0));
        vettore1 = generaVettoreCasuale(lunghezza1);
        vettore2 = generaVettoreCasuale(lunghezza2);
    }
    else if (scelta == 2) {
        // Leggo manualmente i vettori per poi stamparli a video successivamente
        vettore1 = leggiVettore(lunghezza1);
        vettore2 = leggiVettore(lunghezza2);
    }
    else {
        printf("Scelta non valida.\n");
        return 1;
    }

    printf("\nPrimo vettore:   ");
    for (int i = 0; i < lunghezza1; i++) {
        printf("%d ", vettore1[i]);
    }
    printf("\n");

    // Stampa il secondo vettore
    printf("Secondo vettore:   ");
    for (int i = 0; i < lunghezza2; i++) {
        printf("%d ", vettore2[i]);
    }
    printf("\n\n");


    int dimensioneRisultato = 0;
    int* risultatoIntersezione = intersezione(vettore1, sizeof(vettore1) / sizeof(vettore1[0]), vettore2, sizeof(vettore2) / sizeof(vettore2[0]), &dimensioneRisultato);
    //stampa intersezione
    printf("Intersezione tra i due vettori:\n");
    for (int i = 0; i < dimensioneRisultato; i++) {
        printf("%d ", risultatoIntersezione[i]);
    }
    printf("\n\n");

    //stampa l'unione
    int lunghezza = lunghezza1 + lunghezza2;
    int* risultatoUnione = unione(vettore1, lunghezza1, vettore2, lunghezza2, &dimensioneRisultato);  
    printf("Unione dei due vettori:\n");
    for (int i = 0; i < dimensioneRisultato; i++) {
        printf("%d ", risultatoUnione[i]);
    }
    printf("\n\n");

    //stampo indirizzi di memoria e la dimensione totale
    printf("Indirizzi di memoria e dimensione totale:\n");
    for (int i = 0; i < dimensioneRisultato; i++) {
        printf("Elemento %d: Indirizzo %x\n", i, (void*)&risultatoUnione[i]);
    }
    printf("Dimensione totale in byte: %lu\n", (unsigned long)(dimensioneRisultato * sizeof(int)));


    return 0;
}