#include<iostream>
using namespace std;
int main(){
    int a[15],s;
    float avg=0;
    cout<<"enter array size(<15)\t";
    cin>>s;
    cout<<"\nenter array:\t";
    for(int i=0;i<s;i++){
        cin>>a[i];
        avg+=a[i];
    }
    avg/=s;
    cout<<"average elements is:\t"<<avg;
return 0;} // namespace std
