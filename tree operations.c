#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int height(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int findMin(struct TreeNode* root) {
    if (root == NULL) {
        printf("Error: Tree is empty\n");
        return -1; 
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(struct TreeNode* root) {
    if (root == NULL) {
        printf("Error: Tree is empty\n");
        return -1; 
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

void printLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printLevelWise(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* currNode = queue[front++];
        printf("%d ", currNode->data);

        if (currNode->left != NULL) {
            queue[rear++] = currNode->left;
        }
        if (currNode->right != NULL) {
            queue[rear++] = currNode->right;
        }
    }
}

void mirrorImage(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorImage(root->left);
    mirrorImage(root->right);
}

void deleteTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert element\n2. Find Height\n3. Count Nodes\n4. Count Leaf Nodes\n");
        printf("5. Find Minimum\n6. Find Maximum\n7. Create Mirror Image\n");
        printf("8. Print Leaf Nodes\n9. Print Nodes Level Wise\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Height of the BST: %d\n", height(root));
                break;
            case 3:
                printf("Number of nodes in the BST: %d\n", countNodes(root));
                break;
            case 4:
                printf("Number of leaf nodes in the BST: %d\n", countLeafNodes(root));
                break;
            case 5:
                printf("Minimum node value: %d\n", findMin(root));
                break;
            case 6:
                printf("Maximum node value: %d\n", findMax(root));
                break;
            case 7:
                mirrorImage(root);
                printf("BST after creating a mirror image.\n");
                break;
            case 8:
                printf("Leaf nodes of the BST: ");
                printLeafNodes(root);
                printf("\n");
                break;
            case 9:
                printf("Nodes of the BST level-wise: ");
                printLevelWise(root);
                printf("\n");
                break;
        }
    } while (choice != 0);

    deleteTree(root);

    return 0;
}
