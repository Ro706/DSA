#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node * NODE;
NODE createAndAddNodes(NODE first) {
    NODE temp, q;
    int x;
    printf("Enter element : ");
    scanf("%d", &x);
    while(x != -1) {
        temp = (NODE)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;
        if(first == NULL) {
            first = temp;
        } else {
            q->next = temp;
        }
        q = temp;
        printf("Enter element : ");
        scanf("%d", &x);
    }
    return first;
}
NODE sort(NODE first) {
    // Write the code
    NODE t1;
    NODE t2;
    int x;
    for(t1=first;t1->next!=NULL;t1=t1->next){
        for(t2=t1->next;t2!=NULL;t2=t2->next){
            if(t1->data>t2->data){
                x=t1->data;
                t1->data=t2->data;
                t2->data=x;
            }
        }
    }
    return first;
}
NODE add(NODE l3,int x) {
    // Write the code
    NODE temp,q=l3;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(l3==NULL){
        l3=temp;
    }
    else{
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=temp;
    }
    return l3;
}
NODE intersectionSLL(NODE l1,NODE l2) {
    // Write the code
    NODE t1=l1,t2=l2,l3=NULL;
    while(t1!=NULL && t2!=NULL){
        if(t1->data<t2->data){
            t1=t1->next;
        }
        else if(t1->data>t2->data){
            t2=t2->next;
        }
        else{
            l3=add(l3,t1->data);
            t1=t1->next;
            t2=t2->next;
        }
    }
    return l3;
}
void print(NODE first) {
    NODE q = first;
    if (first == NULL) {
        printf("Single Linked List is empty\n");
    } else {
        printf("Elements in the list are : ");
        while (q != NULL) {
            printf("%d---> ", q -> data);
            q = q -> next;
        }
        printf("NULL\n");
    }
}

int main() {
    NODE l1, l2, l3;
    l1 = l2 = l3 = NULL;
    printf("Enter list-1 elements :\n");
    l1 = createAndAddNodes(l1);
    printf("Enter list-2 elements :\n");
    l2 = createAndAddNodes(l2);
    if (l1 == NULL || l2 == NULL) {
        printf("Single Linked List is empty\n");
        return 0;
    }
    l1 = sort(l1);
    l2 = sort(l2);
    l3 = intersectionSLL(l1, l2);
    printf("Elements in the intesection list :\n");
    print(l3);
}
