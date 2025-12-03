#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];  
    char decrypted_string[100]; 

    printf("Inserisci una stringa: ");
    fgets(input_string, sizeof(input_string), stdin);

    int len = strlen(input_string);  //calcola lunghezza stringa

    printf("Decriptazione in corso...\n");

    //simulo il processo di decriptazione generando versioni sempre più simili
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < len; j++) {
            if (j < i) {
                decrypted_string[j] = input_string[j];
            }
            else {
                decrypted_string[j] = '*';
            }
        }
        decrypted_string[len] = '\0'; //terminatore di stringa

        //stampa la versione decriptata corrente
        printf("\r%s", decrypted_string);
        fflush(stdout);
      
        
        time_t startTime = time(NULL);
        int displayDuration = 1; //durata di visualizzazione

        while (difftime(time(NULL), startTime) < displayDuration) {
            //attendo fine del tempo
        }
        

        //aggiorna il terminatore di stringa per ripristinare la versione originale
        decrypted_string[i] = input_string[i];
    }

    return 0;
}
