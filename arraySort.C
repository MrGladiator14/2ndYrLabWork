#include<iostream>
using namespace std;
void bubbleSort(double a[15],int size){
    int i, j;
    for (i = 0; i < size-1; i++)      
         {for (j = 0; j < size-i-1; j++) 
           {if (a[j] > a[j+1])
              {a[j]=a[j+1]+a[j];
              a[j+1]=a[j]-a[j+1];
              a[j]=a[j]-a[j+1];}}}
}
int main(){
    double a[15];
    int s;
    cout<<"enter array size(<15)\t";
    cin>>s;
    cout<<"enter array:\t";
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    bubbleSort(a,s);
    cout<<"sorted array:\t";
    for(int i=0;i<s;i++)
        cout<<a[i];
return 0;}