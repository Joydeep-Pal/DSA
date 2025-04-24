#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int number;
    struct node *previous;
    struct node *next;
}node;


void delete_from_beginning(node **head){
    //store the node in a pointer
    node *ptr = *head;

    //connect the head to the second element
    *head = (*head)->next;

    (*head)->previous = NULL;

    //free the first node stored in ptr
    free(ptr);

}


void delete_from_end(node **tail){
    node *ptr = *tail;
    
    //change tail position
    *tail = (*tail)->previous;

    //remove connections of new tail with the last element
    (*tail)->next = NULL;

    free(ptr);
}


void delete_from_any_position(node **head){
    int pos;
    printf("\n\nEnter position in which you want to remove : ");
    scanf("%d",&pos);

    //find the derised node and taking its help find previous and next position
    node *ptr = *head;

    for(int i=1;i<pos;i++){
        ptr = ptr->next;
    }
        
    node *p = ptr->previous;
    node *nx = ptr->next;

    // connect previous and next
    p->next= nx;
    nx->previous = p;

    free(ptr);
     
}


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


    // Print DOUBLY LINKED LIST
    printf("Doubly Linked List -> \n");
    for(node *ptr = head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ",ptr->number);
    }


    //deletion from beginning
    delete_from_beginning(&head);

    printf("\n \ndeletion from beginning -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //deletion from end
    delete_from_end(&tail);

    printf("\n \ndeletion from end -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //deletion from any position
    delete_from_any_position(&head);

    printf("\n \ndeletion from any position -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    // free memory 
    node *ptr= head;
    while(ptr!=NULL){
        node *next = ptr->next;
        free(ptr);
        ptr=next;
    }
}