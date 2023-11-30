#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int Height(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaf(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeaf(root->left) + countLeaf(root->right);
}

int Minimum(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

int Maximum(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

void printLeaf(struct Node* root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }

    printLeaf(root->left);
    printLeaf(root->right);
}

void LevelWise(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        LevelWise(root->left, level - 1);
        LevelWise(root->right, level - 1);
    }
}

void LevelOrder(struct Node* root) {
    int height = Height(root),i;
    for (i = 1; i <= height + 1; i++) {
        LevelWise(root, i);
        printf("\n");
    }
}

void mirrorImage(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorImage(root->left);
    mirrorImage(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("1. Insert element\n");
        printf("2. Find height\n");
        printf("3. Count nodes\n");
        printf("4. Count leaf nodes\n");
        printf("5. Find minimum\n");
        printf("6. Find maximum\n");
        printf("7. Print leaf nodes\n");
        printf("8. Print nodes at each level\n");
        printf("9. Print Mirror image of the tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Height of the tree is: %d\n", Height(root));
                break;

            case 3:
                printf("Total number of nodes in the tree is: %d\n", countNodes(root));
                break;

            case 4:
                printf("Total number of leaf nodes in the tree is: %d\n", countLeaf(root));
                break;

            case 5:
                printf("Minimum value in the tree is: %d\n", Minimum(root));
                break;

            case 6:
                printf("Maximum value in the tree is: %d\n", Maximum(root));
                break;

            case 7:
                printf("Leaf nodes: ");
                printLeaf(root);
                printf("\n");
                break;

            case 8:
                printf("Nodes level wise:\n");
                LevelOrder(root);
                break;

            case 9:
                mirrorImage(root);
                LevelOrder(root);

                printf("Mirror image of the tree created.\n");
                break;

            case 0:
                printf("Exit\n");
                break;

            default:
                printf("wrong choice\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
