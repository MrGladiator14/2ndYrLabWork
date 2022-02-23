#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define c 3
void copy_ints(int a[], int size, int*b){
    for(int i=0;i<size;i++){
        b[i]=a[i];
    }
}
int main(){
    int a[]={1,2,3,4,5,6,7};
    int* b=new int[c];
    copy_ints(a,c,b);
    for(int i=0;i<c;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}