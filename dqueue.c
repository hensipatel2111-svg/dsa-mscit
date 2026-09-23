```c
#include<stdio.h>

void insert(int Q[], int n, int *F1, int *R1, int *F2, int *R2)
{
    int no, option;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d",&option);

    printf("Enter Number : ");
    scanf("%d",&no);

    if(*R1 + 1 == *R2)
    {
        printf("\nQueue Overflow");
        return;
    }

    if(option == 1)
    {
        *R1 = *R1 + 1;
        Q[*R1] = no;

        if(*F1 == 0)
            *F1 = 1;
    }
    else if(option == 2)
    {
        *R2 = *R2 - 1;
        Q[*R2] = no;

        if(*F2 == n + 1)
            *F2 = n;
    }
    else
    {
        printf("\nInvalid Queue");
    }
}


void deleteq(int Q[], int n, int *F1, int *R1, int *F2, int *R2)
{
    int option;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d",&option);

    if(option == 1)
    {
        if(*F1 == 0)
        {
            printf("\nQueue Underflow");
            return;
        }

        printf("\nDeleted = %d",Q[*F1]);

        if(*F1 == *R1)
        {
            *F1 = 0;
            *R1 = 0;
        }
        else
        {
            *F1 = *F1 + 1;
        }
    }

    else if(option == 2)
    {
        if(*F2 == n + 1)
        {
            printf("\nQueue Underflow");
            return;
        }

        printf("\nDeleted = %d",Q[*F2]);

        if(*F2 == *R2)
        {
            *F2 = n + 1;
            *R2 = n + 1;
        }
        else
        {
            *F2 = *F2 - 1;
        }
    }

    else
    {
        printf("\nInvalid Queue");
    }
}


void modify(int Q[], int n, int F1, int R1, int F2, int R2)
{
    int option, pos, no;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d",&option);

    if(option == 1)
    {
        if(F1 == 0)
        {
            printf("\nQueue Empty");
            return;
        }

        printf("Enter Position : ");
        scanf("%d",&pos);

        if(pos < F1 || pos > R1)
        {
            printf("\nInvalid Position");
            return;
        }

        printf("Enter New Number : ");
        scanf("%d",&no);

        Q[pos] = no;

        printf("\nValue Modified Successfully");
    }

    else if(option == 2)
    {
        if(F2 == n + 1)
        {
            printf("\nQueue Empty");
            return;
        }

        printf("Enter Position : ");
        scanf("%d",&pos);

        if(pos > F2 || pos < R2)
        {
            printf("\nInvalid Position");
            return;
        }

        printf("Enter New Number : ");
        scanf("%d",&no);

        Q[pos] = no;

        printf("\nValue Modified Successfully");
    }

    else
    {
        printf("\nInvalid Queue");
    }
}


void display(int Q[], int n, int F1, int R1, int F2, int R2)
{
    int option;
    int i;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d",&option);

    if(option == 1)
    {
        if(F1 == 0)
        {
            printf("\nQueue Empty");
            return;
        }

        printf("\nFirst Queue : ");

        for(i = F1; i <= R1; i++)
        {
            printf("%d ",Q[i]);
        }
    }

    else if(option == 2)
    {
        if(F2 == n + 1)
        {
            printf("\nQueue Empty");
            return;
        }

        printf("\nSecond Queue : ");

        for(i = F2; i >= R2; i--)
        {
            printf("%d ",Q[i]);
        }
    }

    else
    {
        printf("\nInvalid Queue");
    }
}


int main()
{
    int n;
    int F1 = 0, R1 = 0;
    int F2, R2;
    int ch;

    printf("Enter Size of Array : ");
    scanf("%d",&n);

    int Q[n];

    F2 = n + 1;
    R2 = n + 1;

    do
    {
        printf("\n\n----- DOUBLE QUEUE -----");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Modify");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                insert(Q,n,&F1,&R1,&F2,&R2);
                break;

            case 2:
                deleteq(Q,n,&F1,&R1,&F2,&R2);
                break;

            case 3:
                modify(Q,n,F1,R1,F2,R2);
                break;

            case 4:
                display(Q,n,F1,R1,F2,R2);
                break;

            case 5:
                printf("\nExit");
                break;

            default:
                printf("\nInvalid Choice");
        }

    }while(ch != 5);

    return 0;
}

