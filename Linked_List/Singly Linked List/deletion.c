#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int number;
    struct node *next;
}node;


void delete_from_beginning(node **head){
    //store the node in a pointer
    node *ptr = *head;

    //connect the head to the second element
    *head = (*head)->next;

    //free the first node stored in ptr
    free(ptr);
}


void delete_from_end(node **head){
    node *previous = NULL;
    // find the second last element
    for(node *ptr = *head ; ptr!=NULL ; ptr = ptr->next){
        if(ptr->next!=NULL){
            previous=ptr;
        }
    }

    //free the last element
    free(previous->next);
    previous->next = NULL;
}


void delete_from_any_position(node **head){
    int pos;
    printf("\n\nEnter position in which you want to remove : ");
    scanf("%d",&pos);

    //find the previous node
    node *previous = *head;
    for(int i=1; i<pos-1; i++){
        previous=previous->next;
    }

    //store the node at the position
    node *next = previous->next; 

    //connect the previous node with the new next node
    previous->next = next->next;

    //free the selected node 
    free(next);
}



void main(){
    node *head = NULL;
    int len;

    printf("Enter the length of linked list : ");
    scanf("%d",&len);

    for(int i=0;i<len;i++){
        node *n = malloc(sizeof(node));

        int num;
        scanf("%d",&num);

        n->number = num;
        n->next = NULL;

        // list is empty
        if(head==NULL){
            head = n;
        }

        // list is not empty
        else{
            for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
                // last element
                if(ptr->next==NULL){
                    ptr->next=n;
                    break;
                }
            }
        }
    }

    printf("\n \n Linked List -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //deletion from beginning
    delete_from_beginning(&head);

    printf("\n \ndeletion from beginning -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //deletion from end
    delete_from_end(&head);

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
    node *ptr = head;
    while(ptr != NULL){
        node *next = ptr->next;
        free(ptr);
        ptr=next;
    }
}