#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

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
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

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

    if (head->data == value)
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("Node deleted successfully.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    deleteNode = temp->next;

    temp->next = deleteNode->next;
    free(deleteNode);

    printf("Node deleted successfully.\n");
}

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

    while (temp != NULL && temp->data != oldValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &newValue);

    temp->data = newValue;

    printf("Node modified successfully.\n");
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
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
