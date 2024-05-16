#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        // Tree is empty, create the root node
        root = createNode(val);
    } else if (val < root->val) {
        // Insert in the left subtree
        root->left = insertNode(root->left, val);
    } else {
        // Insert in the right subtree
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Function to search for a node in the binary search tree
struct TreeNode* searchNode(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;
    if (val < root->val)
        return searchNode(root->left, val);
    else
        return searchNode(root->right, val);
}

// Function to find the minimum value node in a binary search tree
struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from the binary search tree
struct TreeNode* deleteNode(struct TreeNode* root, int val) {
    if (root == NULL) return root;

    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node to be deleted found

        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Function for in-order traversal of the binary search tree
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

// Function to free the binary search tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function to demonstrate the binary search tree operations
int main() {
    struct TreeNode* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 20\n");
    root = deleteNode(root, 20);
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 30\n");
    root = deleteNode(root, 30);
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 50\n");
    root = deleteNode(root, 50);
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);
    return 0;
}
