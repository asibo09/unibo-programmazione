
///*void initializeQTable() {
//    qTable[5][6] =
//    {
      /* {0, -1, 0, -1, -1, -1},
        {-1, -100, -1, -1, -100, -1},
        {-1, -1, 0, -1, -1, 0},
        {-100, -1, -1, -100, -1, -1},
        {-1, 0, -1, -1, +100, -1},
    };*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32 // valido sia per 32 che 64 bit
#define CLEAR system("cls");
#else
#define CLEAR system("clear");
#endif

#define NR 5
#define NC 6
#define NA 4
#define Q_LENGTH NR * NC

#define MAX_TRAINING_STEP -1
#define MAX_TRAINING_EXPERIMENT 10000000

#define LEARNING_RATE 0.1
#define DISCOUNT_RATE 0.99

#define REWARD_LOOP -5
#define REWARD_BLANK 0
#define REWARD_POWER 0
#define REWARD_BOMB -100
#define REWARD_END 100

int main(int argc, const char* argv[]) {
    int i, j, first;
    int countTrainingStep = 0, countTrainingExperiment = 0;
    float eps, maxReward;
    int mappa[NR][NC] = {
        {0, -1, 0, -1, -1, -1},
        {-1, -100, -1, -1, -100, -1},
        {-1, -1, 0, -1, -1, 0},
        {-100, -1, -1, -100, -1, -1},
        {-1, 0, -1, -1, +100, -1},
    };
    float q_table[Q_LENGTH][NA];
    int moveDirection[NA][2] = {
        {-1, 0},    //in alto
        {0, 1},     //destra
        {1, 0},    //in basso
        {0, -1},    //sinistra
    };

    int start_r = 1, start_c = 0;   
    int curr_r, curr_c, action, curr_state;
    int next_r, next_c, prev_state, reward;

    srand(time(NULL));

    CLEAR;

    printf("Generazione percorso...\n\n");

    /* inizializzo Q Table */
    for (i = 0; i < Q_LENGTH; i++) {
        for (j = 0; j < NA; j++) {
            q_table[i][j] = 0;
        }
    }

    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {
            reward = REWARD_BLANK;
            switch (mappa[i][j]) {
            case 0://energia
                reward = REWARD_POWER;
                break;
            case -100://bomba
                reward = REWARD_BOMB;
                break;
            case 100://fine
                reward = REWARD_END;
                break;
            }
            mappa[i][j] = reward;
        }
    }

    eps = 100;
    prev_state = -1;
    curr_state = start_r * NC + start_c;
    curr_r = start_r;
    curr_c = start_c;
    while (countTrainingExperiment < MAX_TRAINING_EXPERIMENT) {
        countTrainingStep++;

        action = 0;
        
        int r = rand() % 100 + 1;
        if (r <= (100 - eps)) {
            first = 1;
            for (i = 0; i < NA; i++) {
                next_r = curr_r + moveDirection[i][0];
                next_c = curr_c + moveDirection[i][1];
                if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                    if (first || q_table[curr_state][i] > maxReward) {
                        maxReward = q_table[curr_state][i];
                        action = i;
                        first = 0;
                    }
                }
            }
        }
        else {
            int actionRandomCheck[] = { 0, 0, 0, 0 };
            int trovato = 0;
            while (!trovato) {
                do {
                    action = rand() % 4;
                } while (actionRandomCheck[action] == 1);
                actionRandomCheck[action] = 1;

                next_r = curr_r + moveDirection[action][0];
                next_c = curr_c + moveDirection[action][1];
                if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                    trovato = 1;
                }
            }
        }

        curr_r += moveDirection[action][0];
        curr_c += moveDirection[action][1];
        int reward = mappa[curr_r][curr_c];
        int new_state = curr_r * NC + curr_c;
        int maxFutureReward = 0;
        first = 1;
        for (i = 0; i < NA; i++) {
            next_r = curr_r + moveDirection[i][0];
            next_c = curr_c + moveDirection[i][1];
            if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                if (first || q_table[new_state][i] > maxFutureReward) {
                    maxFutureReward = q_table[new_state][i];
                    first = 0;
                }
            }
        }
        if (new_state == prev_state) {
            reward = REWARD_LOOP;//altrimenti crea dei loop finche non finisce i passi
        }
        q_table[curr_state][action] = q_table[curr_state][action] + LEARNING_RATE * (reward + DISCOUNT_RATE * maxFutureReward - q_table[curr_state][action]);

        if (mappa[curr_r][curr_c] == REWARD_BOMB || mappa[curr_r][curr_c] == REWARD_END || (MAX_TRAINING_STEP > 0 && countTrainingStep > MAX_TRAINING_STEP)) {
            if (mappa[curr_r][curr_c] == REWARD_BOMB && countTrainingExperiment > MAX_TRAINING_EXPERIMENT / 5) {
                eps -= 100.0 / MAX_TRAINING_EXPERIMENT;
            }
            countTrainingStep = 0;
            prev_state = -1;
            curr_state = start_r * NC + start_c;
            curr_r = start_r;
            curr_c = start_c;
            countTrainingExperiment++;
        }
        else {
            prev_state = curr_state;
            curr_state = new_state;
        }
    }


    printf("\n\n");
    for (i = 0; i < Q_LENGTH; i++) {
        for (j = 0; j < NA; j++) {
            printf("%3.2f ", q_table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    int move = 1, count = 1;
    int mappaSpostamento[NR][NC];
    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {
            mappaSpostamento[i][j] = 0;
        }
    }

    curr_state = start_r * NC + start_c;
    curr_r = start_r;
    curr_c = start_c;
    mappaSpostamento[curr_r][curr_c] = count;
    while (move) {
        action = 0;
        first = 1;
        for (i = 0; i < NA; i++) {
            next_r = curr_r + moveDirection[i][0];
            next_c = curr_c + moveDirection[i][1];
            if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                if (first || q_table[curr_state][i] > maxReward) {
                    maxReward = q_table[curr_state][i];
                    action = i;
                    first = 0;
                }
            }
        }

        curr_r += moveDirection[action][0];
        curr_c += moveDirection[action][1];
        count++;
        curr_state = curr_r * NC + curr_c;
        mappaSpostamento[curr_r][curr_c] = count;
        switch (mappa[curr_r][curr_c]) {
        case 100: //trovata la fine
            printf("trovata la fine del percorso!");
            move = 0;
            break;
        case -100: //find cat
            printf("trovata la bomba, sei morto!");
            move = 0;
            break;
        }
        if (count >= NR * NC) {
            printf("troppi passi!"); //troppi passi usata l'energia
            move = 0;
        }
    }

    printf("\n\n");

    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {
            printf("%3d", mappaSpostamento[i][j]); //stampo il percorso che ha fatto
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}