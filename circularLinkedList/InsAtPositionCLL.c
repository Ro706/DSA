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
NODE insertAtPositionInCLL(NODE first, int pos, int x) {

    // Write your code here
    NODE temp,lastNode = first;
    int i ;
    for(i=1;i<(pos-1);i++){
        if(lastNode->next==first){
            printf("No such position in CLL so insertion is not possible\n");
            return first;
        }
        lastNode=lastNode->next;
    }
    temp=createNodeInCLL();
    temp->data=x;
    if(pos==1){
        if(first == NULL){
            first = temp;
            temp-> next = first ;
        }else{
            while(lastNode->next != first){
                lastNode=lastNode->next;
            }
            temp->next = first ;
            first = temp;
            lastNode->next=first;
        }
    }else{
        temp->next=lastNode->next;
        lastNode->next=temp;
    }
    return first;

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
    int x, pos, op;
    while(1) {
        printf("1.Insert At specified position 2.Traverse the List 3.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
		    printf("Enter a position : ");
                    scanf("%d", &pos);
                    if (pos <= 0) {
                        printf("No such position in CLL so insertion is not possible\n");
                    } else {
                        printf("Enter an element : ");
                        scanf("%d", &x);
                        first = insertAtPositionInCLL(first, pos, x);
                    }
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
