#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
 };
typedef struct node *NODE;

NODE createNode() {
    NODE temp ;
    temp = (NODE) malloc(sizeof(struct node));
    temp -> next = NULL;
    return temp;
};

NODE addNodes(NODE first,int x){
    NODE temp,lastNode = first;
    temp = createNode();
    temp -> data = x ;
    if(first== NULL){
        first = temp;
    }else{
        while(lastNode -> next !=NULL){
            lastNode = lastNode-> next;
        }
        lastNode -> next = temp;
    }
    return first;
}

void traverseList(NODE first){
    if(first == NULL){
        printf("List is Empty.\n");
    }else{
        NODE temp = first;
        while(temp != NULL){
        printf("%d --> ", temp->data);
        temp = temp -> next;
        }
        printf("NULL\n");
    }
}

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
    printf("The list is : %d --> %d --> NULL\n", first -> data, first -> next -> data);
}
