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
    temp->prev = NULL;
    temp->next = NULL;
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
NODE insertAtBeginInDCLL(NODE first, int x) {
    NODE temp, lastNode;
    temp = createNodeInDCLL();
    temp -> data = x;
    if (first == NULL) {
            temp->next= temp;
            temp->prev= temp;
    } else {
            lastNode = first->prev;
            temp -> prev = lastNode;
            temp -> next = first;
            lastNode -> next = temp;
            first -> prev = temp;
    }
    first = temp;
    return first;
}
int searchPosOfEleInDCLL(NODE first, int key) {
    NODE currentNode = first;
    int count = 0;
    if (currentNode == NULL) {
            return count;
    }
    while (currentNode != NULL && currentNode -> data != key) {
            if (currentNode -> next == first) {
                return 0;
            }
                count++;
                currentNode = currentNode -> next;
    }
    return(count + 1);
}
void main() {
    NODE first = NULL;
    int x, pos, op;
    while(1) {
        printf("1.Insert At Begin \n2.Search an element Position \n3.Traverse the List \n4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtBeginInDCLL(first, x);
                    break;
            case 2: printf("Enter search element : ");
                    scanf("%d", &x);
                    pos = searchPosOfEleInDCLL(first, x);
                    if (pos == 0) {
                        printf("The given element %d is not found in the given DCLL\n", x);
                    } else {
                        printf("The given element %d is found at position : %d\n", x, pos);
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
