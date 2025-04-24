#include<stdio.h>

int top=-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int isFull(int size){
    if(top==size-1){
        return 1;
    }
    return 0;
}

void push(int stack[],int size,int value){
    if(isFull(size)==1){
        printf("Stack is Full");
    }
    else{
        top+=1;
        stack[top]=value;
    }

}

void pop(){
    if(isEmpty()==1){
        printf("Stack is empty");
    }
    else{
        top-=1;
    }
    
}

void main(){
    int stack[100];
    int size=0,sizeTemp,n,s=1,i,j,count=0;
    while(s!=5){
        printf("\n Press 1 to push element. \n Press 2 to pop element. \n Press 3 to check if stack is empty or not. \n Press 4 to check if stack is full or not. \n Press 5 when done.\n \n");
        scanf("%d",&s);
        switch(s){
            case 1: //push
                printf("Enter no. of elements you want to enter : \n");
                scanf ("zd" ,&sizeTemp);
                size+=sizeTemp;
                printf ("Enter element to push :\n");
                for(i=0; i<sizeTemp; i++){
                    scanf ("%d",&n);
                    push(stack,size,n);
                    count++;
                }
                break;
            

            case 2: //pOP
                pop();
                count--;
                printf ("element poped\n");
                break;
                    
            case 3: //IsEmpty
                if (isEmpty()==1){
                    printf("Stack is Empty. \n");
                }
                else{
                    printf("Stack is not Empty.");
                }
                break;

            case 4: //is Full
                if (isEmpty(size)==1){
                    printf("Stack is Empty \n");
                }
                else{
                    printf("Stack is not Empty.");
                }
                break;

            case 5:
                printf("\n Operations done\n");
                break;


            default:
                printf("In Wrong key pressed\n");
                break;
        }
    }


    printf ("Stack ->\n");
    for(j=0; j<count; j++){
        printf ("%d ",stack[j]);
    }
}


            