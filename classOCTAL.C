#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
class OCTAL
{
    int x;
    int sum = 0;

public:
    OCTAL(int y)
    {
        x = y;
        while (y > 0)
        {
            y %= 10;
            if (y > 7)
            {
                cout << "\nINVALID INPUT\n";
                break;
            }
            y /= 10;
        }
    }
    int operator+(int);
    void operator<<(OCTAL);
    //~OCTAL();
};
void OCTAL::operator<<(OCTAL k)
{
    cout << sum;
}

int OCTAL::operator+(int k)
{
    int y = k;
    while (y > 0)
    {

        if (y % 10 > 7)
        {
            cout << "\nINVALID INPUT\n";
            return 0;
            break;
        }
        y /= 10;
    }
    int s = x;
    y = k;
    int a[SIZE] = {0};
    int b[SIZE] = {0};
    for (int i = SIZE - 1; i > 0; i--)
    {
        a[i] = s % 10;
        b[i] = y % 10;
        s = (s > 0) ? s / 10 : 0;
        y = (y > 0) ? y / 10 : 0;
    }
    /*for(int i=0;i<SIZE;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<SIZE;i++)
    cout<<b[i]<<" ";
    cout<<endl;*/

    int z[SIZE] = {0};
    int carry = 0;
    for (int i = SIZE - 1; i > 0; i--)
    {

        z[i] = a[i] + b[i] + carry;
        carry = 0;
        if (z[i] > 7)
        {
            while (z[i] > 7)
            {
                z[i] -= 8;
                carry++;
            }
        }
    }
    /*for(int i=0;i<SIZE;i++)
    cout<<z[i]<<" ";
    cout<<endl;
    cout<<sum;*/
    for (int i = 0; i < SIZE; i++)
    {
        sum += z[i];
        sum *= 10;
    }
    sum /= 10;
    // cout<<sum;
    return sum;
}
int main()
{
    OCTAL h = 635;   // Enter Octal Number Strictly
    int y = h + 232; // Add Octal Number Strictly
    // cout<<y;
    h << h;
}