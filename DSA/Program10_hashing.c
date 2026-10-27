#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int linearTable[TABLE_SIZE];
int quadraticTable[TABLE_SIZE];

struct Node {
    int key;
    struct Node *next;
};

struct Node *chainTable[TABLE_SIZE];

int hashFunction(int key) {
    return ((key % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
}

void initTables(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        linearTable[i] = -1;
        quadraticTable[i] = -1;
        chainTable[i] = NULL;
    }
}

void insertLinear(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i) % TABLE_SIZE;

        if (linearTable[probe] == -1) {
            linearTable[probe] = key;
            printf("Inserted at index %d (linear probing).\n", probe);
            return;
        }
    }

    printf("Linear probing table is full.\n");
}

void insertQuadratic(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i * i) % TABLE_SIZE;

        if (quadraticTable[probe] == -1) {
            quadraticTable[probe] = key;
            printf("Inserted at index %d (quadratic probing).\n", probe);
            return;
        }
    }

    printf("No free slot found using quadratic probing.\n");
}

void insertChaining(int key) {
    int index = hashFunction(key);

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->key = key;
    newNode->next = NULL;

    if (chainTable[index] == NULL) {
        chainTable[index] = newNode;
    } else {
        struct Node *temp = chainTable[index];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted at index %d (separate chaining).\n", index);
}

void displayLinear(void) {
    printf("\nLinear Probing Table:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (linearTable[i] == -1)
            printf("%d: -\n", i);
        else
            printf("%d: %d\n", i, linearTable[i]);
    }
}

void displayQuadratic(void) {
    printf("\nQuadratic Probing Table:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (quadraticTable[i] == -1)
            printf("%d: -\n", i);
        else
            printf("%d: %d\n", i, quadraticTable[i]);
    }
}

void displayChaining(void) {
    printf("\nSeparate Chaining Table:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *temp = chainTable[i];

        printf("%d: ", i);

        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main(void) {
    int choice, key;

    initTables();

    while (1) {
        printf("\n1. Insert using Linear Probing");
        printf("\n2. Insert using Quadratic Probing");
        printf("\n3. Insert using Separate Chaining");
        printf("\n4. Display Linear Probing");
        printf("\n5. Display Quadratic Probing");
        printf("\n6. Display Separate Chaining");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insertLinear(key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                insertQuadratic(key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                insertChaining(key);
                break;
            case 4:
                displayLinear();
                break;
            case 5:
                displayQuadratic();
                break;
            case 6:
                displayChaining();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}