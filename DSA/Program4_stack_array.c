#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top=-1;

int isFull(){
    return top==MAX-1;
}

int isEmpty(){
    return top==-1;
}

void push(int val){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }

    stack[++top]=val;
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped %d\n",stack[top--]);
}

void peek(){
    if(isEmpty()){
        printf("Empty\n");
        return;
    }

    printf("Top=%d\n",stack[top]);
}

void display(){
    if(isEmpty()){
        printf("Empty\n");
        return;
    }

    for(int i=0;i<=top;i++)
        printf("%d ",stack[i]);

    printf("\n");
}

int main(){
    int ch,val;

    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                scanf("%d",&val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}