#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 5
struct EMPLOYEE
{
    int employee_number;
    string employee_name;
    float basic, DA, IT, NET_salary;
}a[N];
void read(int i)
{
    cout << "enter name\t";
    cin >> (a[i].employee_name);
    cout << "enter number\t";
    cin >> a[i].employee_number;
    cout << "enter BASIC\t";
    cin >> a[i].basic;
    cout << endl;
}
void printData(int i)
{
    cout << "employee name: " << a[i].employee_name << "\nemployee number: " << a[i].employee_number << "\nBASIC: " << a[i].basic << "\nDA: " << a[i].DA << "\nIT: " << a[i].IT << "\nNET_Salary: " << a[i].NET_salary << endl;
}
void netSalary(int i)
{
    a[i].DA = 0.52 * a[i].basic;
    a[i].IT = 0.3 * (a[i].basic + a[i].DA);
    a[i].NET_salary = a[i].DA + a[i].basic - a[i].IT;
    printData(i);
}
int main()
{
    struct EMPLOYEE a[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Entry " << i + 1 << endl;
        read(i);
        netSalary(i);
        cout<<"\n";
    }
    return 0;
}