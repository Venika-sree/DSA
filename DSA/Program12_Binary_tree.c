#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main(void) {
    struct Node *root = NULL;
    struct Node *result;
    int choice, key;

    int elements[] = {
        13, 3, 4, 12, 14, 10, 5, 1,
        8, 2, 7, 9, 11, 6, 18
    };

    int n = sizeof(elements) / sizeof(elements[0]);

    while (1) {
        printf("\n----- BINARY SEARCH TREE -----");
        printf("\n1. Create BST");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = NULL;

                for (int i = 0; i < n; i++)
                    root = insert(root, elements[i]);

                printf("BST created successfully.\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("Please create the BST first.\n");
                } else {
                    printf("Enter the element to search: ");
                    scanf("%d", &key);

                    result = search(root, key);

                    if (result != NULL)
                        printf("KEY %d is found in the BST.\n", key);
                    else
                        printf("KEY %d is not found in the BST.\n", key);
                }
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}