#include<iostream>
using namespace std;
int duplicate(int a[15],int size){
    int c=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
            c++;
            break;}
        }
    }
    return c;
}
int main(){
    int a[15];
    int s;
    cout<<"enter array size(<15)\t";
    cin>>s;
    cout<<"enter array:\t";
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    cout<<"number of duplicates:\t"<<duplicate(a,s);
return 0;} // namespace std