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
NODE insertAtPositionInDLL(NODE first, int position, int x) {
    if(position <= 0 ||(first == NULL && position > 1)){
        printf("No such position in DLL so insertion is not possible\n");
        return first;
    }
    NODE temp,last = first;
    int i ;
    for(i = 1;i<(position - 1 );i++){
        if(last -> next== NULL){
            printf("No such position in DLL so insertion is not possible\n");
            return first;
        }
        last = last -> next;
    }
    temp = createNodeInDLL();
    temp->data = x;
    if(position == 1){
        if(first != NULL){
            temp -> next = first;
            first -> prev = temp;
        }
        first = temp;
    }
    else{
        temp -> next = last -> next;
        last -> next = temp;
        temp -> prev = last;
    }
    return first;
}
void traverseListInDLL(NODE first) {
    NODE lastNode = first;
    while (lastNode != NULL) {
        printf("%d <--> ", lastNode -> data);
        lastNode = lastNode -> next;
    }
    printf("NULL\n");
}
void main() {
    NODE first = NULL;
    int x, pos, op;
    while(1) {
        printf("1.Insert At specified position 2.Traverse the List 3.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter a position : ");
                    scanf("%d", &pos);
                    printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtPositionInDLL(first, pos, x);
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
