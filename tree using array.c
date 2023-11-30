#include <stdio.h>

#define MAX_NODES 100


int keys[MAX_NODES];

void insert(int rootIndex, int key) {
    if (keys[rootIndex] == 0) {
      
        keys[rootIndex] = key;
    } else {
      
        if (key < keys[rootIndex]) {
            insert(2 * rootIndex + 1, key); 
        } else if (key > keys[rootIndex]) {
            insert(2 * rootIndex + 2, key);
        }
    }
}

void inorderTraversal(int rootIndex) {
    if (keys[rootIndex] != 0) {
        inorderTraversal(2 * rootIndex + 1); // Traverse left subtree
        printf("%d ", keys[rootIndex]);      // Print current node
        inorderTraversal(2 * rootIndex + 2); // Traverse right subtree
    }
}

int main() {
    int key;
    char choice;

    do {
        printf("Enter key to insert into the BST: ");
        scanf("%d", &key);
        insert(0, key);

        printf("Do you want to insert another key? (y/n): ");
        scanf(" %c", &choice); // Notice the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    // Performing inorder traversal to display the sorted keys
    printf("Inorder Traversal: ");
    inorderTraversal(0);
    printf("\n");

    return 0;
}
