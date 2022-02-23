#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template<class t>
void swAp(t &a,t &b){
    t temp=a;
    a=b;
    b=temp;
}
template <class x>
int partition(x arr[],int st,int end) // note:pvt=pivot!!
{

    x pvt = arr[st];

    int ct = 0;
    for (int i = st + 1; i <= end; i++)
    {
        if (arr[i] <= pvt)
            ct++;
    }

    int pvtIndex = st + ct;
    swAp(arr[pvtIndex], arr[st]);

    int i = st, j = end;

    while (i < pvtIndex && j > pvtIndex)
    {

        while (arr[i] <= pvt)
        {
            i++;
        }

        while (arr[j] > pvt)
        {
            j--;
        }

        if (i < pvtIndex && j > pvtIndex)
        {
            swAp(arr[i++], arr[j--]);
        }
    }
    return pvtIndex;
}

template <class y>
void Quicksort(y arr[], int st, int end)
{
    if (st >= end)
        return;
    int p = partition(arr,st,end);
    Quicksort(arr, st, p - 1);
    Quicksort(arr, p + 1, end);
    return;
}


int main()
{

    int arr1[] = {12, 23, 56, 56, 43};
    int n = 5;
    double arr2[] = {3.14, 1.123, 3.123, 5.123};
    int m = 4;
    Quicksort(arr1, 0, n-1);
    Quicksort(arr2, 0, m-1);
    cout<<"arr1\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << "\t";
    }
    cout<<"\narr2\n";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << "\t";
    }

    return 0;
}