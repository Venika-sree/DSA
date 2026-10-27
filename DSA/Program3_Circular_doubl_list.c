#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next,*prev;
};

struct Node *head=NULL;

void insertBeginning(int value){
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

    head->prev=newNode;
    last->next=newNode;
    head=newNode;
}

void insertEnd(int value){
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

void deleteBeginning(){
    if(head==NULL)
        return;

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

void deleteEnd(){
    if(head==NULL)
        return;

    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }

    struct Node *last=head->prev;

    last->prev->next=head;
    head->prev=last->prev;

    free(last);
}

void display(){
    if(head==NULL){
        printf("Empty\n");
        return;
    }

    struct Node *temp=head;

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");
}

int main(){
    int ch,val;

    while(1){
        printf("\n1.Insert Beg\n2.Insert End\n3.Delete Beg\n4.Delete End\n5.Display\n6.Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                scanf("%d",&val);
                insertBeginning(val);
                break;

            case 2:
                scanf("%d",&val);
                insertEnd(val);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;
        }
    }
}