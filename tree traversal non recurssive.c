#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* tree_node;
    struct StackNode* next;
};

struct StackNode* createStackNode(struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->tree_node = node;
    stackNode->next = NULL;
    return stackNode;
}

void push(struct StackNode** top_ref, struct TreeNode* node) {
    struct StackNode* stackNode = createStackNode(node);
    stackNode->next = *top_ref;
    *top_ref = stackNode;
}

int isEmpty(struct StackNode* top) {
    return top == NULL;
}

struct TreeNode* pop(struct StackNode** top_ref) {
    if (isEmpty(*top_ref))
        return NULL;

    struct StackNode* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    struct TreeNode* popped = temp->tree_node;
    free(temp);
    return popped;
}
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* current = root;
    struct StackNode* stack = NULL;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right)
            push(&stack, current->right);
        if (current->left)
            push(&stack, current->left);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left)
            push(&stack1, current->left);
        if (current->right)
            push(&stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        struct TreeNode* temp = pop(&stack2);
        printf("%d ", temp->data);
    }
}

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


int main() {
    struct TreeNode* root = NULL;
    int i,n,value;

    printf("Enter no of nodes=");
    scanf("%d",&i);
    for(i=1;i<n;i++)
    {
        printf("Enter value of nodes=");
        scanf("%d",&value);
        root = insert(root, value);
    }
    /*root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    */

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");


    return 0;
}
