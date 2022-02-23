#include<stdio.h>
#include<conio.h>
void main(){
    int array[]={1,2,3,4,5,6};
    int arraySize=6,t;
    printf("original array:\t");
    for(int i=0;i<arraySize;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
    for(int i=0;i<arraySize;i++){
        t=array[arraySize-1];
        for(int j=arraySize-1;j>0;j--){
            array[j]=array[j-1];
        }
        array[0]=t;
        printf("iteration %d:\t",i);
        for(int k=0;k<arraySize;k++){
            printf("%d\t",array[k]);
        }
        printf("\n");
    }

}