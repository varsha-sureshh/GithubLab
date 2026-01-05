#include <stdio.h>

void calc(int n, int bt[]) {
    int wt[10]={0}, tat[10], tw=0, tt=0;

    for(int i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        tw += wt[i];  tt += tat[i];
        printf("P%d  BT=%d WT=%d TAT=%d\n",i+1,bt[i],wt[i],tat[i]);
    }

    printf("Avg WT = %.2f\n",(float)tw/n);
    printf("Avg TAT = %.2f\n",(float)tt/n);
}

/* ---------- FCFS ---------- */
void fcfs(int n, int bt[]){
    calc(n,bt);
}

/* ---------- SJF ---------- */
void sjf(int n, int bt[]){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(bt[i] > bt[j]){
                int t=bt[i]; bt[i]=bt[j]; bt[j]=t;
            }
    calc(n,bt);
}

/* ---------- PRIORITY ---------- */
void priority(int n, int bt[], int pr[]){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(pr[i] > pr[j]){
                int t=pr[i]; pr[i]=pr[j]; pr[j]=t;
                t=bt[i]; bt[i]=bt[j]; bt[j]=t;
            }
    calc(n,bt);
}

/* ---------- ROUND ROBIN ---------- */
void rr(int n, int bt[], int q){
    int rem[10], wt[10]={0}, t=0;

    for(int i=0;i<n;i++) rem[i]=bt[i];

    while(1){
        int done=1;
        for(int i=0;i<n;i++){
            if(rem[i]>0){
                done=0;
                if(rem[i]>q){ t+=q; rem[i]-=q; }
                else{ t+=rem[i]; wt[i]=t-bt[i]; rem[i]=0; }
            }
        }
        if(done) break;
    }

    for(int i=0;i<n;i++)
        printf("P%d WT=%d TAT=%d\n",i+1,wt[i],wt[i]+bt[i]);
}

/* ---------- MAIN ---------- */
int main(){
    int n, bt[10], pr[10], q;

    printf("Enter n: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("BT of P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    // Uncomment ONE at a time

     //fcfs(n,bt);
    sjf(n,bt);

    //printf("Enter priorities:\n");
    //for(int i=0;i<n;i++) scanf("%d",&pr[i]);
    //priority(n,bt,pr);

    /*printf("Enter Quantum: ");
    scanf("%d",&q);
    rr(n,bt,q);*/
}