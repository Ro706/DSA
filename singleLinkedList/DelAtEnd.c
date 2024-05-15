#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE createNode() {
    NODE temp;
    temp = (NODE) malloc(sizeof(struct node));
    temp -> next = NULL;
    return temp;
}

NODE insertAtEnd(NODE first, int x) {

    // Write your code here
    NODE newNode = createNode();
    newNode->data=x;
    if(first == NULL){
        first = newNode;
    }
    else{
        NODE last = first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next=newNode;
    }
    return first;
}

NODE deleteAtEnd(NODE first) {

    // Write your code here
    NODE last = first;
    if(last->next == NULL){
        first = NULL;
    }
    else{
        NODE prev;
        while(last->next != NULL){
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
    }
    printf("The deleted item from SLL : %d\n",last->data);
    free(last);
    return first;
}

void traverseList(NODE first) {
    NODE temp = first;
    while (temp != NULL) {
        printf("%d --> ",temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void main() {
    NODE first = NULL;
    int x, op;
    while(1) {
        printf("1.Insert At End \n2.Delete at End \n3.Traverse the List \n4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
		    printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtEnd(first, x);
                    break;
            case 2: 
		    if (first == NULL) {
                        printf("Single Linked List is empty so deletion is not possible\n");
                    } else {
                        first = deleteAtEnd(first);
                    }
                    break;
            case 3: 
		    if (first == NULL) {
                        printf("Single Linked List is empty\n");
                    } else {
                        printf("The elements in SLL are : ");
                        traverseList(first);
                    }
                    break;
            case 4: 
		    exit(0);
        }
    }
}
