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
NODE insertAtBeginInDLL(NODE first, int x) {
    NODE temp;
    temp=createNodeInDLL();
    temp->data=x;
    if(first != NULL){
        temp ->next = first;
        first-> prev = temp;
    }
    first = temp;
    return first;
}
NODE deleteAtBeginInDLL(NODE first) {
    NODE lastNode = first;
    if(first == NULL){
        printf("Doubly Linked List is Empty. So deletion is not possible.\n");
    }else{
        if(lastNode -> next  == NULL){
            first = NULL;
        }else{
            first = first -> next;
            first -> prev = NULL;
        }
        printf("The deleted element from DLL : %d\n",lastNode-> data);
        free(lastNode);
        return first;
    }
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
    int x, op;
    while(1) {
        printf("1.Insert At Begin 2.Delete at Begin 3.Traverse the List 4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtBeginInDLL(first, x);
                    break;
            case 2: if (first == NULL) {
                        printf("Double Linked List is empty so deletion is not possible\n");
                    } else {
                        first = deleteAtBeginInDLL(first);
                    }
                    break;
            case 3: if (first == NULL) {
                        printf("Double Linked List is empty\n");
                    } else {
                        printf("The elements in DLL are : ");
                        traverseListInDLL(first);
                    }
                    break;
            case 4: exit(0);
        }
    }
}
