#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node * NODE;
NODE createNodeInDCLL() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
void main() {
    NODE first = NULL;
    NODE second = NULL;
    int x;
    printf("Enter element of first node : ");
    scanf("%d", &x);
    first = createNodeInDCLL();
    first -> data = x;
    printf("Enter element of second node : ");
    scanf("%d", &x);
    second = createNodeInDCLL();
    second -> data = x;
    //creating links between the nodes in the Doubly circular linked list fashion.
    first->prev= second;
    first->next = second;
    second->prev = first;
    second->next = first;
    printf("The Doubly Circular Linked List is : %d <--> %d <--> %d\n", first -> data, first -> next -> data, first -> next -> prev -> data);
}
