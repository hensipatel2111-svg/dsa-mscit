#include<stdio.h>

int main()
{
    int PQ[2][5];
    int n = 5;
    int front = 0, rear = 4;
    int i;
    int time;
    int completed = 0;

    printf("Enter burst time of 5 processes:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d : ", i + 1);

        PQ[0][i] = i + 1;       // Process number
        scanf("%d",&PQ[1][i]);  // Burst time
    }

    printf("\nProcess Execution:\n");

    while(completed < n)
    {
        if(PQ[1][front] > 0)
        {
            printf("P%d is executing\n",PQ[0][front]);

            if(PQ[1][front] <= 2)
            {
                time = PQ[1][front];
                PQ[1][front] = 0;

                printf("P%d completed\n",PQ[0][front]);

                completed++;
            }
            else
            {
                PQ[1][front] = PQ[1][front] - 2;
            }
        }

        front = (front + 1) % n;
    }

    return 0;
}