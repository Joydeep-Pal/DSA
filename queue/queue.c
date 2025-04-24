#include<stdio.h>

int Front=-1;
int Rear=-1;

void Enqueue(int queue[],int size,int value){
    if(Rear==size-1){
        printf("queue is full");
    }
    if(Front==-1){
        Front=0;
    }

    Rear+=1;
    queue[Rear]==value;
}

void Dequeue(int queue[]){
    if(Front==-1 || Front>Rear){
        printf("Queue is empty");
    }
    int n=queue[Front];
    if(Rear==Front){
        Rear=-1;
        Front=-1;
    }
    else{
        Front+=1;
    }

}

void main(){

}