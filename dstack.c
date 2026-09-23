#include<stdio.h>

void push(int stack[], int *top1, int *top2, int n)
{
    int option, value;

    printf("\n1. Stack 1");
    printf("\n2. Stack 2");
    printf("\nEnter Stack : ");
    scanf("%d",&option);

    if(*top1 + 1 == *top2)
    {
        printf("\nStack Overflow");
        return;
    }

    printf("Enter value : ");
    scanf("%d",&value);

    if(option == 1)
    {
        *top1 = *top1 + 1;
        stack[*top1] = value;
    }
    else if(option == 2)
    {
        *top2 = *top2 - 1;
        stack[*top2] = value;
    }
    else
    {
        printf("\nInvalid Stack");
        return;
    }

    printf("\nValue inserted successfully");
}


void pop(int stack[], int *top1, int *top2, int n)
{
    int option;

    printf("\n1. Stack 1");
    printf("\n2. Stack 2");
    printf("\nEnter Stack : ");
    scanf("%d",&option);

    if(option == 1)
    {
        if(*top1 == -1)
        {
            printf("\nStack 1 Underflow");
        }
        else
        {
            printf("\nDeleted value = %d",stack[*top1]);
            *top1 = *top1 - 1;
        }
    }

    else if(option == 2)
    {
        if(*top2 == n)
        {
            printf("\nStack 2 Underflow");
        }
        else
        {
            printf("\nDeleted value = %d",stack[*top2]);
            *top2 = *top2 + 1;
        }
    }

    else
    {
        printf("\nInvalid Stack");
    }
}


void peep(int stack[], int top1, int top2, int n)
{
    int option;

    printf("\n1. Stack 1");
    printf("\n2. Stack 2");
    printf("\nEnter Stack : ");
    scanf("%d",&option);

    if(option == 1)
    {
        if(top1 == -1)
            printf("\nStack 1 is Empty");
        else
            printf("\nTop value = %d",stack[top1]);
    }

    else if(option == 2)
    {
        if(top2 == n)
            printf("\nStack 2 is Empty");
        else
            printf("\nTop value = %d",stack[top2]);
    }

    else
    {
        printf("\nInvalid Stack");
    }
}


void modify(int stack[], int top1, int top2, int n)
{
    int option, pos, value;

    printf("\n1. Stack 1");
    printf("\n2. Stack 2");
    printf("\nEnter Stack : ");
    scanf("%d",&option);

    printf("Enter position : ");
    scanf("%d",&pos);

    printf("Enter new value : ");
    scanf("%d",&value);

    if(option == 1)
    {
        if(pos < 0 || pos > top1)
        {
            printf("\nInvalid Position");
        }
        else
        {
            stack[pos] = value;
            printf("\nValue modified successfully");
        }
    }

    else if(option == 2)
    {
        if(pos < top2 || pos >= n)
        {
            printf("\nInvalid Position");
        }
        else
        {
            stack[pos] = value;
            printf("\nValue modified successfully");
        }
    }

    else
    {
        printf("\nInvalid Stack");
    }
}


void display(int stack[], int top1, int top2, int n)
{
    int option, i;

    printf("\n1. Stack 1");
    printf("\n2. Stack 2");
    printf("\nEnter Stack : ");
    scanf("%d",&option);

    if(option == 1)
    {
        if(top1 == -1)
        {
            printf("\nStack 1 is Empty");
        }
        else
        {
            printf("\nStack 1 : ");

            for(i=top1; i>=0; i--)
                printf("%d ",stack[i]);
        }
    }

    else if(option == 2)
    {
        if(top2 == n)
        {
            printf("\nStack 2 is Empty");
        }
        else
        {
            printf("\nStack 2 : ");

            for(i=top2; i<n; i++)
                printf("%d ",stack[i]);
        }
    }

    else
    {
        printf("\nInvalid Stack");
    }
}


int main()
{
    int n;
    int stack[100];
    int top1 = -1;
    int top2;
    int choice;

    printf("Enter size of array : ");
    scanf("%d",&n);

    top2 = n;

    do
    {
        printf("\n\n--- DOUBLE STACK ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peep");
        printf("\n4. Modify");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                push(stack,&top1,&top2,n);
                break;

            case 2:
                pop(stack,&top1,&top2,n);
                break;

            case 3:
                peep(stack,top1,top2,n);
                break;

            case 4:
                modify(stack,top1,top2,n);
                break;

            case 5:
                display(stack,top1,top2,n);
                break;

            case 6:
                printf("\nProgram terminated");
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(choice != 6);

    return 0;
}