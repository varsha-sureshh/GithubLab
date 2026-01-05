#include <stdio.h>

int n,m;
int max[10][10], alloc[10][10], need[10][10];
int avail[10], finish[10];

int main(){
    int work[10], count=0;

    printf("Enter processes & resources: ");
    scanf("%d%d",&n,&m);

    printf("Enter Available:\n");
    for(int j=0;j<m;j++) scanf("%d",&avail[j]);

    printf("Enter Max matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Allocation matrix:\n");
    for(int i=0;i<n;i++){
        finish[i]=0;
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    /* -------- DISPLAY -------- */
    printf("\nAvailable:\n");
    for(int j=0;j<m;j++) printf("%d ",avail[j]);

    printf("\n\nMax Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",max[i][j]);
        printf("\n");
    }

    printf("\nAllocation Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",alloc[i][j]);
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",need[i][j]);
        printf("\n");
    }
    /* -------------------------- */

    for(int j=0;j<m;j++) work[j]=avail[j];

    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(!finish[i]){
                int j;
                for(j=0;j<m;j++)
                    if(need[i][j]>work[j]) break;

                if(j==m){
                    for(int k=0;k<m;k++)
                        work[k]+=alloc[i][k];
                    finish[i]=1;
                    found=1;
                    count++;
                }
            }
        }
        if(!found) break;
    }

    if(count==n)
        printf("\nSystem is in SAFE state\n");
    else
        printf("\nSystem is in UNSAFE state\n");

    return 0;
}