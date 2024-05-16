#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* NODE;

// Function to create a new node
NODE createNodeInDLL() {
    NODE newNode = (NODE)malloc(sizeof(struct node)); // Allocate memory for a new node
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->next = NULL; // Initialize the next pointer to NULL
    newNode->prev = NULL; // Initialize the prev pointer to NULL
    return newNode;
}
// Function to insert a node at the end of the doubly linked list
NODE insertAtEndInDLL(NODE first, int x) {
    NODE temp, lastNode = first;
    temp = createNodeInDLL(); // Create a new node
    temp->data = x; // Assign the data to the new node
    if (first == NULL) { // If the list is empty
        first = temp; // Make the new node the first node
    } else {
        while (lastNode->next != NULL) {
            lastNode = lastNode->next; // Traverse to the end of the list
        }
        lastNode->next = temp; // Link the last node to the new node
        temp->prev = lastNode; // Link the new node back to the last node
    }
    return first; // Return the head of the list
}
// Function to delete a node at a specific position in the doubly linked list
NODE deleteAtPositionInDLL(NODE first, int position) {
    NODE prev = NULL;
    if (first == NULL) {
        printf("Doubly Linked List is empty so deletion is not possible\n");
    } else {
        NODE last = first;
        if (position == 1) { // If the position is the first node
            if (last->next == NULL) { // If there is only one node in the list
                first = NULL; // Make the list empty
            } else {
                first = first->next; // Move the head to the next node
                first->prev = NULL; // Set the prev pointer of the new head to NULL
            }
        } else {
            int i;
            for (i = 1; i < position; i++) {
                if (last == NULL) {
                    printf("No such position in DLL so deletion is not possible\n");
                    return first;
                } else {
                    prev = last;
                    last = last->next; // Move to the desired position
                }
            }
            if (last == NULL || position <= 0) {
                printf("No such position in DLL so deletion is not possible\n");
                return first;
            } else if (last->next == NULL) {
                prev->next = NULL; // Unlink the last node
            } else {
                prev->next = last->next; // Unlink the node to be deleted
                last->next->prev = prev; // Link the next node back to the previous node
            }
        }
        printf("The deleted element from DLL: %d\n", last->data);
        free(last); // Free the memory of the deleted node
    }
    return first; // Return the head of the list
}
// Function to traverse and print the doubly linked list
void traverseListInDLL(NODE first) {
    NODE temp = first;
    while (temp != NULL) {
        printf("%d --> ", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}
#include<stdio.h>
#include<stdlib.h>
#include "DelAtPositionInDLL.c"
void main() {
    NODE first = NULL;
    int x, op, pos;
    while(1) {
        printf("1.Insert At End 2.Delete at Position 3.Traverse the List 4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtEndInDLL(first, x);
                    break;
            case 2: if (first == NULL) {
                        printf("Double Linked List is empty so deletion is not possible\n");
                    } else {
                        printf("Enter position : ");
                        scanf("%d", &pos);
                        first = deleteAtPositionInDLL(first, pos);
                    }
                    break;
            case 3: if (first == NULL) {
                        printf("Double Linked List is empty\n");
                    } else {
                        printf("The elements in DLL are : ");
                        traverseListInDLL(first);
                    }
                    break;
            case 4: exit(0);
        }
    }
}
