
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;

void deleteBeginning(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }

    struct Node *last=head->prev;
    struct Node *temp=head;
    head=head->next;
    head->prev=last;
    last->next=head;
    free(temp);
}

void display(){
    if(head==NULL){
        printf("List is empty\n");
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

    printf("Before deletion: ");
    display();

    deleteBeginning();

    printf("After deletion: ");
    display();

    return 0;
}
