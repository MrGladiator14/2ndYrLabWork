#include<stdio.h>
#include<conio.h>
void main(){
    int array1[]={1,2,3,4,5,6};
    int array2[]={7,8,9};
    int array3Size,array1Size=6,array2Size=3;
    int array3[20];
    array3Size=array2Size+array1Size;
    printf("original array1:\t");
    for(int i=0;i<array1Size;i++){
        printf("%d\t",array1[i]);
    }
    printf("\n");
    printf("original array2:\t");
    for(int i=0;i<array2Size;i++){
        printf("%d\t",array2[i]);
    }
    printf("\n");
    for(int i=0;i<array1Size;i++){
        array3[i]=array1[i];}
    for(int i=0;i<array2Size;i++){
        array3[array1Size+i]=array2[i];}

    for(int k=0;k<array3Size;k++){
        printf("%d\t",array3[k]);
    }
    printf("\n");
    

}