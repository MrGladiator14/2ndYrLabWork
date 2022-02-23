#include <bits/stdc++.h>
using namespace std;
template <class t>
class QUEUE
{
    int front, rear, size;
    t *queue;

public:
    QUEUE(int s)
    {
        size = s;
        front = rear = 0;
        queue = new t;
    }
    void enQueue(t data)
    {
        if (size == rear)
            return;
        else
        {
            queue[rear] = data;
            rear++;
        }
        cout<<"\nenQueue Successful\n";
        return;
    }
    void deQueue()
    {
        if (front == rear)
        {
            cout << "EMPTY\n";
            return;
        }
        else
        { // shifting elements to left
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
        cout<<"\ndeQueue Successful\n";
        return;
    }
    void display()
    {
        int i;
        if (front == rear)
            return;
        for (i = front; i < rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
        return;
    }
};
/*void QUEUE :: enQueue(t data)
    {
        if (size == rear)
            return;
        else {
            queueI[rear] = data;
            rear++;
        }
        return;
    }

void QUEUE :: deQueue()
    {
        if (front == rear) {
            cout<<"EMPTY\n";
            return;
        }
        else {//shifting elements to left
            for (int i = 0; i < rear - 1; i++) {
                queueI[i] = queueI[i + 1];
            }
            rear--;
        }
        return;
    }
    void QUEUE :: display()
    {
        int i;
        if (front == rear)
            return;
                for (i = front; i < rear; i++) {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
        return;
    }
*/
int main(void)
{
    QUEUE<int> q(4);
    q.display();
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.display();
    q.enQueue(60);
    q.display();
    q.deQueue();
    q.deQueue();
    q.display();
    QUEUE<double> q1(4);
    q1.display();
    q1.enQueue(2.023);
    q1.enQueue(3.023);
    q1.enQueue(4.023);
    q1.enQueue(5.023);
    q1.display();
    q1.enQueue(6.023);
    q1.display();
    q1.deQueue();
    q1.deQueue();
    q1.display();
    return 0;
}
