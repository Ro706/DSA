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
NODE insertAtBeginInCLL(NODE first, int x) {
    NODE temp,lastNode=first;
    temp=createNodeInCLL();
    temp->data=x;
    if(first==NULL){
        first=temp;
        temp->next = first ;
    }else{
        while(lastNode->next!=first){
            lastNode=lastNode->next;
        }
        temp->next=first;
        first=temp;
        lastNode->next=first;
    }
    return first;
}
NODE deleteAtBeginInCLL(NODE first) {
    NODE prev=first ,lastNode=first;
    if(prev->next==first){
        first=NULL;
    }
    else{
        while(lastNode->next!=first){
            lastNode=lastNode->next;
        }
        first=prev->next;
        lastNode->next=first;
    }
    printf("The deleted element from CLL : %d\n",prev->data);
    free(prev);
    return first ;
}
void traverseListInCLL(NODE first) {
    NODE temp = first;
    do {
        printf("%d --> ", temp -> data);
        temp = temp -> next;
    } while (temp != first);
    printf("\n");
}
void main() {
    NODE first = NULL;
    int x, op;
    while(1) {
        printf("1.Insert At Begin \n2.Delete at Begin \n3.Traverse the List \n4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtBeginInCLL(first, x);
                    break;
            case 2: if (first == NULL) {
                        printf("Circular Linked List is empty so deletion is not possible\n");
                    } else {
                        first = deleteAtBeginInCLL(first);
                    }
                    break;
            case 3: if (first == NULL) {
                        printf("Circular Linked List is empty\n");
                    } else {
                        printf("The elements in CLL are : ");
                        traverseListInCLL(first);
                    }
                    break;
            case 4: exit(0);
        }
    }
}
