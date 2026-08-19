#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;

void insertAtBeginning(int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
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
    head->prev=newNode;
    last->next=newNode;
    head=newNode;
}

void display(){
    struct Node *temp=head;

    if(temp==NULL){
        printf("List is empty.\n");
        return;
    }

    printf("List: ");

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");
}

int main(){
    struct Node *node1,*node2,*node3;

    node1=(struct Node*)malloc(sizeof(struct Node));
    node2=(struct Node*)malloc(sizeof(struct Node));
    node3=(struct Node*)malloc(sizeof(struct Node));

    node1->data=28;
    node2->data=54;
    node3->data=87;

    node1->next=node2;
    node2->next=node3;
    node3->next=node1;

    node1->prev=node3;
    node2->prev=node1;
    node3->prev=node2;

    head=node1;

    printf("Values: %d %d %d\n",node1->data,node2->data,node3->data);

    insertAtBeginning(59);
    insertAtBeginning(24);
    insertAtBeginning(98);

    display();

    return 0;
}
