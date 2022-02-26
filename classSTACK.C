#include <bits/stdc++.h>
using namespace std;
#define size 10
int top = -1;
class STACK
{
    int a[size] = {0};

public:
    /*STACK(){
        a[size]={0};
        cout<<" stack updated";

    }*/
    void operator<<(STACK);
    STACK operator+(int);
    STACK operator-();
};
STACK STACK::operator+(int k)
{
    STACK x;
    if (top == size - 1)
    {
        cout << "\nStack Overflow\n";
    }
    else
    {
        top++;
        a[top] = k;
        // cout<<"\nexecuted once";
    }
    for (int i = 0; i < size; i++)
        x.a[i] = a[i];
    return x;
}
void STACK::operator<<(STACK k)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}
STACK STACK::operator-()
{
    STACK x;
    if (top == -1)
        cout << "\nStack Underflow\n";
    else
    {
        a[top] = 0;
        top--;
    }
    for (int i = 0; i < size; i++)
        x.a[i] = a[i];
    return x;
}
int main()
{
    STACK s1;
    s1 = s1 + 1;
    s1 << s1;
    cout << endl;

    s1 = s1 + 1;
    s1 = s1 + 1;
    s1 << s1;
    cout << endl;

    s1 = s1 + 1;
    s1 << s1;
    cout << endl;

    s1 = -s1;
    s1 = s1 + 3;
    s1 << s1;
    cout << endl;

    return 0;
}
