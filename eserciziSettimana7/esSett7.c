#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 9578
#define MAX_COLS 10
#define K 5 // Sostituisci con il valore desiderato di K

// Definizione della struttura DistanceLabel
struct DistanceLabel {
    double distance;
    int label;
};

struct Persona {
    char campo1[10]; //soddisfazione criterio credito 1 o 0(1)
    char campo2[10]; //tasso interesse(2)
    char campo3[10]; //punteggio credito fico(6)
    char campo4[10]; //se il prestito è stato pagato 1 o 0(13)
    char classe[10];
};

//funzione di confronto
int compareDistances(const void* a, const void* b) {
    double distance_a = ((struct DistanceLabel*)a)->distance;
    double distance_b = ((struct DistanceLabel*)b)->distance;

    if (distance_a < distance_b) {
        return -1;
    }
    else if (distance_a > distance_b) {
        return 1;
    }
    else {
        return 0;
    }
}

double calculateDistance(struct Persona p1, struct Persona p2) {
    double dist = atof(p1.campo2) - atof(p2.campo2);
    return fabs(dist);
}

int predictClass(struct Persona testPersona, struct Persona trainingSet[], int k, int rowCount) {
    struct DistanceLabel distances[MAX_ROWS];

    //calcola la distanza tra il punto di test e tutti i punti dell'insieme di training
    for (int i = 0; i < rowCount; i++) {
        distances[i].distance = calculateDistance(testPersona, trainingSet[i]);
        distances[i].label = atoi(trainingSet[i].classe);
    }

    //ordina la struttura dati in base alle distanze utilizzando la funzione di confronto
    qsort(distances, rowCount, sizeof(struct DistanceLabel), compareDistances);

    //seleziona i primi K elementi
    int classCounts[MAX_ROWS] = { 0 };
    for (int i = 0; i < k; i++) {
        classCounts[distances[i].label]++;
    }


    int maxCount = 0;
    int predictedClass = -1;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (classCounts[i] > maxCount) {
            maxCount = classCounts[i];
            predictedClass = i;
        }
    }

    return predictedClass;
}

int main() {
    FILE* file;
    char buffer[10048];
    struct Persona persona[MAX_ROWS];
    int rowCount = 0;

    file = fopen("loan_dataWIN.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Impossibile aprire il file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) && rowCount < MAX_ROWS) {
        char* token = strtok(buffer, ",");
        strncpy(persona[rowCount].campo1, token, sizeof(persona[rowCount].campo1) - 1);
        persona[rowCount].campo1[sizeof(persona[rowCount].campo1) - 1] = '\0';

        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        strncpy(persona[rowCount].classe, token, sizeof(persona[rowCount].classe) - 1);
        persona[rowCount].classe[sizeof(persona[rowCount].classe) - 1] = '\0';

        rowCount++;
    }

    fclose(file);

    int trainingRowCount = rowCount * 0.75;
    int testRowCount = rowCount - trainingRowCount;



    //valuta l'accuratezza per il 25% dei dati
    int correctPredictions = 0;
    for (int i = trainingRowCount; i < rowCount; i++) {
        int predictedClass = predictClass(persona[i], persona, K, trainingRowCount);
        if (predictedClass == atoi(persona[i].classe)) {
            correctPredictions++;
        }
    }
    printf("Attendere il calcolo...\n");
    //calcola e stampa l'accuratezza
    double accuracy = (double)correctPredictions / testRowCount;
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}
