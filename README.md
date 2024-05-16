# Data Structures and Algorithms (DSA)

## What is DSA?

**Data Structures and Algorithms (DSA)** are fundamental concepts in computer science and programming. They play a crucial role in solving complex problems efficiently. Let's break down what each term means:

- **Data Structures**:
  - Data structures are ways of organizing and storing data in a computer's memory.
  - They define how data elements are stored, accessed, and manipulated.
  - Examples of common data structures include arrays, linked lists, trees, graphs, stacks, and queues.

- **Algorithms**:
  - Algorithms are step-by-step procedures or instructions for solving a specific problem.
  - They describe how to perform a task or computation.
  - Efficient algorithms are essential for optimizing resource usage (such as time and memory).

## Singly Linked List

A **singly linked list** is a type of data structure where each element (node) contains two parts:
1. **Data**: The actual value or payload stored in the node.
2. **Next Pointer**: A reference to the next node in the list.

### Characteristics of a Singly Linked List:

- **Dynamic Size**: A linked list can grow or shrink dynamically as elements are added or removed.
- **No Fixed Size**: Unlike arrays, linked lists do not have a fixed size.
- **Traversal**: To access elements, you start from the head (first node) and follow the next pointers until you reach the desired node.
- **Insertion and Deletion**:
  - Insertion: Adding a new node involves updating the next pointer of an existing node.
  - Deletion: Removing a node requires adjusting the next pointer of the preceding node.
- **Memory Overhead**: Each node has an additional pointer (next pointer), which consumes memory.

### Example:

Suppose we have the following singly linked list:

```
1 -> 5 -> 9 -> 3 -> NULL
```

- The head node contains the value `1`.
- The next pointer of the head points to the node with value `5`.
- The next pointer of the node with value `5` points to the node with value `9`, and so on.
- The last node's next pointer is `NULL`, indicating the end of the list.

### Use Cases:

- Singly linked lists are commonly used for implementing stacks, queues, and other dynamic data structures.
- They are efficient for insertion and deletion at the beginning or end of the list.

Remember that there are other types of linked lists (such as doubly linked lists and circular linked lists), each with its own characteristics and use cases.

## Circular Linked List

A **circular linked list** is a variation of the linked list in which the last node points back to the first node instead of pointing to `NULL`. This creates a circular loop in the linked list.

### Characteristics
- The `next` pointer of the last node points to the first node.
- There is no `NULL` at the end of the list.
- Can be singly or doubly linked.

### Advantages
- Circular linked lists are useful for applications where the entire list is to be repeatedly traversed (e.g., round-robin scheduling).
- Easier to manage when the list is manipulated by the tail, as you always have access to the head through the tail.

### Operations
#### Insertion
- **At the beginning**: Adjust the `next` of the new node to point to the head and update the last node's `next` to the new head.
- **At the end**: Adjust the `next` of the last node to point to the new node, and the `next` of the new node to point to the head.

#### Deletion
- **From the beginning**: Adjust the `next` of the last node to point to the second node and free the original head.
- **From the end**: Traverse to the second last node, adjust its `next` to point to the head, and free the last node.

### Example
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Circular Linked List: ");
    display(head);

    return 0;
}
```

# Doubly Linked List

A **doubly linked list** is a type of linked list in which each node contains three fields: 
- A data part
- Two pointers, `next` and `prev`, which point to the next node and the previous node in the sequence, respectively.

## Characteristics

- **Bidirectional Traversal**: Each node points to both its successor and predecessor.
- **Memory Usage**: Each node uses more memory compared to a singly linked list due to the additional pointer.
- **Flexibility**: Nodes can be easily added or removed without reorganizing the entire list.

## Advantages

- **Bi-directional Traversal**: Allows traversal in both forward and backward directions.
- **Easy Deletion**: Easier to delete a given node when a pointer to the node is given.
- **More Flexible**: More flexible than singly linked lists for certain operations.

## Operations

### Insertion

- **At the Beginning**: Adjust the `prev` of the current head, the `next` of the new node to the current head, and update the head to the new node.
- **At the End**: Traverse to the last node, adjust its `next` to the new node, the `prev` of the new node to the last node, and set the new node's `next` to `NULL`.

### Deletion

- **From the Beginning**: Adjust the `prev` of the second node to `NULL` and update the head to the second node.
- **From the End**: Traverse to the second last node, adjust its `next` to `NULL`, and free the last node.

## Example

Below is an example implementation of a doubly linked list in C:

```c
#include <stdio.h>
#include <stdlib.h>

// Definition for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display the doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Doubly Linked List: ");
    display(head);

    return 0;
}
```

# Trees and Their Types

A **tree** is a hierarchical data structure consisting of nodes connected by edges. It has the following properties:
- **Root Node**: The topmost node of the tree.
- **Parent Node**: The node which has one or more child nodes.
- **Child Node**: The node which is a descendant of another node.
- **Leaf Node**: A node with no children.
- **Subtree**: A tree consisting of a node and its descendants.

## Types of Trees

### 1. General Tree
A tree in which nodes can have any number of children.

### 2. Binary Tree
A tree in which each node has at most two children, typically referred to as the left child and the right child.

### 3. Binary Search Tree (BST)
A binary tree with the following properties:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

### 4. Balanced Tree
A tree where the height of the left and right subtrees of any node differ by at most one.

### 5. AVL Tree
A self-balancing binary search tree where the difference in heights of the left and right subtrees is at most one for all nodes.

### 6. Red-Black Tree
A self-balancing binary search tree where each node contains an extra bit for denoting the color of the node, either red or black.

### 7. B-Tree
A self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.

## Binary Tree

A **binary tree** is a tree data structure in which each node has at most two children. The children are usually called the left child and the right child.

### Characteristics

- **Root**: The top node of the tree.
- **Internal Node**: A node with at least one child.
- **Leaf Node**: A node with no children.
- **Depth**: The length of the path from the root to the node.
- **Height**: The length of the path from the node to the deepest leaf.

### Types of Binary Trees

1. **Full Binary Tree**: Every node has either 0 or 2 children.
2. **Complete Binary Tree**: All levels are completely filled except possibly the last level, which is filled from left to right.
3. **Perfect Binary Tree**: All internal nodes have exactly two children, and all leaf nodes are at the same level.
4. **Degenerate (or Pathological) Tree**: Each parent node has only one child.

### Operations on Binary Trees

#### Insertion
Nodes are inserted at the first available position in level order.

#### Deletion
Nodes are deleted and replaced with the deepest and rightmost node in the binary tree.

#### Traversal
- **In-order (Left, Root, Right)**: Visits the left subtree, the root, and then the right subtree.
- **Pre-order (Root, Left, Right)**: Visits the root, then the left subtree, and finally the right subtree.
- **Post-order (Left, Right, Root)**: Visits the left subtree, the right subtree, and then the root.

### Example of Binary Tree Implementation in C

```c
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
```
---
