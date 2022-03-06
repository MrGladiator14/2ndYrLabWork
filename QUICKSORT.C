#include <bits/stdc++.h>
using namespace std;
template <class t>
t partition(t a[], int st, int end)
{

    t pivot = a[st];

    int count = 0;
    for (int i = st + 1; i <= end; i++)
    {
        if (a[i] <= pivot)
            count++;
    }

    int pivotIndex = st + count;
    swap(a[pivotIndex], a[st]);

    int i = st, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(a[i++], a[j--]);
        }
    }

    return pivotIndex;
}
template <class t>
void quickSort(t a[], int st, int end)
{

    if (st >= end)
        return;

    int p = partition(a, st, end);

    quickSort(a, st, p - 1);

    quickSort(a, p + 1, end);
}

int main()
{

    int arr1[] = {10, 3, 32, 6, 7, 9};
    int n = 6;
    double arr2[] = {0.9, 3.0, 4.9, 2.2, 1.9, 8.4};
    quickSort(arr1, 0, n - 1);
    quickSort(arr2, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << "\t";
    }

    return 0;
}
