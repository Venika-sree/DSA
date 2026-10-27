#include <stdio.h>
#define MAX 5

struct Element {
    int data;
    int priority;
};

struct Element pq[MAX];
int size = 0;

void insert(int data, int priority) {
    if (size == MAX) {
        printf("Priority queue is full\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && pq[i].priority > priority) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    size++;

    printf("Element inserted successfully\n");
}

void deleteHighestPriority(void) {
    if (size == 0) {
        printf("Priority queue is empty\n");
        return;
    }

    printf("Deleted element: %d (Priority: %d)\n",
           pq[0].data, pq[0].priority);

    for (int i = 0; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

void display(void) {
    if (size == 0) {
        printf("Priority queue is empty\n");
        return;
    }

    printf("Data\tPriority\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
}

int main(void) {
    int choice, data, priority;

    while (1) {
        printf("\n1. Insert\n2. Delete highest priority");
        printf("\n3. Display\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                insert(data, priority);
                break;
            case 2:
                deleteHighestPriority();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}