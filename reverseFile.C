#include <iostream>
#include <conio.h>
#include<string.h>
#include <fstream>
 
using namespace std;
 
int main()
{
   char ch;
   string word;
   ifstream in ("file67.txt");
   in.seekg(0,ios::end);
   int size=in.tellg();
 
      for (int j=1; j<=size; j++)
        { in.seekg(-j, ios::end);
          ch=in.get();
          if(ch!=' '){
                word+=ch;
            }
          else{
                int n = word.length();
                for (int i = 0; i < n / 2; i++)
                swap(word[i], word[n - i - 1]);
                cout<<word<<" ";
                if(j!=size)
                    word="";
            }
          
        }
    cout<<word<<" ";
    in.close();
    getch();
    return 0;
}