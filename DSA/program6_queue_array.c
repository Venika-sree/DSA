#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull(void) {
    return rear == MAX - 1;
}

int isEmpty(void) {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
    printf("Element inserted successfully\n");
}

void dequeue(void) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front++]);

    if (front > rear) {
        front = rear = -1;
    }
}

void peek(void) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void display(void) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}