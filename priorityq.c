```c
#include<stdio.h>

int main()
{
    int Q1[5], Q2[5], Q3[5];

    int F1 = -1, R1 = -1;
    int F2 = -1, R2 = -1;
    int F3 = -1, R3 = -1;

    int option, value, priority;

    do
    {
        printf("\n\n----- PRIORITY QUEUE -----");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");

        printf("\nEnter Choice : ");
        scanf("%d",&option);

        /* Insert */
        if(option == 1)
        {
            printf("\nEnter Value : ");
            scanf("%d",&value);

            printf("Enter Priority (1/2/3) : ");
            scanf("%d",&priority);

            if(priority == 1)
            {
                if(R1 == 4)
                {
                    printf("\nQueue Overflow");
                }
                else
                {
                    R1++;
                    Q1[R1] = value;

                    if(F1 == -1)
                        F1 = 0;

                    printf("\nValue Inserted in Q1");
                }
            }

            else if(priority == 2)
            {
                if(R2 == 4)
                {
                    printf("\nQueue Overflow");
                }
                else
                {
                    R2++;
                    Q2[R2] = value;

                    if(F2 == -1)
                        F2 = 0;

                    printf("\nValue Inserted in Q2");
                }
            }

            else if(priority == 3)
            {
                if(R3 == 4)
                {
                    printf("\nQueue Overflow");
                }
                else
                {
                    R3++;
                    Q3[R3] = value;

                    if(F3 == -1)
                        F3 = 0;

                    printf("\nValue Inserted in Q3");
                }
            }

            else
            {
                printf("\nInvalid Priority");
            }
        }


        /* Delete */
        else if(option == 2)
        {
            if(F1 != -1)
            {
                printf("\nDeleted = %d", Q1[F1]);

                if(F1 == R1)
                {
                    F1 = -1;
                    R1 = -1;
                }
                else
                {
                    F1++;
                }
            }

            else if(F2 != -1)
            {
                printf("\nDeleted = %d", Q2[F2]);

                if(F2 == R2)
                {
                    F2 = -1;
                    R2 = -1;
                }
                else
                {
                    F2++;
                }
            }

            else if(F3 != -1)
            {
                printf("\nDeleted = %d", Q3[F3]);

                if(F3 == R3)
                {
                    F3 = -1;
                    R3 = -1;
                }
                else
                {
                    F3++;
                }
            }

            else
            {
                printf("\nQueue Underflow");
            }
        }


        /* Exit */
        else if(option == 3)
        {
            printf("\nExit");
        }

        else
        {
            printf("\n Invalid Choice");
        }

    } while(option != 3);

    return 0;
}

