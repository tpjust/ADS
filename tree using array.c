#include <stdio.h>

#define MAX_NODES 100

// Array to store keys in the BST
int keys[MAX_NODES];

// Function to insert a key into the BST
void insert(int rootIndex, int key) {
    if (keys[rootIndex] == 0) {
        // If the current root is empty, insert the key
        keys[rootIndex] = key;
    } else {
        // Otherwise, recursively insert into the left or right subtree
        if (key < keys[rootIndex]) {
            insert(2 * rootIndex + 1, key); // Insert into the left subtree
        } else if (key > keys[rootIndex]) {
            insert(2 * rootIndex + 2, key); // Insert into the right subtree
        }
    }
}

// Function to perform inorder traversal of the BST
void inorderTraversal(int rootIndex) {
    if (keys[rootIndex] != 0) {
        inorderTraversal(2 * rootIndex + 1); // Traverse left subtree
        printf("%d ", keys[rootIndex]);      // Print current node
        inorderTraversal(2 * rootIndex + 2); // Traverse right subtree
    }
}

int main() {
    // Inserting keys into the BST
    insert(0, 50);
    insert(0, 30);
    insert(0, 20);
    insert(0, 40);
    insert(0, 70);
    insert(0, 60);
    insert(0, 80);

    // Performing inorder traversal to display the sorted keys
    printf("Inorder Traversal: ");
    inorderTraversal(0);
    printf("\n");

    return 0;
}
