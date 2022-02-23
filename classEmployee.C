#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class EMPLOYEE
{
    int employee_number;
    string employee_name;
    float basic, DA, IT, NET_salary;
    void printData();

public:
    void read();
    float netSalary();
};
void EMPLOYEE::read()
{
    cout << "enter name\t";
    cin >> (employee_name);
    cout << "enter number\t";
    cin >> employee_number;
    cout << "enter BASIC\t";
    cin >> basic;
    cout << endl;
}
float EMPLOYEE::netSalary()
{
    DA = 0.52 * basic;
    IT = 0.3 * (basic + DA);
    NET_salary = DA + basic - IT;
    printData();
    return NET_salary;
}
void EMPLOYEE::printData()
{
    cout << "employee name: " << employee_name << "\nemployee number: " << employee_number << "\nBASIC: " << basic << "\nDA: " << DA << "\nIT: " << IT << "\nNET_Salary: " << NET_salary << endl;
}

int main()
{
    int n = 1;
    cout << "enter number of employees:\t";
    cin >> n;
    EMPLOYEE obj[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Entry " << i + 1 << endl;
        obj[i].read();
        cout << "total salary: " << obj[i].netSalary() << "\n";
    }
    return 0;
}
