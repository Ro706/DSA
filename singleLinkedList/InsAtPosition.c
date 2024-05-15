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
NODE insertAtPosition(NODE first, int pos, int x) {
    NODE temp, prevPos = first,lastNode = first;
    for(int i = 1;i<pos;i++){
        if(lastNode==NULL){
            printf("No such position in SLL so insertion is not possible\n");
            return first;
        }
        prevPos = lastNode;
        lastNode = lastNode -> next;
    }
    temp = createNode();
    temp ->data = x;
    if(pos == 1){
        temp -> next = first;
        first = temp;
    }else{
        temp -> next = prevPos->next;
        prevPos->next = temp;
    };
    return first;
}
void traverseList(NODE first) {
    NODE temp = first;
    while(temp != NULL){
        printf("%d --> ",temp->data);
        temp = temp ->next;
    }
    printf("NULL\n");
}

void main() {
    NODE first = NULL;
    int x, pos, op;
    while(1) {
        printf("1.Insert At specified position \n2.Traverse the List \n3.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
		    printf("Enter a position : ");
                    scanf("%d", &pos);
                    if (pos <= 0) {
                        printf("No such position in SLL so insertion is not possible\n");
                    } else {
                        printf("Enter an element : ");
                        scanf("%d", &x);
                        first = insertAtPosition(first, pos, x);
                    }
                    break;
            case 2: 
		    if (first == NULL) {
                        printf("Single Linked List is empty\n");
                    } else {
                        printf("The elements in SLL are : ");
                        traverseList(first);
                    }
                    break;
            case 3: 
		    exit(0);
        }
    }
}
