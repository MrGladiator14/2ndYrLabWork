#include <bits/stdc++.h>
using namespace std;
class STRING
{
    string s;

public:
    STRING(string k)
    {
        s = k;
    }
    STRING(const STRING &a, const STRING &b)
    {
        s = a.s + b.s;
    }
    void operator<<(STRING);
    string operator+(STRING);
};
string STRING::operator+(STRING k)
{
    return s += k.s;
}
void STRING::operator<<(STRING k)
{
    cout << s;
}
int main()
{
    STRING s1("NIT ");
    STRING s2("GOA");
    STRING s3 = s1 + s2;
    s3 << s3;
    return 0;
}
