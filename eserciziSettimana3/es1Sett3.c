#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//metodo in cui genero delle coordinate casuali
void generaCoordinate(int* x, int* y) {
    *x = rand() % 330; 
    *y = rand() % 150;
}

int main() {
    srand(time(NULL));  //iInizializza il generatore di numeri casuali

    int punteggio = 0;
    int continua = 1;

    while (continua == 1) {
        int x, y;
        generaCoordinate(&x, &y);//riprendo il metodo scritto sopra

        printf("Coordinate generate: (%d, %d)\n", x, y);
        printf("A quale continente pensi che appartengano? (Europa, America, Asia, Africa, Oceania): ");

        char continente[10];
        scanf("%s", continente);

        //valuto la risposta del giocatore controllando le coordinare ed assegnando loro un punteggio in caso di risposta corretta
        if ((x >= 40 && x < 100) && (y >= 0 && y < 60) && strcmp(continente, "Europa") == 0) {
            printf("Corretto!\n");
            punteggio = punteggio + 40;
        }
        else if ((x >= 0 && x < 40) && (y >= 0 && y < 150) && strcmp(continente, "America") == 0) {
            printf("Corretto!\n");
            punteggio = punteggio + 10;
        }
        else if ((x >= 100 && x < 330) && (y >= 0 && y < 90) && strcmp(continente, "Asia") == 0) {
            printf("Corretto!\n");
            punteggio = punteggio + 40;
        }
        else if ((x >= 40 && x < 120) && (y >= 60 && y < 150) && strcmp(continente, "Africa") == 0) {
            printf("Corretto!\n");
            punteggio = punteggio + 30;
        }
        else if ((x >= 280 && x < 330) && (y >= 90 && y < 150) && strcmp(continente, "Oceania") == 0) {
            printf("Corretto!\n");
            punteggio = punteggio + 50;
        }
        else {
            printf("Sbagliato! Il gioco finisce. Punteggio finale: %d\n", punteggio);
            //chiedo al giocatore una volta finita la partita se intende giocare di nuovo, nel caso azzero il punteggio
            printf("Vuoi giocare di nuovo? (1 = Si, 0 = No): "); 
            printf("\n");
            scanf("%d", &continua);
            if (continua == 0) {
                punteggio = 0; 
            }
        }
    }
    return 0;
}
