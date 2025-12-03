#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int versione;
    printf("Scegliere la versione del programma:\n 1(versione senza numero di tentativi);\n 2(versione con numero di tentativi);\n");
    fflush(stdin);
    scanf("%d", &versione);

    switch(versione)
    {
    case 1:
        printf("Hai scelto la versione senza numero di tentativi\n");
        senzaLimite();
        break;
    case 2:
        printf("Hai scelto la versione con il numero di tentativi\n");
        conLimite();
        break;
    default:
        printf("Scelta non valida.\n");
        return 1;
    }
    return 0;
}

void senzaLimite()
{
    int min, max;
    int numero, tentativo, tentativi = 0;
    int numeroMagico;

    //chiedo all'utente i numeri per l'intervallo e il numero magico
    do {
        printf("Inserisci il numero min: ");
        fflush(stdin);
        scanf("%d", &min);

        printf("Inserisci il numero max: ");
        fflush(stdin);
        scanf("%d", &max);
        if (min <= 0 || min > max) {
            printf("Intervallo non valido. Riprova.\n");
        }
    } while (min <= 0 || min > max);

    do {
        printf("Inserisci il numero magico: ");
        fflush(stdin);
        scanf("%d", &numeroMagico);
        if (min > numeroMagico || max < numeroMagico)
        {
            printf("Numero magico non valido.\n");
        }
    } while (min > numeroMagico || max < numeroMagico);

    //controllo se le condizioni sono giuste
    if (min >= max || min < 0) {
        printf("Intervallo non valido.\n");
    }
    if (min > numeroMagico || max < numeroMagico) {
        printf("Numero magico non valido.\n");
    }

    //inizializzazione generatore numeri casuali
    srand(time(NULL));

    //generazione numero da indovinare
    numero = rand() % (max - min + 1) + min;

    do {
        //proposta del numero da parte del computer
        tentativo = rand() % (max - min + 1) + min;
        printf("Il computer propone: %d\n", tentativo);

        //chiedo all'utente com'� la proposta del computer
        int risposta;
        printf("Il numero da indovinare e' (1 = piu piccolo, 2 = piu grande, 3 = indovinato): ");
        fflush(stdin);
        scanf("%d", &risposta);

        if (risposta == 1) 
        {
            if(numeroMagico!=tentativo && numeroMagico < tentativo)
            max = tentativo - 1;
            else {
                if (numeroMagico > tentativo)
                {
                    printf("Mi hai mentito il numero generato e' piu grande!!!\n"); tentativi - 1;
                }
                if (numeroMagico == tentativo)
                {
                    printf("Mi hai mentito il numero generato e' corretto!!! Indovinato in %d tentativi.\n", tentativi + 1); break;
                }
                
            }
        }
        else if (risposta == 2) 
        {
            if (numeroMagico != tentativo && numeroMagico > tentativo)
                min = tentativo + 1;
            else {
                if (numeroMagico < tentativo)
                {
                    printf("Mi hai mentito il numero generato e' piu piccolo!!!\n");tentativi - 1;
                }
                if (numeroMagico == tentativo)
                {
                    printf("Mi hai mentito il numero generato e' corretto!!! Indovinato in %d tentativi.\n", tentativi + 1); break;
                }
                
            }
        }
        else if (risposta == 3) {
            if (numeroMagico == tentativo) {
                printf("Il computer ha indovinato il numero %d in %d tentativi.\n", numeroMagico, tentativi + 1);
                break;
            }
            else{
                printf("Mi hai mentito il numero generato non e' corretto!!!\n"); tentativi-1;
            }
        }
        else {
            printf("Risposta non valida. Inserisci 1, 2 o 3.\n");
        }
        tentativi++;
    } while (1);

    return 0;
}

void conLimite()
{
    int min, max, maxtentativi;
    int numero, tentativo, tentativi = 0;
    int numeroMagico;

    //chiedo all'utente i numeri per l'intervallo, il numero magico e il numero massimo di tentativi che ha il computer
    do {
        printf("Inserisci il numero min: ");
        fflush(stdin);
        scanf("%d", &min);

        printf("Inserisci il numero max: ");
        fflush(stdin);
        scanf("%d", &max);
        if (min <= 0 || min > max) {
            printf("Intervallo non valido. Riprova.\n");
        }
    } while (min <= 0 || min > max);

    do {
        printf("Inserisci il numero magico: ");
        fflush(stdin);
        scanf("%d", &numeroMagico);
        if (min > numeroMagico || max < numeroMagico)
        {
            printf("Numero magico non valido.\n");
        }
    } while (min > numeroMagico || max < numeroMagico);

    printf("Inserisci il numero max di tentativi a disposizione del computer: ");
    fflush(stdin);
    scanf("%d", &maxtentativi);
    printf("\n");

    //controllo se le condizioni sono giuste
    if (min >= max || min < 0) {
        printf("Intervallo non valido.\n");
    }
    if (min > numeroMagico || max < numeroMagico) {
        printf("Numero magico non valido.\n");
    }

    //inizializzazione generatore numeri casuali
    srand(time(NULL));

    //generazione numero da indovinare
    numero = rand() % (max - min + 1) + min;

    //eseguo un ciclo for per eseguire le operazioni finchè il computer ha tentativi
    for (tentativi = 0; tentativi < maxtentativi; tentativi++)
    {
        //proposta del numero da parte del computer
        tentativo = rand() % (max - min + 1) + min;
        printf("Il computer propone: %d\n", tentativo);

        //chiedo all'utente com'è la proposta del computer
        int risposta;
        printf("Il numero da indovinare e' (1 = piu piccolo, 2 = piu grande, 3 = indovinato): ");
        fflush(stdin);
        scanf("%d", &risposta);

        //con piu condizioni vado a vedere se il computer ha indovinato il numero in base alla risposta dell'utente e controllo anche se l'utente è stato onesto o ha mentito
        if (risposta == 1)
        {
            if (numeroMagico != tentativo && numeroMagico < tentativo)
                max = tentativo - 1;
            else {
                if (numeroMagico == tentativo)
                {
                    printf("Mi hai mentito il numero generato e' corretto!!! Indovinato in %d tentativi.\n", tentativi + 1); break;
                }
                if (numeroMagico > tentativo)
                {
                    printf("Mi hai mentito il numero generato e' piu grande!!!\n"); tentativi-1;
                }
            }
        }
        else if (risposta == 2)
        {
            if (numeroMagico != tentativo && numeroMagico > tentativo)
                min = tentativo + 1;
            else {
                if (numeroMagico == tentativo)
                {
                    printf("Mi hai mentito il numero generato e' corretto!!! Indovinato in %d tentativi.\n", tentativi + 1); break;
                }
                if (numeroMagico < tentativo)
                {
                    printf("Mi hai mentito il numero generato e' piu piccolo!!!\n"); tentativi-1;
                }
            }
        }
        else if (risposta == 3) {
            if (numeroMagico == tentativo) {
                printf("Il computer ha indovinato il numero %d in %d tentativi.\n", numeroMagico, tentativi + 1);
                break;
            }
            else {
                printf("Mi hai mentito il numero generato non e' corretto!!!\n"); tentativi-1;
            }
        }
        else {
            printf("Risposta non valida. Inserisci 1, 2 o 3.\n");
        }
    };
    if (tentativi >= maxtentativi)
    {
        printf("Il computer ha esaurito il numero di temtativi e non e' riuscito ad indovinare il numero scelto dall'utente.\n");
    }

    return 0;
}
