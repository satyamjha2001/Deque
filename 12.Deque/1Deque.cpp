#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
    node(int data)
    {
        prev=NULL;
        item=data;
        next=NULL;
    }
};
class Deque
{
    private:
        node *front,*rear;
    public:
        Deque();
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        int getFront();
        int getRear();
        ~Deque();
        bool isEmpty();
};
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}
void Deque::insertFront(int data)
{
    node *n=new node(data);
    n->next=front;
    if(rear==NULL)
        rear=n;
    if(front!=NULL)
        front->prev=n;
    front=n;
}
void Deque::insertRear(int data)
{
    node *n=new node(data);
    n->prev=rear;
    if(front==NULL)
        front=n;
    if(rear!=NULL)
        rear->next=n;
    rear=n;
}
void Deque::deleteFront()
{
    if(front!=NULL)
    {
        if(front->next==NULL)
        {
            delete front;
            front=rear=NULL;
        }
        else
        {
        node *temp=front;
        front=front->next;
        front->prev=NULL;
        delete temp;
        }
    }
}
void Deque::deleteRear()
{
    if(rear)
    {
        if(rear->prev==NULL)
        {
            delete rear;
            front=rear=NULL;
        }
        else
        {
            node *temp=rear;
            rear=rear->prev;
            rear->next=NULL;
            delete temp;
        }
    }
}
int Deque::getFront()
{
    if(front==NULL)
        throw 1;
    return front->item;
}
int Deque::getRear()
{
    if(rear==NULL)
        throw 1;
    return rear->item;
}
Deque::~Deque()
{
    while(front)
        deleteFront();
}
bool Deque::isEmpty()
{
    return front==NULL;
}
int main() {

return 0;
}