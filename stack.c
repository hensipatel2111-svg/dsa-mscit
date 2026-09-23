#include<stdio.h>

void push(int stack[], int *top, int n)
{
    int value;

    if(*top == n-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\nEnter value : ");
        scanf("%d",&value);

        *top = *top + 1;
        stack[*top] = value;

        printf("\nValue inserted successfully");
    }
}

void pop(int stack[], int *top)
{
    if(*top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nDeleted value = %d",stack[*top]);
        *top = *top - 1;
    }
}

void peep(int stack[], int top)
{
    if(top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nTop value = %d",stack[top]);
    }
}

void modify(int stack[], int top)
{
    int pos, value;

    if(top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nEnter position to modify : ");
        scanf("%d",&pos);

        if(pos < 0 || pos > top)
        {
            printf("\nInvalid Position");
        }
        else
        {
            printf("Enter new value : ");
            scanf("%d",&value);

            stack[pos] = value;

            printf("\nValue modified successfully");
        }
    }
}

void display(int stack[], int top)
{
    int i;

    if(top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nStack elements are : ");

        for(i=top; i>=0; i--)
        {
            printf("\n%d",stack[i]);
        }
    }
}

int main()
{
    int n, stack[100];
    int top = -1;
    int choice;

    printf("Enter size of stack : ");
    scanf("%d",&n);

    do
    {
        printf("\n\n--- STACK MENU ---");
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
                push(stack,&top,n);
                break;

            case 2:
                pop(stack,&top);
                break;

            case 3:
                peep(stack,top);
                break;

            case 4:
                modify(stack,top);
                break;

            case 5:
                display(stack,top);
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