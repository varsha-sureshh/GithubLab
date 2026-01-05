#include <stdio.h>

void firstFit(int b[], int p[], int nb, int np){
    printf("\n--- First Fit ---\n");
    for(int i=0;i<np;i++){
        int flag = 0;
        for(int j=0;j<nb;j++){
            if(b[j] >= p[i]){
                printf("Process %d allocated to Block %d\n", i, j);
                b[j] -= p[i];
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("Process %d NOT allocated\n", i);
    }
}

void bestFit(int b[], int p[], int nb, int np){
    printf("\n--- Best Fit ---\n");
    for(int i=0;i<np;i++){
        int best = -1;
        for(int j=0;j<nb;j++){
            if(b[j] >= p[i] && (best == -1 || b[j] < b[best]))
                best = j;
        }
        if(best != -1){
            printf("Process %d allocated to Block %d\n", i, best);
            b[best] -= p[i];
        } else {
            printf("Process %d NOT allocated\n", i);
        }
    }
}

void worstFit(int b[], int p[], int nb, int np){
    printf("\n--- Worst Fit ---\n");
    for(int i=0;i<np;i++){
        int worst = -1;
        for(int j=0;j<nb;j++){
            if(b[j] >= p[i] && (worst == -1 || b[j] > b[worst]))
                worst = j;
        }
        if(worst != -1){
            printf("Process %d allocated to Block %d\n", i, worst);
            b[worst] -= p[i];
        } else {
            printf("Process %d NOT allocated\n", i);
        }
    }
}

int main(){
    int nb, np;
    int block[10], process[10];
    int b1[10], b2[10], b3[10];

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for(int i=0;i<nb;i++){
        scanf("%d", &block[i]);
        b1[i] = b2[i] = b3[i] = block[i]; // copy blocks
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for(int i=0;i<np;i++)
        scanf("%d", &process[i]);

    //firstFit(b1, process, nb, np);
    //bestFit(b2, process, nb, np);
    worstFit(b3, process, nb, np);

    return 0;
}