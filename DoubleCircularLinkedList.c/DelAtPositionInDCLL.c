#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;
NODE createNodeInDCLL() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}
void traverseListInDCLL(NODE first) {
    NODE lastNode = first;
    do {
            printf("%d <--> ",lastNode -> data);
                lastNode = lastNode -> next;
    } while (lastNode != first);    
    printf("\n");
}
NODE deleteAtPositionInDCLL(NODE first, int pos) {
    NODE temp = first, lastNode = first;
    int i;
    if (pos == 1) {
            if (temp -> next == first) {
                        first = NULL;
            } else {
                        lastNode = first->prev;
                        lastNode -> next = first -> next;
                        first -> next -> prev = lastNode;
                        first = first -> next;
            }   
    } else {
            for (i = 1; i < pos; i++) {
                if (temp -> next == first) {
                        printf("No such position in DCLL so deletion is not possible\n");
                        return first;
                        }
                        lastNode = temp;
                        temp = temp -> next;
            } 
                if (temp -> next == first) {
                        lastNode -> next = first;
                        first -> prev = lastNode;
                } else {
                        lastNode -> next = temp -> next;
                        temp -> next -> prev = lastNode;
                }
    }
    printf("The deleted element from DCLL : %d\n" , temp -> data);
    free(temp);
    return first;
}
NODE insertAtEndInDCLL(NODE first, int x) {
    NODE temp, lastNode;
    temp = createNodeInDCLL();
    temp->data = x;
    if (first == NULL) {
            first = temp;
    } else {
            lastNode = first->prev;
            lastNode->next = temp;
            temp -> prev = lastNode;
    }
    temp -> next = first;
    first -> prev = temp;
    return first;
}
