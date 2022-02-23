#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(int argv,char* argc[]){
    int i=1;
    char c;
    while(i<=argv)
    {FILE *fp1 = fopen(argc[i], "r");
    while ((c = fgetc(fp1)) != EOF)
	{fputc(c, stdout);
    
    }
    cout<<endl;
    i++;}
    return 0;
}