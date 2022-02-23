#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct Student
{
    int RollNo = 0, mk1 = 0, mk2 = 0, mk3 = 0;
    string Name;
} STUDENT[10];

float averageMarks(struct Student a)
{
    int k = (a.mk1 <= a.mk2) ? (a.mk1 <= a.mk3) ? a.mk1 : a.mk3 : a.mk2;
    return (a.mk1 + a.mk3 + a.mk2 - k) / 2.0;
}

void input(struct Student s[], int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << "student " << i + 1 << " details" << endl;
        cout << "enter name\t";
        cin >> s[i].Name;
        cout << "enter RollNo\t";
        cin >> s[i].RollNo;
        cout << "enter marks in subject1\t";
        cin >> s[i].mk1;
        cout << "enter marks in subject2\t";
        cin >> s[i].mk2;
        cout << "enter marks in subject3\t";
        cin >> s[i].mk3;
    }
}
void output(struct Student s[], int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << "student " << x + 1 << " results" << endl;
        cout << "Name:\t" << s[i].Name << endl;
        cout << "RollNo:\t" << s[i].RollNo << endl;
        cout << "BetterMarks Avg:\t" << averageMarks(s[i]) << endl;
    }
}
int main()
{
    int n;
    cout << "enter number of students:\t";
    cin >> n;
    input(STUDENT, n);
    output(STUDENT, n);

    return 0;
}