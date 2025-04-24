#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *previous;
    struct node *next;
}node;




void insert_at_beginning(node **head){
    node *n = malloc(sizeof(node));

    int num;
    printf("\n \nEnter the number you want to insert at beginning : ");
    scanf("%d",&num);

    n->number = num;
    n->previous = NULL;
    n->next = NULL;

    n->next = *head;          //connect new node with the first node
    (*head)->previous = n;    //connect first node with the new node
    *head = n;                //change head position
}


void insert_at_end(node **tail){
    node *n = malloc(sizeof(node));

    int num;
    printf("\n\nEnter the number you want to insert at end : ");
    scanf("%d",&num);

    n->number = num;
    n->previous = NULL;
    n->next = NULL;
   
    n->previous = *tail;        //connect new node with the last node
    (*tail)->next = n;          //connect last node with the new node
    *tail = n;                  //change tail position
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

    //find the previous and next position
    node *p = *head; 
    node *nx = NULL;

    for(int i=1;i<pos-1;i++){
        p = p->next;
    }

    nx = p->next;


    //connect the existing nodes with new node
    p->next = n;
    nx->previous = n;
    
    //connect the new node with existing nodes
    n->previous = p;
    n->next = nx;
}


void main(){
    node *head = NULL;
    node *tail = NULL;

    int len;
    printf("Enter no. of elements in the DOUBLY LINKED LIST : ");
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

        // else list is not empty
        else{
            tail->next = n;       // connect the new node with the existing list  (tail->next)
            n->previous=tail;     // now connect the existing list with the new node  (n->previous)
            tail = n;             // now update the tail as a new node is added to the list
        }
    }


    // Print DOUBLY LINKED LIST
    printf("\nDoubly Linked List -> \n");
    for(node *ptr = head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ",ptr->number);
    }


    //insert at beginning
    insert_at_beginning(&head);

    printf("\n \ninsertion at beginning -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //insert at end
    insert_at_end(&tail);

    printf("\n \ninsertion at end -> \n");
    for(node *ptr=head ; ptr!=NULL ; ptr=ptr->next){
        printf("%d ", ptr->number);
    }


    //insert at any position
    insert_at_any_position(&head);

    printf("\n \ninsertion at any position -> \n");
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