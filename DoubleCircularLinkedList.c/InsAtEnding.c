#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node * NODE;
NODE createNodeInDLL() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
NODE insertAtEndInDLL(NODE first, int x) {
    NODE temp,lastNode = first;
    temp=createNodeInDLL();
    temp->data=x;
    if(first==NULL){
        first=temp;
    }else{
        while(lastNode -> next != NULL){
            lastNode = lastNode ->next;
        }
        lastNode ->next=temp;
        temp->prev=lastNode;
    }
    return first;
}
void traverseListInDLL(NODE first) {
    if(first == NULL){
        printf("Doubly linked List is Empty.");
    }else{
        NODE lastNode = first;
        while(lastNode!=NULL){
            printf("%d <--> ",lastNode -> data);
            lastNode = lastNode -> next;
        }
        printf("NULL\n");
    }
}
void main() {
    NODE first = NULL;
    int x, op;
    while(1) {
        printf("1.Insert At End 2.Traverse the List 3.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtEndInDLL(first, x);
                    break;
            case 2: if (first == NULL) {
                        printf("Double Linked List is empty\n");
                    } else {
                        printf("The elements in DLL are : ");
                        traverseListInDLL(first);
                    }
                    break;
            case 3: exit(0);
        }
    }
}
