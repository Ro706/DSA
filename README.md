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

---
