#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE createAndAddNodes(NODE first) {
      NODE temp,q;
      int x;
      printf("Enter element : ");
      scanf("%d",&x);
      while(x!=-1){
        temp=(NODE)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        if(first==NULL){
            first=temp;
        }
        else{
            q->next=temp;
        }
        q=temp;
        printf("Enter element : ");
        scanf("%d",&x);
      }
      return first;
}
NODE concatenate(NODE t1, NODE t2) {
    NODE t3;
    if(t1==NULL){
        return t2;
    }
    else if (t2==NULL){
        return t1;
    }
    else{
        t3=t1;
        while (t1->next!=NULL){
            t1=t1->next;
        }
        t1->next=t2;
    }
    return t3;
}
void print(NODE first) {
    NODE q = first;
    if (first == NULL) {
        printf("Single Linked List is empty\n");
    } else {
        while (q != NULL) {
            printf("%d---> ", q->data);
            q = q->next;
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
    l3 = concatenate(l1, l2);
    printf("Elements in concatenated list :\n");
    print(l3);
}
