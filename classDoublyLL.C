#include <bits/stdc++.h>
using namespace std;
class NODE
{
public:
    int data;
    NODE *next;
    NODE *prev;
    NODE(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    NODE()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DLIST
{
    NODE *front;
    bool search(int *arr, int s, int n)
    {

        for (int i = 0; i < s; i++)
        {
            if (arr[i] == n)
            {

                return true;
            }
        }

        return false;
    }

public:
    DLIST()
    {
        front = NULL;
    }
    DLIST operator+(int k)
    {
        NODE *temp = new NODE(k);
        temp->next = NULL;
        temp->prev = NULL;
        if (front == NULL)
        {
            front = temp;
        }
        else
        {
            front->prev = temp;
            temp->next = front;
            front = temp;
            front->prev = NULL;
        }
        return *this;
    }
    DLIST operator-(int i)
    {
        NODE *k = front;
        if (front->data == i)
        {
            cout << "element " << i << " deleted.\n";
            front = front->next;
            front->prev = NULL;
            delete (k);
            return *this;
        }
        NODE *l = k->next;
        while (l != NULL && l->data != i)
        {
            k = k->next;
            l = l->next;
        }
        if (l == NULL)
        {
            cout << "element not present\n";
        }
        else
        {
            cout << "element " << i << " deleted.\n";
            k->next = l->next;
            l->prev = k;
        }
        delete k;
        delete l;
        return *this;
    }
    bool operator==(DLIST l)
    {
        NODE *temp1 = front;
        NODE *temp2 = l.front;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == NULL && temp2 == NULL)
            return true;
        return false;
    }
    DLIST operator--(int i)
    {
        NODE *temp1 = front;
        int j = 0;
        int *arr = new int[100];
        while (temp1 != NULL)
        {
            if (!search(arr, j + 1, temp1->data))
            {
                arr[j] = temp1->data;
                j++;
            }
            temp1 = temp1->next;
        }
        DLIST x;
        for (int i = j - 1; i >= 0; i--)
        {
            x = x + arr[i];
        }
        return x;
    }
    void operator>>(DLIST k)
    {
        NODE *temp1 = front;
        while (temp1 != NULL)
        {
            cout << temp1->data <<"\t";
            temp1 = temp1->next;
        }
        cout << endl;
    }
};
int main()
{
    DLIST L1;
    DLIST L2;
    L1 = L1 + 1;
    L1 = L1 + 2;
    L1 = L1 + 3;
    L1 = L1 + 4;
    L2 = L2 + 1;
    L2 = L2 + 2;
    L2 = L2 + 3;
    L2 = L2 + 4;
    L1 >> L1;
    L2 >> L2;
    L2 = L2 + 5;
    L2 >> L2;
    if (L1 == L2)
        cout << "same\n";
    else
        cout << "not same\n";
    L2 = L2 - 5;
    if (L1 == L2)
        cout << "same\n";
    else
        cout << "not same\n";
    L2 >> L2;
    L2 = L2 + 1;
    L2 = L2 + 2;
    L2 = L2 + 3;
    L2 = L2 + 4;
    L2 >> L2;
    L2 = L2--;
    L2 >> L2;
    return 0;
}