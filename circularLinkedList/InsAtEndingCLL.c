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
NODE insertAtEndInCLL(NODE first, int x) {

    // Write your code here
    NODE temp ,lastNode = first;
    temp=createNodeInCLL();
    temp->data=x;
    if(first == NULL){
        first = temp;
    }
    else{
        while(lastNode->next!=first){
            lastNode=lastNode->next;
        }
        lastNode->next=temp;
    }
    temp->next = first ;
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
    int x, op;
    while(1) {
        printf("1.Insert At End \n2.Traverse the List \n3.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
		    printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtEndInCLL(first, x);
                    break;
            case 2: 
		    if (first == NULL) {
                        printf("Circular Linked List is empty\n");
                    } else {
                        printf("The elements in CLL are : ");
                        traverseListInCLL(first);
                    }
                    break;
            case 3: 
		    exit(0);
        }
    }
}
