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
NODE insertAtBegin(NODE first, int x) {
    NODE temp;
    temp=createNode();
    temp->data=x;
    if(first==NULL){
        first=temp;
    }
    else{
        temp->next=first;
        first=temp;
    }
}
int searchPosOfEle(NODE first, int key) {
    int count=0;
    NODE currentNode=first;
    if(first==NULL){
        return count;
    }else{
        while(currentNode->data!=key){
            if(currentNode->next==NULL){
                return 0;
            }else{
                count++;
                currentNode=currentNode->next;
            }
        }
        return (++count);
    }
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
    int x, pos, op;
    while(1) {
        printf("1.Insert At Begin \n2.Search an element Position \n3.Traverse the List \n4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1:
		    printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtBegin(first, x);
                    break;
            case 2:
		    printf("Enter search element : ");
                    scanf("%d", &x);
                    pos = searchPosOfEle(first, x);
                    if (pos == 0) {
                        printf("The given element %d is not found in the given SLL\n", x);
                    } else {
                        printf("The given element %d is found at position : %d\n", x, pos);
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
