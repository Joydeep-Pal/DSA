#include <stdio.h>

struct SparseMatrix{
    int row;
    int col;
    int val;
};


void main(){

    int mat1[5][4]={{1, 0, 0, 3},
                    {0, 0, 0, 2},
                    {3, 0, 0, 0},
                    {0, 0, 0, 4},
                    {5, 0, 0, 0}};

    int mat2[5][4]={{6, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 8, 0},
                    {0, 0, 0, 4},
                    {8, 0, 0, 0}};

    int size1,size2,size,i,j,k,l;

    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            if(mat1[i][j]!=0){
                size1++;
            }
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            if(mat2[i][j]!=0){
                size2++;
            }
        }
    }

    struct SparseMatrix triplet1[size1];
    struct SparseMatrix triplet2[size2];

    k=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(mat1[i][j]!=0){
                triplet1[k].row = i;
                triplet1[k].col = j;
                triplet1[k].val = mat1[i][j]; 
                k++;
            }
        }
    }

    k=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(mat2[i][j]!=0){
                triplet2[k].row = i;
                triplet2[k].col = j;
                triplet2[k].val = mat2[i][j]; 
                k++;
            }
        }
    }

    size=size1+size2;
    struct SparseMatrix result[size];

    i=0;
    j=0;
    k=0;
    
    while(i<size1 && j<size2){
        
        if(triplet1[i].row == triplet2[j].row && triplet1[i].col == triplet2[j].col){
            result[k].row = triplet1[i].row;
            result[k].col = triplet1[i].col;
            result[k].val = triplet1[i].val + triplet2[j].val;
            k++;
            i++;
            j++;
        } 

        else if((triplet1[i].row < triplet2[j].row || triplet1[i].row == triplet2[j].row) && triplet1[i].col < triplet2[j].col){
            result[k] = triplet1[i];
            k++;
            i++; 
        }
        
        else{
            result[k] = triplet2[j];
            k++;
            j++;
        }

    } 
       

    while(i < size1){
        result[k] = triplet1[i];
        k++;
        i++;
    }

    while(j < size2){
        result[k] = triplet2[j];
        k++;
        j++;
    }


    for (l=0;l<size;l++){
        printf("\n[%d, %d, %d]\n", result[l].row, result[l].col, result[l].val);
    }

}