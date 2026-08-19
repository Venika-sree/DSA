#include<stdio.h>
#define MAX 5
int arr[MAX];
int top = -1;
void Push(int data){
	if( top == MAX-1){
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	arr[top]=data;
}
int pop(){
	int value;
	if(top==-1){
		printf("Stack Underflow\n");
		return -1;
		
		}
		value=arr[top];
		top=top-1;
		return value;
	}
int peek(){
	if (top==-1){
		printf("Stack is empty\n");
		
	}
	return arr[top];
}
void display(){
	int i;
	if(top==-1){
		printf("Stack is empty\n");
		
	}
	for(i=top;i>=0;i--){
		printf("%d\n",arr[i]);
		
	}
}

int main(){
	int data;
	Push(10);
	Push(20);
	Push(30);   
	display();
	data=pop();
	printf("Popped data is %d\n",data);
	data=peek();
	printf("Peeked value is %d\n",data);
	return 0;
}