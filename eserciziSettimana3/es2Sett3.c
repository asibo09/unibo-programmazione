#include <stdio.h>
#include <ctype.h>

int main() {
    //inizializzo tutte le variabili per i controlli che andrò a fare
    char carattere;
    int spazi = 0;
    int punteggiatura = 0;
    int nuoveLinee = 0;
    int caratteriLetti = 0;
    int maiuscoli = 0;
    int minuscoli = 0;
    int cifre = 0;
    int altriCaratteri = 0;

    //faccio inserire all'utente un testo
    printf("Inserisci un testo terminato da '#':\n");

    //controllo il testo con le funzioni di ctype.h
    while ((carattere = getchar()) != '#') {
        caratteriLetti++;

        if (isspace(carattere)) {
            spazi++;
        }
        if (carattere == '\n') {
            nuoveLinee++;
        }
        if (ispunct(carattere)) {
            punteggiatura++;
        }
        if (isupper(carattere)) {
            maiuscoli++;
        }
        if (islower(carattere)) {
            minuscoli++;
        }
        if (isdigit(carattere)) {
            cifre++;
        }
        if (!isalnum(carattere) && !ispunct(carattere) && !isspace(carattere)) {

            altriCaratteri++;
        }
    }

    //stampo le informazioni ottenute
    printf("\nStatistiche del testo:\n");
    printf("Spazi: %d\n", spazi);
    printf("Caratteri di punteggiatura: %d\n", punteggiatura);
    printf("Caratteri di nuova linea: %d\n", nuoveLinee);
    printf("Caratteri letti: %d\n", caratteriLetti);
    printf("Caratteri maiuscoli: %d\n", maiuscoli);
    printf("Caratteri minuscoli: %d\n", minuscoli);
    printf("Cifre: %d\n", cifre);
    printf("Altri caratteri: %d\n", altriCaratteri);

    return 0;
}
