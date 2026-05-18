#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int value;
    struct NODE *next;
};

// Function prototypes
void insertBeginning(struct NODE **head, int val);
void insert_End(struct NODE **head, int val);
void insert_after(struct NODE *head, int val, int x);
void deleteNode(struct NODE **head, int key);
void printLinkedList(struct NODE *head);

void main()
{
    struct NODE *head = NULL;
    int choice;
    int val;
    int x;
    do
    {
        printf("Press 1. Insert at Beginning\n");
        printf("Press 2. Insert at End\n");
        printf("Press 3. Insert After Value\n");
        printf("Press 4. Delete Node\n");
        printf("Press 5. Display List\n");
        printf("Press 6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insertBeginning(&head, val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insert_End(&head, val);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Insert after which value?: ");
            scanf("%d", &x);
            insert_after(head, val, x);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            deleteNode(&head, val);
            break;
        case 5:
            printLinkedList(head);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);
    
} //end of main

void printLinkedList(struct NODE *head)
{
    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("Linked list: ");
    while (head != NULL)
    {
        printf("%d", head->value);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
}// end of printLinkedList

void insertBeginning(struct NODE **head, int val)
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode->value = val;
    newNode->next = *head;
    *head = newNode;
} // end of insertBeginning

void insert_End(struct NODE **head, int val)
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode->value = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct NODE *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
} // end of insert_end

void insert_after(struct NODE *head, int val, int x)
{
    struct NODE *temp = head;
    while (temp != NULL && temp->value != x)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value %d not found!\n", x);
        return;
    }
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode->value = val;
    newNode->next = temp->next;
    temp->next = newNode;
} // end of insert_after

void deleteNode(struct NODE **head, int key)
{
    struct NODE *temp = *head;
    struct NODE *prev = NULL;
    if (temp == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    // delete head
    if (temp->value == key)
    {
        *head = temp->next;
        free(temp);
        printf("%d deleted\n", key);
        return;
    }
    while (temp != NULL && temp->value != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value %d not found!\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted\n", key);
} // end of delete