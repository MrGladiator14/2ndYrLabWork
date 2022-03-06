#include <bits/stdc++.h>
using namespace std;
class DATE
{
    int d = 0, m = 0, y = 0;
    int days();

public:
    DATE(int k)
    {
        return;
    }
    DATE()
    {

        cout << "enter date in 'dd/mm/yy' format\t";
        scanf("%d/%d/%d", &d, &m, &y);
        cout << endl;
    }

    DATE operator+(int);
    int operator-(DATE);
    void operator<<(DATE);
};
int DATE::days()
{
    int leapyr = 0, dayC = 0;
    for (int i = 0; i < y; i++) // counts leapyears from 0 AD
    {
        if (((i) % 4 == 0 && !((i) % 100 == 0)) || ((i) % 400 == 0))
            leapyr++;
    }
    for (int i = 0; i < m; i++) // counts days passed in the given year by months
    {
        if (m - 1 == 1 || m - 1 == 3 || m - 1 == 5 || m - 1 == 7 || m - 1 == 8 || m - 1 == 10)
        {
            dayC += 31;
            break;
        }
        if (m - 1 == 2)
        {
            dayC += 28;
            break;
        }
        else if (m - 1 != 0)
        {
            dayC += 30;
            break;
        }
    }
    if (m > 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) // checks if current year is a leap year and adds 29th Feb accordingly
    {
        return 1 + dayC + leapyr + (365 * y) + d;
    }
    else
        return dayC + leapyr + (365 * y) + d;
}

DATE DATE::operator+(int n)
{
    DATE x(0);
    x.d = d, x.y = y, x.m = m;
    for (int i = n; i > 0; i--)
    {
        x.d++;
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        {
            if (d > 29 && m == 2)
            {
                x.m++;
                x.d = 1;
            }
            else if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
            {
                x.d = 1;
                x.m++;
            }
            else if (d > 30 && !(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
            {
                x.m++;
                x.d = 1;
            }
            if (m > 12)
            {
                x.m = 1;
                x.y++;
            }
        }
        else
        {
            if (d > 28 && m == 2)
            {
                x.m++;
                x.d = 1;
            }
            else if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
            {
                x.m++;
                x.d = 1;
            }
            else if (d > 30 && !(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
            {
                x.m++;
                x.d = 1;
            }
            if (m > 12)
            {
                x.m = 1;
                x.y++;
            }
        }
    }

    return x;
}

int DATE::operator-(DATE o)
{
    int d1 = days();
    int d2 = o.days();
    return d1 - d2;
}
void DATE::operator<<(DATE k)
{
    cout << " date: ";
    printf("%d/%d/%d", d, m, y);
    cout << endl;
}

int main()
{
    // cout<<"choose proceed\n";
    DATE d1, d2;
    d1 << d1;
    d2 << d2;
    int noOfDays;
    noOfDays = d1 - d2;
    cout << "No_Of_Days = " << noOfDays << endl;
    // cout<<"choose skip\n";
    d2 = d1 + noOfDays;
    d1 << d1;
    d2 << d2;
    return 0;
}