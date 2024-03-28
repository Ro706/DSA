#include<stdio.h>
#include<stdlib.h>
#include "CreateANode.c"
void main() {
    NODE first = NULL;
    int x;
    first = createNode();
    printf("Enter element of first node : ");
    scanf("%d", &x);
    first -> data = x;
    first -> next = createNode();
    printf("Enter element of second node : ");
    scanf("%d", &x);
    first -> next -> data = x;
    printf("The list is : %d --> %d --> NULL\n", first -> data, first -> next -> data );
}
