#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTR_LEN 20
#define MAX_VAL_LEN 10
#define MAX_HYPOTHESES 100

typedef struct {
    char alternative[MAX_VAL_LEN];
    char bar[MAX_VAL_LEN];
    char day[MAX_VAL_LEN];
    char hunger[MAX_VAL_LEN];
    char crowded[MAX_VAL_LEN];
    char price[MAX_VAL_LEN];
    char rain[MAX_VAL_LEN];
    char reservation[MAX_VAL_LEN];
    char type[MAX_VAL_LEN];
    char wait[MAX_VAL_LEN];
    char result[MAX_VAL_LEN];
    char attribute[MAX_ATTR_LEN];
    char value[MAX_VAL_LEN];
} Hypothesis;

typedef struct {
    char attribute[MAX_ATTR_LEN];
    char value[MAX_VAL_LEN];
} AttributeValuePair;

int loadTrainingSet(char* filename, Hypothesis hypotheses[]);
void trainFindS(Hypothesis hypotheses[], int numHypotheses);
void testFindS(Hypothesis hypotheses[], int numHypotheses);

int main() {
    char choice;
    printf("Vuoi inserire i dati manualmente? (s/n): ");
    scanf(" %c", &choice);

    Hypothesis hypotheses[MAX_HYPOTHESES];
    int numHypotheses;

    if (choice == 's' || choice == 'S') {
        //input manuale
        printf("Inserisci il numero di ipotesi di allenamento: ");
        scanf("%d", &numHypotheses);

        printf("Inserisci le ipotesi di allenamento nel formato specificato:\n");
        //printf("I campi in ordine sono : alterative, bar, giorno, affamati, affollato, prezzo, pioggia, prenotato, tipo rist., attesa, result\n");
        for (int i = 0; i < numHypotheses; i++) {
            printf("Ipotesi %d:\n", i + 1);
            printf("Alternative, c'e' un ristorante nei paraggi (vero, falso): "); scanf("%s", hypotheses[i].alternative);
            printf("Bar, il ristorante ha un'area bar per l'attesa (vero, falso): "); scanf("%s", hypotheses[i].bar);
            printf("Giorno, giorno della settimana in cui si vuole andare al ristorante (vero se venerdi o sabato, falso diversamente): "); scanf("%s", hypotheses[i].day);
            printf("Fame, siamo affamati (vero, falso): "); scanf("%s", hypotheses[i].hunger);
            printf("Affollato, quante persone sono presenti nel ristorante (nessuno, qualcuno, pieno): "); scanf("%s", hypotheses[i].crowded);
            printf("Prezzo, categoria di costo del ristorante ($, $$, $$$): "); scanf("%s", hypotheses[i].price);
            printf("Pioggia, fuori sta piovendo (vero, falso): "); scanf("%s", hypotheses[i].rain);
            printf("Prenotazione, abbiamo prenotato (vero, falso): "); scanf("%s", hypotheses[i].reservation);
            printf("Tipo, tipo di ristorante (italiano, francese, fast-food, thai): "); scanf("%s", hypotheses[i].type);
            printf("Attesa stimata, stima del tempo di attesa (<10, 10-29, 30-60, >60): "); scanf("%s", hypotheses[i].wait);
            printf("Risultato, indicare se positivo o negativo: "); scanf("%s", hypotheses[i].result);
            /*scanf("%s %s %s %s %s %s %s %s %s %s %s",
                hypotheses[i].alternative,
                hypotheses[i].bar,
                hypotheses[i].day,
                hypotheses[i].hunger,
                hypotheses[i].crowded,
                hypotheses[i].price,
                hypotheses[i].rain,
                hypotheses[i].reservation,
                hypotheses[i].type,
                hypotheses[i].wait,
                hypotheses[i].result);*/
        }
    }
    else {
        //input da file
        char filename[100];
        printf("Inserisci il nome del file di addestramento: ");
        scanf("%s", filename);

        numHypotheses = loadTrainingSet(filename, hypotheses);
        if (numHypotheses <= 0) {
            printf("Errore nel caricamento del file di addestramento.\n");
            return 1;
        }
    }

    trainFindS(hypotheses, numHypotheses);
    testFindS(hypotheses, numHypotheses);

    return 0;
}

int loadTrainingSet(char* filename, Hypothesis hypotheses[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Errore nell'apertura del file: %s\n", filename);
        return -1;
    }

    int numHypotheses = 0;
    while (fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s",
        hypotheses[numHypotheses].alternative,
        hypotheses[numHypotheses].bar,
        hypotheses[numHypotheses].day,
        hypotheses[numHypotheses].hunger,
        hypotheses[numHypotheses].crowded,
        hypotheses[numHypotheses].price,
        hypotheses[numHypotheses].rain,
        hypotheses[numHypotheses].reservation,
        hypotheses[numHypotheses].type,
        hypotheses[numHypotheses].wait,
        hypotheses[numHypotheses].result) == 11) {
        numHypotheses++;
        if (numHypotheses >= MAX_HYPOTHESES) {
            printf("Attenzione: Numero massimo di ipotesi raggiunto (%d).\n", MAX_HYPOTHESES);
            break;
        }
    }

    fclose(file);
    return numHypotheses;
}

void trainFindS(Hypothesis hypotheses[], int numHypotheses) {
    Hypothesis findS = hypotheses[0];

    for (int i = 1; i < numHypotheses; i++) {
        if (strcmp(hypotheses[i].result, "true") == 0) {
            for (int j = 0; j < sizeof(Hypothesis) / sizeof(AttributeValuePair); j++) {
                if (strcmp(findS.result, "true") == 0) {
                    if (strcmp(hypotheses[i].attribute, findS.attribute) != 0 ||
                        strcmp(hypotheses[i].value, findS.value) != 0) {
                        strcpy(findS.attribute, "?");
                        strcpy(findS.value, "?");
                        strcpy(findS.result, "true");
                    }
                }
            }
        }
    }

    printf("\n\nIpotesi appresa:\n");
    printf("Alternativa: %s\n", findS.alternative);
    printf("Bar: %s\n", findS.bar);
    printf("Giorno: %s\n", findS.day);
    printf("Affamati: %s\n", findS.hunger);
    printf("Affollato: %s\n", findS.crowded);
    printf("Prezzo: %s\n", findS.price);
    printf("Pioggia: %s\n", findS.rain);
    printf("Prenotato: %s\n", findS.reservation);
    printf("Tipo ristorante: %s\n", findS.type);
    printf("Attesa: %s\n", findS.wait);
    printf("Result: %s\n", findS.result);

    printf("\n");
}


void testFindS(Hypothesis hypotheses[], int numHypotheses) {
    char input[MAX_ATTR_LEN];
    printf("\nTestiamo il modello:\n");

    while (1) {
        printf("Scrivere tutti gli attrubuti richiesti per testare il programma(una volta finito digitare 'exit'): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        AttributeValuePair userInput[MAX_ATTR_LEN];
        int i = 0;
        while (strcmp(input, "exit") != 0) {
            strcpy(userInput[i].attribute, input);
            scanf("%s", userInput[i].value);
            i++;
            scanf("%s", input);
        }

        
        int prediction = 1; 

        
        printf("Risultato prediction: %s\n", prediction ? "vero" : "falso");

        //chiediamo all'utente se � coretta la prediction
        char userResponse[MAX_VAL_LEN];
        printf("E'corretta? (si/no): ");
        scanf("%s", userResponse);

        if (strcmp(userResponse, "si") == 0) {
            // Prediction corretta
            printf("La prediction � corretta!\n");
        }
        else if (strcmp(userResponse, "no") == 0) {
            // Prediction sbagliata, aggiorno
            if (numHypotheses < MAX_HYPOTHESES) {
                //salvo esempio errato
                strcpy(hypotheses[numHypotheses].attribute, "?");
                strcpy(hypotheses[numHypotheses].value, "?");
                strcpy(hypotheses[numHypotheses].result, "false");

                numHypotheses++;

                trainFindS(hypotheses, numHypotheses);

                printf("Modello aggiornato!\n");
            }
            else {
                printf("Limite massimo per le ipotesi.\n");
            }
        }
        else {
            printf("Risposta non valida. Digita 'si' o 'no'.\n");
        }
    }
}

