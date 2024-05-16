#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node * NODE;
NODE first = NULL;
NODE createNodeInDCLL() {
    NODE temp;
    temp = (NODE) malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}
NODE addNodesInDCLL(NODE first, int x) {
    NODE temp, lastNode;
    temp = createNodeInDCLL();
    temp->data = x;
    if (first == NULL) {
        first = temp;
    } else {
        lastNode = first->prev;
        lastNode->next = temp;
        temp -> prev = lastNode;
    }
    temp -> next = first;
    first -> prev = temp;
    return first;
}
void traverseListInDCLL(NODE first) {
    NODE lastNode = first;
    do {
        printf("%d <--> ",lastNode -> data);
        lastNode = lastNode -> next;
    } while (lastNode != first);
    printf("\n");
}
void main() {
    NODE first = NULL;
    int x;
    printf("Enter elements up to -1 : ");
    scanf("%d", &x);
    while (x != -1) {
        first = addNodesInDCLL(first, x);
        scanf("%d", &x);
    }
    if (first == NULL) {
        printf("Doubly Circular Linked List is empty\n");
    } else {
        printf("The elements in DCLL are : ");
        traverseListInDCLL(first);
    }
}
