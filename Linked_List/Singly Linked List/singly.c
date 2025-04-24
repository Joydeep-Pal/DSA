#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;

void delFromBeginning(node *head){
    node *next = head->next;
    free(head);
    head=next;
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

    // free memory
    node *ptr = head;
    while(ptr != NULL){
        node *next = ptr->next;
        free(ptr);
        ptr=next;
    }
}