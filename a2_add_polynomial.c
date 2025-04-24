#include<stdio.h>

struct poly{
    int coefficient;
    int exponent;
};


void struct_input(int size,struct poly p[]){
    int i;
    printf("\nenter <coefficient>x^<exponent> ->\n");
    for(i=0;i<size;i++){
        scanf("%d %d",&p[i].coefficient,&p[i].exponent);
    }
    printf("\n");
}


void addpoly(struct poly p1[],int size1,struct poly p2[],int size2){
    
    int i=0,j=0;
    
    while(i<size1||j<size2){

        if(i<size1-1 && (p1[i].exponent>p2[j].exponent || j>=size2-1)){
            if(p1[i].coefficient>=0){
                printf(" +");
            }
            else{
                printf(" ");
            }
            printf("%dx^%d",p1[i].coefficient,p1[i].exponent);
            i++;
        }

        else if(j<size2-1 && (p2[j].exponent>p1[i].exponent || i>=size1-1)){
            if(p2[j].coefficient>=0){
                printf(" +");
            }
            else{
                printf(" ");
            }
            printf("%dx^%d",p2[j].coefficient,p2[j].exponent);
            j++;
        }

        else{
            int sum=p1[i].coefficient+p2[j].coefficient;
            if(sum>=0){
                printf(" +");
            }
            else{
                printf(" ");
            }
            printf("%dx^%d",sum,p1[i].exponent);
            i++;
            j++;
        }
        
    }
}


void main(){
    struct poly p1[100];
    struct poly p2[100];
    int size1,size2;

    printf("Enter size of 1st polynomial -> ");
    scanf("%d",&size1);
    struct_input(size1,p1);
    printf("Enter size of 2nd polynomial -> ");
    scanf("%d",&size2);
    struct_input(size2,p2);

    printf("\n Addition of 2 polynomial -> \n");
    
    addpoly(p1,size1,p2,size2);
    
}