#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert */
void insert()
{
    int value;
    struct Node *newNode;
    struct Node *temp;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted successfully.\n");
}

/* Delete */
void deleteNode()
{
    int value;
    struct Node *temp;
    struct Node *deleteNode;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    /* Delete first node */
    if (head->data == value)
    {
        /* Only one node */
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            deleteNode = head;
            head = head->next;
            temp->next = head;

            free(deleteNode);
        }

        printf("Node deleted successfully.\n");
        return;
    }

    temp = head;

    while (temp->next != head &&
           temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == head)
    {
        printf("Node not found.\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Node deleted successfully.\n");
}

/* Modify */
void modify()
{
    int oldValue, newValue;
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to modify: ");
    scanf("%d", &oldValue);

    temp = head;

    do
    {
        if (temp->data == oldValue)
        {
            printf("Enter new value: ");
            scanf("%d", &newValue);

            temp->data = newValue;

            printf("Node modified successfully.\n");
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Node not found.\n");
}

/* Display */
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while (temp != head);

    printf("HEAD\n");
}

/* Main */
int main()
{
    int choice;

    do
    {
        printf("\n===== SINGLY CIRCULAR LINKED LIST =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
