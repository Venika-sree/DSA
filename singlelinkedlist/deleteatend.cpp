#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void deleteAtFront(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}


void display(struct Node *head)
{
    struct Node *temp = head;

    printf(" Before Linked List: ");
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
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40; 
	head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

   
    display(head);

    deleteAtFront(&head);

    display(head);

    return 0;
}