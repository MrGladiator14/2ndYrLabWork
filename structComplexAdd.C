#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef struct COMPLEX{
    float R,I;
}C;
C ADD (C a,C b){
    C sum;
    sum.R=a.R+b.R;
    sum.I=a.I+b.I;
    return sum;
}
C ADD (int a,C b){
    C sum;
    sum.R=a+b.R;
    sum.I=+b.I;
    return sum;
}
int main(){
    C a,b,sum1,sum2;
    a.R=2,a.I=4;
    b.R=1,b.I=3;
    sum1=ADD(a,b);
    sum2=ADD(5,b);
    cout<<"sum1: "<<sum1.R<<"+i"<<sum1.I<<endl;
    cout<<"sum2: "<<sum2.R<<"+i"<<sum2.I;
    return 0;
    }