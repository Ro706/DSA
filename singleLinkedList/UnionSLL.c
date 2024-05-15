#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;
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
void print(NODE first) {
    NODE q = first;
    if (first == NULL) {
        printf("Single Linked List is empty\n");
    } else {
        printf("Elements in the list are : ");
        while (q != NULL) {
            printf("%d---> ", q->data);
            q = q->next;
        }
        printf("NULL\n");
    }
}
NODE concatenate(NODE t1, NODE t2) {
    // Write the code
    NODE t3;
    if(t1==NULL){
        return t2;
    }else{
        t3=t1;
        while(t1->next!=NULL){
            t1=t1->next;
        }
        t1->next=t2;
    }
    return t3;
}
NODE unionSLL(NODE l1, NODE l2) {
    // Write the code
    NODE t1,t2,q=NULL;
    NODE l3= concatenate(l1,l2);
    for(t1=l3;t1!=NULL && t1->next!=NULL;t1=t1->next){
        for(t2=t1;t2!=NULL && t2->next!=NULL;){
            if(t1->data == t2->next->data){
                q=t2->next;
                t2->next=q->next;
                free(q);
            }
            else{
                t2=t2->next;
            }
        }
    }
    return l3;
}

int main() {
    NODE l1, l2, l3;
    l1 = l2 = l3 = NULL;
    printf("Enter list-1 elements :\n");
    l1 = createAndAddNodes(l1);
    printf("Enter list-2 elements :\n");
    l2 = createAndAddNodes(l2);
    l3 = unionSLL(l1, l2);
    printf("Elements in the union list :\n");
    print(l3);
}
