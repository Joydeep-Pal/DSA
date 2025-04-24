#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    struct node *previous;
    int number;
    struct node *next;
}node;


void main(){
    node *head = NULL;
    node *tail = NULL;

    int len;
    printf("Enter length of the Linked List : ");
    scanf("%d",&len);

    for(int i=0;i<len;i++){
        node *n = malloc(sizeof(node));

        int num;
        scanf("%d",&num);

        n->previous = NULL;
        n->next = NULL;

        //if list is empty
        if(head==NULL){
            head = n;
            tail = n;
        }

        //else list is not empty
        else{
            tail->next = n;          //connecting end node with new node
            n->previous = tail;      //connect new node with end node
            tail = n;                //new tail will be the new node that is being added
        }
    }

    tail->next = head;        //connect end with start 
    head->previous = tail;    //connect start with end
}