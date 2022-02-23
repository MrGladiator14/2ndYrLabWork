#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef struct list
{
    int data;
    struct list *next;
}node;
class LIST{
    node*front=NULL;
    public:
        
        void create(int);
        void insert(int);
        void del();
        void display();
};
void LIST:: create(int a){
    front->data =a;
    front->next=NULL;
    cout<<"list created\n";
}

void LIST:: insert(int a){
        if(front==NULL){
{cout<<"create a lis\n";
return;
}
        }
        node*h=new node;
        cout<<"enter data\t";
        cin>>h->data;
        h->next=NULL;
            h->next=front;
            front=h;
        cout<<"insertion successful\n";}
    
void LIST:: del(){
    if(front==NULL)
    {cout<<"error\n";
    return;}
    int x=front->data;
    node*d=front;
    front=front->next;
    delete d;
    cout<<endl<< x<<" is deleted\n";
        cout<<"deletion successful\n";

}
void LIST:: display(){
    node*p=front;
    while(p->next!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
}
int main(){
    LIST obj1;
    LIST obj2;
    obj1.create(1);
    obj2.create(2);
    obj1.insert(1);
    obj2.insert(2);
    obj1.insert(1);
    obj2.insert(2);
    obj1.insert(1);
    obj2.insert(2);
    obj1.insert(1);
    obj2.insert(2);
    obj1.display();
    obj2.display();
    obj1.del();
    obj2.del();
    obj1.display();
    obj2.display();
return 0;
}