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
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}
int countInDLL(NODE first) {
    NODE lastNode= first;
    int sum = 0 ;
    while (lastNode != NULL){
        sum++;
        lastNode = lastNode -> next;
    }
    return sum;
}
NODE insertAtBeginInDLL(NODE first, int x) {
    NODE temp;
    temp = createNodeInDLL();
    temp-> data = x;
    if(first != NULL){
        temp -> next = first;
        first -> prev = temp;
    }
    first = temp;
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
    int x, op;
    while(1) {
        printf("1.Insert At Begin 2.Count Number of Nodes 3.Traverse the List 4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtBeginInDLL(first, x);
                    break;
            case 2: printf("The number of nodes in a DLL are : %d\n", countInDLL(first));
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
