#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE createNodeInCLL() {
    NODE temp;
    temp = (NODE) malloc(sizeof(struct node));
    temp -> next = NULL;
    return temp;
}
NODE addNodesInCLL(NODE first, int x) {

    // Write your code here
    NODE temp = createNodeInCLL();
    temp->data=x;
    if(first==NULL){
        first =temp;
        temp->next = first ;
    }
    else{
        NODE lastNode = first ;
        while (lastNode->next!=first){
            lastNode = lastNode -> next ;
        }
        lastNode->next= temp;
    }
    temp->next=first;
    return first ;
}
void traverseListInCLL(NODE first) {

    // Write your code here
    NODE temp = first ;
    do{
        printf("%d --> ",temp->data);
        temp=temp->next;
    }while(temp!=first);
    printf("\n");

}
void main() {
    NODE first = NULL;
    int x;
    printf("Enter elements up to -1 : ");
    scanf("%d", &x);
    while (x != -1) {
        first = addNodesInCLL(first, x);
        scanf("%d", &x);
    }
    if (first == NULL) {
        printf("Circular Linked List is empty\n");
    } else {
        printf("The elements in CLL are : ");
        traverseListInCLL(first);
    }
}
