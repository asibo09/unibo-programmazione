#include <stdio.h>
#include <stdlib.h>

#define N 10

void random_walk(char array[N][N]) {
    //inizializza l'array con i punti
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = '.';
        }
    }

    //inizializza le posizioni e lettera
    int i = rand()%N, j = rand() % N;
    char letter = 'A';

    while (1) {

        int direction = rand() % 4;

        //controllo direzione
        switch (direction) {
        case 0:
            if (i > 0 && array[i - 1][j] == '.') {
                i--;
                break;
            }
        case 1:
            if (i < N - 1 && array[i + 1][j] == '.') {
                i++;
                break;
            }
        case 2:
            if (j < N - 1 && array[i][j + 1] == '.') {
                j++;
                break;
            }
        case 3:
            if (j > 0 && array[i][j - 1] == '.') {
                j--;
                break;
            }
        case 100:
            if (!((i > 0 && array[i - 1][j] == '.')|| (i < N - 1 && array[i + 1][j] == '.')|| (j < N - 1 && array[i][j + 1] == '.')|| (j > 0 && array[i][j - 1] == '.')))
            {
                printf("Tutte e quattro direzioni sono bloccate, non si riesce a concludere la passeggiata dopo %c\n\n",letter-1);
                return;
            }
            
        }

        //controllo se la posizione � gi� stata visitata ed assegno lettera
        if (array[i][j] == '.') {
            array[i][j] = letter;
            
            if (letter != 'Z') {
                letter++;
            }
            else { return; }
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));
    char array[N][N];
    random_walk(array);

    //stampa passeggiata
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
