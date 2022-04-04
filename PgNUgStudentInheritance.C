#include <bits/stdc++.h>
using namespace std;
class STUDENT
{
protected:
    int USN, age;
    char name[10];
};
class PGSTUDENT : protected STUDENT
{
    int semester, fees, stipend;

public:
    PGSTUDENT()
    {
        cout << "\nenter PG student USN\t";
        cin >> USN;
        cout << "\nenter PG student name\t";
        cin >> name;
        cout << "\nenter PG student Age\t";
        cin >> age;
        cout << "\nenter semester\t";
        cin >> semester;
        cout << "\nenter fees\t";
        cin >> fees;
        cout << "\nenter stipend\t";
        cin >> stipend;
    }
    int Age()
    {
        return age;
    }
};

class UGSTUDENT : protected STUDENT
{
    int semester, fees, stipend;

public:
    UGSTUDENT()
    {
        cout << "\nenter UG student USN\t";
        cin >> USN;
        cout << "\nenter UG student name\t";
        cin >> name;
        cout << "\nenter UG student Age\t";
        cin >> age;
        cout << "\nenter semester\t";
        cin >> semester;
        cout << "\nenter fees\t";
        cin >> fees;
        cout << "\nenter stipend\t";
        cin >> stipend;
    }
    int Age()
    {
        return age;
    }
};
int main()
{
    int N;
    float avg1 = 0, avg2 = 0;
    cin >> N;
    PGSTUDENT ob1[N];
    UGSTUDENT ob2[N];
    for (int i = 0; i < N; i++)
    {
        avg1 += ob1[i].Age();
        avg2 += ob2[i].Age();
    }

    cout << avg1 / N << endl;
    cout << avg2 / N << endl;
    return 0;
}