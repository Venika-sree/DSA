#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}
void deleteByValue(struct Node **head, int value)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

 
    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }

  prev->next = temp->next;
    free(temp);
}
void display(struct Node *head)
{
    struct Node *temp = head;

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
    struct Node *head, *second, *third, *fourth;
    int value;

    head = createNode(10);
    second = createNode(20);
    third = createNode(30);
    fourth = createNode(40);
    head->next = second;
    second->next = third;
    third->next = fourth;

    printf("Before Deletion:\n");
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &value);

    deleteByValue(&head, value);

    printf("\nAfter Deletion:\n");
    display(head);

    return 0;
}