#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *previous;
    struct node *next;
}node;

void main(){
    node *head = NULL;
    node *tail = NULL;

    int len;
    printf("Enter no. of elements in the LINKED LIST : ");
    scanf("%d",&len);
    
    for(int i=0 ; i<len ; i++){
        node *n = malloc(sizeof(node));

        int num;
        scanf("%d",&num);

        n->number = num;

        n->next = NULL;
        n->previous = NULL;

        // check if the list is empty
        if(head==NULL){
            head=n;
            tail=n;
        }

        // else lsit is not empty
        else{
            tail->next = n;       // connect the new node with the existing list  (tail->next)
            n->previous=tail;     // now connect the existing list with the new node  (n->previous)
            tail = n;             // now update the tail as a new node is added to the list
        }
    }


    // Print LINKED LIST
    printf("Doubly Linked List -> \n");
    for(node *ptr = head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ",ptr->number);
    }


    // free memory 
    node *ptr= head;
    while(ptr!=NULL){
        node *next = ptr->next;
        free(ptr);
        ptr=next;
    }
}