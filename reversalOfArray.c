#include<stdio.h>
#include<conio.h>
void main(){
    int array[]={1,2,3,4,5,6};
    int arraySize=6;
    printf("original array:\t");
    for(int i=0;i<arraySize;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
    int i=0,j=arraySize-1;
    while((i<=arraySize/2) && (j>=arraySize/2)){
        array[i]=array[i]+array[j];
        array[j]=array[i]-array[j];
        array[i]=array[i]-array[j];
        i++,j--;
    }
    
    for(int k=0;k<arraySize;k++){
        printf("%d\t",array[k]);
    }
    printf("\n");
    

}