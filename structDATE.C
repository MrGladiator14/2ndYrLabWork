#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct date //date structure
{
    int d = 0, m = 0, y = 0;
};

int days(struct date c)
{
    int leapyr = 0, dayC = 0;
    for (int i = 0; i < c.y; i++)//counts leapyears from 0 AD
    {
        if (((i) % 4 == 0 && !((i) % 100 == 0)) || ((i) % 400 == 0))
            leapyr++;
    }
    for (int i = 0; i < c.m; i++)//counts days passed in the given year by months
    {
        if (c.m - 1 == 1 || c.m - 1 == 3 || c.m - 1 == 5 || c.m - 1 == 7 || c.m - 1 == 8 || c.m - 1 == 10)
        {
            dayC += 31;
            break;
        }
        if (c.m - 1 == 2)
        {
            dayC += 28;
            break;
        }
        else if (c.m - 1 != 0)
        {
            dayC += 30;
            break;
        }
    }
    if (c.m > 2 && (c.y%4==0 && c.y%100!=0 || c.y%400==0))// checks if current year is a leap year and adds 29th Feb accordingly
    {
        return 1 + dayC + leapyr + (365 * c.y) + c.d;
    }
    else
        return dayC + leapyr + (365 * c.y) + c.d;
}

int Difference(struct date a, struct date b)
{
    int d1 = days(a);
    int d2 = days(b);
    return d1 - d2;
}

date Add_days(struct date c, int n)
{
    struct date d;
    d.m = c.m;
    d.y = c.y;
    d.d = c.d;
    for (int i = n; i > 0; i--)
    {
        d.d++;
        if (d.y % 4 == 0 && d.y % 100 != 0 || d.y % 400 == 0)
        {
            if (d.d > 29 && d.m == 2)
            {
                d.m++;
                d.d = 1;
            }
            else if (d.d > 31 && (d.m == 1 || d.m == 3 || d.m == 5 || d.m == 7 || d.m == 8 || d.m == 10 || d.m == 12))
            {
                d.d = 1;
                d.m++;
            }
            else if (d.d > 30 && !(d.m == 1 || d.m == 3 || d.m == 5 || d.m == 7 || d.m == 8 || d.m == 10 || d.m == 12))
            {
                d.m++;
                d.d = 1;
            }
            if (d.m > 12)
            {
                d.m = 1;
                d.y++;
            }
        }
        else
        {
            if (d.d > 28 && d.m == 2)
            {
                d.m++;
                d.d = 1;
            }
            else if (d.d > 31 && (d.m == 1 || d.m == 3 || d.m == 5 || d.m == 7 || d.m == 8 || d.m == 10 || d.m == 12))
            {
                d.m++;
                d.d = 1;
            }
            else if (d.d > 30 && !(d.m == 1 || d.m == 3 || d.m == 5 || d.m == 7 || d.m == 8 || d.m == 10 || d.m == 12))
            {
                d.m++;
                d.d = 1;
            }
            if (d.m > 12)
            {
                d.m = 1;
                d.y++;
            }
        }
    }
    return d;
}
int main()
{
    struct date date1, date2;
    cout << "enter date 1 in dd/mm/yyyy format\t";
    cin >> date1.d >> date1.m >> date1.y;
    cout << "enter date 2 in dd/mm/yyyy format\t";
    cin >> date2.d >> date2.m >> date2.y;
    int No_of_days = Difference(date1, date2);
    cout << "No_of_days = " << No_of_days << endl;
    int n;
    cout << "enter number of days\t";
    cin >> n;
    date2 = Add_days(date1, n);
    cout << "date1 after adding days is\t";
    cout << date2.d << " " << date2.m << " " << date2.y;
}