#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE createNodeInCLL() {
    NODE temp;
    temp = (NODE) malloc(sizeof(struct node));
    temp -> next = NULL;
    return temp;
}
NODE insertAtBeginInCLL(NODE first, int x) {
    NODE temp,last=first;
    temp=createNodeInCLL();
    temp->data=x;
    if(first==NULL){
        first=temp;
        temp->next=first;
    }
    else{
        while(last->next != first){
            last = last->next;
        }
        temp->next = first ;
        first = temp;
        last -> next = first ;
    }
    return first;
}
int countInCLL(NODE first) {
    int sum = 0;
    NODE temp = first;
    if(first == NULL){
        return sum;
    }
    else{
        do{
            sum++;
            temp=temp->next;
        }while(temp!=first);
    }
    return sum;
}
void traverseListInCLL(NODE first) {
    NODE temp = first;
    do {
        printf("%d --> ", temp -> data);
        temp = temp -> next;
    } while (temp != first);
    printf("\n");
}

void main() {
    NODE first = NULL;
    int x, op;
    while(1) {
        printf("1.Insert At Begin \n2.Count Number of Nodes \n3.Traverse the List \n4.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
            case 1: printf("Enter an element : ");
                    scanf("%d", &x);
                    first = insertAtBeginInCLL(first, x);
                    break;
            case 2: printf("The number of nodes in a CLL are : %d\n", countInCLL(first));
                    break;
            case 3: if (first == NULL) {
                        printf("Circular Linked List is empty\n");
                    } else {
                        printf("The elements in CLL are : ");
                        traverseListInCLL(first);
                    }
                    break;
            case 4: exit(0);
        }
    }
}
