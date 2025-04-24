#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int number;
    struct node *next;
}node;


void insert_at_beginning(node **head){
    node *n = malloc(sizeof(node));

    int num;
    printf("\n \nEnter the number you want to insert at beginning : ");
    scanf("%d",&num);

    n->number = num;
    n->next = NULL;

    n->next = *head;
    *head = n;
}


void insert_at_end(node **head){
    node *n = malloc(sizeof(node));

    int num;
    printf("\n\nEnter the number you want to insert at end : ");
    scanf("%d",&num);

    n->number = num;
    n->next = NULL;

    for(node *ptr = *head; ptr!=NULL; ptr = ptr->next){
        if(ptr->next == NULL){
            ptr->next = n;
            break;
        }
    }
}


void insert_at_any_position(node **head){
    node *n = malloc(sizeof(node));

    int num;
    printf("\n \nEnter the number you want to insert at any position : ");
    scanf("%d",&num);

    n->number = num;
    n->next = NULL;

    int pos;
    printf("\n\nEnter the position in which you want to enter : ");
    scanf("%d",&pos);

    //find the previous position
    node *previous = *head; 
    for(int i=1;i<pos-1;i++){
        previous = previous->next;
    }

    //first connect the next node (present in previous->next) with the new node
    n->next = previous->next;

    //now connect the new node with the previous
    previous->next = n; 
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


    //insert at beginning
    insert_at_beginning(&head);

    printf("\n \ninsert at beginning -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //insert at end
    insert_at_end(&head);

    printf("\n \ninsert at end -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //insert at any position
    insert_at_any_position(&head);

    printf("\n \ninsert at any position -> \n");
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