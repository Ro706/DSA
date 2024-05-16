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

// Function to insert a new node in the binary tree
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

// Function for in-order traversal of the binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

// Function for pre-order traversal of the binary tree
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for post-order traversal of the binary tree
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);
}

// Function to free the binary tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function to demonstrate the binary tree operations
int main() {
    struct TreeNode* root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 8);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 9);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    freeTree(root);
    return 0;
}
