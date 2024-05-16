#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node * NODE;
NODE createNodeInDCLL() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
NODE insertAtBeginInDCLL(NODE first, int x) {
    NODE temp, lastNode;
    temp = createNodeInDCLL();
    temp ->data = x;
    if (first == NULL) {
        temp->next= temp;
        temp->prev= temp;
    }
    else {
        lastNode = first->prev;
        temp -> prev = lastNode;
        temp -> next = first;
        lastNode->next = temp;
        first -> prev = temp;
    }
    first = temp;
    return first;
}
NODE deleteAtBeginInDCLL(NODE first) {
    NODE temp = first, lastNode = first;
    if (temp -> next == first) {
        first = NULL;
    } else {
        lastNode = first->prev;
        first = first -> next;
        first -> prev = lastNode;
        lastNode -> next = first;
    }
    printf("The deleted element from DCLL : %d\n",temp->data);
    free(temp);
    return first;
}
void traverseListInDCLL(NODE first) {
    NODE lastNode = first;
    do {
        printf("%d <--> ",lastNode -> data);
        lastNode = lastNode -> next;
    } while (lastNode != first);
    printf("\n");
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
                    first = insertAtBeginInDCLL(first, x);
                    break;
            case 2: if (first == NULL) {
                        printf("Double Linked List is empty so deletion is not possible\n");
                    } else {
                        first = deleteAtBeginInDCLL(first);
                    }
                    break;
            case 3: if (first == NULL) {
                        printf("Doubly Circular Linked List is empty\n");
                    } else {
                        printf("The elements in DCLL are : ");
                        traverseListInDCLL(first);
                    }
                    break;
            case 4: exit(0);
        }
    }
}
