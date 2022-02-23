#include<iostream>
using namespace std;
void matrixAdd(int a[15][15],int b[15][15],int d[15][15],int r,int c){
int i, j;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++)
        d[i][j] = a[i][j] + b[i][j];
    }
}
int main(){
    int a[15][15],b[15][15],d[15][15];
    int r,c;
    cout<<"enter matrix1 size(<15x15)\t";
    cin>>r>>c;
    cout<<"enter array:\t";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cin>>a[i][j];
    }
    cout<<"enter matrix2 size(<15x15)\t";
    cin>>r>>c;
    cout<<"enter array:\t";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cin>>b[i][j];
    }
    matrixAdd(a,b,d,r,c);
    cout<<"result:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cout<<d[i][j]<<" ";
        cout<<endl;
    }
return 0;}