#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top=NULL;

void Push(){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));

    if(newnode==NULL){
        printf("Memory Allocation Failed");
        return;
    }

    printf("Enter element: ");
    scanf("%d",&newnode->data);

    newnode->next=top;
    top=newnode;
}

void pop(){
    struct Node *temp;

    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }

    temp=top;
    printf("%d is popped\n",top->data);
    top=top->next;
    free(temp);
}

int peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return -1;
    }

    return top->data;
}

void display(){
    struct Node *temp=top;

    if(temp==NULL){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    int opt;
    int value;

    while(1){
    	printf("ENter operations: \n");  
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");

        printf("Enter: ");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                Push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                value=peek();

                if(value!=-1){
                    printf("Peeked value is %d\n",value);
                }
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid\n");
        }
    }

    return 0;
}