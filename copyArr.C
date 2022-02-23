#include<iostream>
using namespace std;
void copy(int a[15], int b[15],int size){
    for(int i=0;i<size;i++){
        b[i]=a[i];
    };
}
int main(){
    int a[15];
    int b[15];
    int s;
    cout<<"enter array size(<15)\t";
    cin>>s;
    cout<<"enter array:\t";
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    copy(a,b,s);
    cout<<"destination array:\t";
    for(int i=0;i<s;i++)
        cout<<b[i]<<"\t";
return 0;} // namespace std