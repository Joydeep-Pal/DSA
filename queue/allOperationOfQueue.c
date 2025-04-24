// WAP a proagram in c to implement all the operations on queue
//insert delete queue-empty and queue-full

#include<stdio.h>

int Front=-1;
int Rear=-1;

int isEmpty(){
    if(Rear==-1){
        return 1;
    }
    return 0;
}

int isFull(int size){
    if(Rear==size-1){
        return 1;
    }
    return 0;
}

void Enqueue(int queue[],int size,int value){
    if(isFull(size)==1){
        printf("queue is full");
    }
    else{
        if(Front==-1){
            Front=0;
        }
        Rear+=1;
        queue[Rear]=value;
    }
}

void Dequeue(int queue[]){
    if(isEmpty()==1){
        printf("Queue is empty");
    }
    else{
        int n=queue[Front];
        if(Rear==Front){
            Rear=-1;
            Front=-1;
        }
        else{
            Front+=1;
        }
    }
}

void main(){
    int queue[100];
    int size=0,sizeTemp,n,s=1,i,j,enq=0,deq=0;
    while(s!=5){
        printf("\n \n Press 1 to Enqueue element. \n Press 2 to Dequeue element. \n Press 3 to check if queue is empty or not. \n Press 4 to check if queue is full or not. \n Press 5 when done.\n \n");
        scanf("%d",&s);
        switch(s){
            case 1: // Enqueue
                printf("Enter no. of elements you want to enter : ");
                scanf ("%d" ,&sizeTemp);
                size+=sizeTemp;
                printf ("Enter elements to Enqueue : \n");
                for(i=0; i<sizeTemp; i++){
                    scanf("%d",&n);
                    Enqueue(queue,size,n);
                    enq++;
                }
                break;
            

            case 2: // Dequeue
                Dequeue(queue);
                deq++;
                printf ("element poped \n");
                break;
                    
            case 3: //IsEmpty
                if (isEmpty()==1){
                    printf("Queue is Empty. \n");
                }
                else{
                    printf("Queue is not Empty. \n");
                }
                break;

            case 4: //is Full
                if (isFull(size)==1){
                    printf("Queue is Full. \n");
                }
                else{
                    printf("Queue is not Full. \n");
                }
                break;

            case 5:
                printf("\n Operations done. \n");
                break;


            default:
                printf("\n Wrong key pressed. \n");
                break;
        }
    }


    printf ("Queue ->\n");
    for(j=deq; j<enq; j++){
        printf ("%d ",queue[j]);
    }
}