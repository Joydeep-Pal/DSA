#include<stdio.h>

int top=-1;

void push(int stack[],int size,int value){
    if(top==size-1){
        printf("Stack is Full");
    }

    top+=1;
    stack[top]=value;

}

void pop(int stack[]){
    if(top==-1){
        printf("Stack is empty");
    }
    
    top-=1;
}

void main(){
}