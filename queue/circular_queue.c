#include<stdio.h>

int Front =-1;
int Rear =-1;

//Front++ -> (Front+1)%size
//Rear++ -> (Rear+1)%size

void Enqueue(int queue[],int size,int value){
    if(Front==(Rear+1)%size){
        printf("queue is full");
    }
    if(Front==-1){
        Front=0;
    }

    Rear=(Rear+1)%size;
    queue[Rear]=value;
}

void Dequeue(int queue[],int size){
    if(Front==-1){
        printf("Queue is empty");
    }
    if(Front==Rear){
        Front=-1;
        Rear=-1;
    }

    Front=(Front+1)%size;
}