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
    temp = (NODE) malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}
NODE insertAtBeginInDCLL(NODE first, int x) {
    NODE temp, lastNode;
    temp = createNodeInDCLL();
    temp ->data = x;
    if(first == NULL) {
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
void traverseListInDCLL(NODE first) {
    NODE lastNode = first;
    do {
        printf("%d <--> ",lastNode -> data);
        lastNode = lastNode -> next;
    } while (lastNode != first);    
    printf("\n");
}
int countInDCLL(NODE first) {
    NODE temp = first;
    int sum = 0;
    if (first == NULL) {
        return sum;
    } else {
        do {
            sum++;
            temp = temp -> next;
        } while (temp != first);
        return sum;
    }
}
void main() {
    NODE first = NULL;
    int x, op;
    while(1) {
        printf("1.Insert At Begin 2.Count Number of Nodes 3.Traverse the List 4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtBeginInDCLL(first, x);
                    break;
            case 2: printf("The number of nodes in a DCLL are : %d\n", countInDCLL(first));
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
