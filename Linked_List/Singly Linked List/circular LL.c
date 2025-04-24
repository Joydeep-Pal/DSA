#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int number;
    struct node *next;
}node;


void main(){
    int *head = NULL;

    int len;
    printf("Enter length of the linked list : ");
    scanf("%d",&len);

    for(int i=0;i<len;i++){
        node *n = malloc(sizeof(node));

        int num;
        scanf("%d",&num);

        n->number = num;
        n->next=NULL;

        //if list is empty
        if(head == NULL){
            head=n;
        }

        // list is not empty
        else{
            //traverse whole list 
            for(node *ptr = head ; ptr != NULL ; ptr=ptr->next){
                //find last node
                if(ptr->next == NULL){
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    
    // now connect the last node with the first to make a normal linked list into circular linked list
    for(node *ptr = head ; ptr!=NULL ; ptr=ptr->next){
        if(ptr->next == NULL){
            ptr->next=head;
        }
    }
}