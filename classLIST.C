#include <bits/stdc++.h>
using namespace std;
/*typedef struct LinkedList{
 int data;
    struct LinkedList*next;

}LIST;*/
class LIST
{
    int data;
    class LIST *next;
    class LIST *front;

public:
    LIST()
    {

        front->data = 0;
        front->next == NULL;
    }
    void operator>>(LIST);
    bool operator==(LIST);
    LIST operator+(int);
    LIST operator-(int);
    LIST operator--(int);
};
LIST LIST::operator+(int n)
{
    LIST x;
    LIST *k = (LIST *)malloc(sizeof(LIST));
    k->data = n;
    k->next = front;
    front = k;
    x.front = front;
    free(k);
    return x;
}
LIST LIST::operator-(int n)
{
    LIST x;
    LIST *k, *q;
    k = front;
    if (k->data == n)
    {
        front = k->next; //@start
        free(k);
    }
    else
    {
        while ((k != NULL) && (k->data != n))
        {
            q = k;
            k = k->next;
        }
        if (k->data == n)
        {
            q->next = k->next;
            free(k); //@ middle
        }
        else if (k == NULL)
        {
            cout << "\n\t No match :: Deletion failed \n\t";
        }
    }
    return x;
}
bool LIST::operator==(LIST o)
{
    int c = 0;
    LIST *k1, *k2;
    k1 = front;
    k2 = o.front;
    while ((k1 != NULL) && (k2 != NULL))
    {
        if (k1->data != k2->data)
        {
            c++;
            break;
        }
        else
        {
            k1 = k1->next;
            k2 = k2->next;
        }
    }
    if ((k1 == NULL) && (k2 == NULL) && (c == 0))
        return true;
    else
        return false;
}
void LIST::operator>>(LIST)
{
    LIST *p;
    p = front;
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
LIST LIST::operator--(int k)
{
    LIST x;
    LIST *p, *q, *r;
    int c;
    p = front;
    x = x + p->data;
    q = x.front;
    q = q->next;
    p = p->next;
    while (p != NULL)
    {
        c = 0;
        r = x.front;
        while (r != NULL)
        {
            if (p->data == r->data)
            {
                c++;
            }
            r = r->next;
        }
        if (c == 0)
        {
            q->data = p->data;
            q = q->next;
        }
        p = p->next;
    }
    q = NULL;
    return x;
}
int main()
{
    LIST L1, L2;
    L1 = L1 + 1;
    L2 = L2 + 1;
    L1 = L1 + 2;
    L2 = L2 + 2;
    L1 >> L1;
    L2 >> L2;
    if (L1 == L2)
    {
        cout << "Equivalent Lists\n";
    }
    else
    {
        cout << "Non-Equivalent Lists\n";
    }
    L1 = L1 + 1;
    L2 = L2 + 1;
    L1 >> L1;
    L2 >> L2;
    L2 = L2--;
    L2 = L2 - 2;
    L1 >> L1;
    L2 >> L2;
    return 0;
}