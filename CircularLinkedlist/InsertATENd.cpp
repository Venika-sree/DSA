#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;

void insertAtEnd(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;

    if(head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
        return;
    }

    struct Node *last=head->prev;
    newNode->next=head;
    newNode->prev=last;
    last->next=newNode;
    head->prev=newNode;
}

void display(){
    if(head==NULL){
        printf("List is empty");
        return;
    }

    struct Node *temp=head;
    printf("List: ");

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");
}

int main(){
    struct Node *n1,*n2,*n3;

    n1=(struct Node*)malloc(sizeof(struct Node));
    n2=(struct Node*)malloc(sizeof(struct Node));
    n3=(struct Node*)malloc(sizeof(struct Node));

    n1->data=25;
    n2->data=56;
    n3->data=45;

    n1->next=n2;
    n2->next=n3;
    n3->next=n1;

    n1->prev=n3;
    n2->prev=n1;
    n3->prev=n2;

    head=n1;

    printf("Original values: ");
    display();

    insertAtEnd(10);

    printf("After insertion at end: ");
    display();

    return 0;
} 
