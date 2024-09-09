#include<iostream>
using namespace std;

template <class T>
struct nodeQueue
{
    T data;
    struct nodeQueue *next;
};


template <class T>
class Queue
{
    private:
        struct nodeQueue<T>* First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  // InsertLast()
        int DeQueue();   // DeleteFirst()
};


template <class T>
Queue<T>:: Queue()
{
    First = NULL;
    iCount = 0;
}


template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQueue<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}


template <class T>
int Queue<T>::Count()
{
    return iCount;
}


template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQueue<T>* newn = NULL;
    struct nodeQueue<T>* temp = NULL;

    newn = new nodeQueue<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}


template <class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQueue<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}

int main()
{
    Queue<int> *iobj = new Queue<int>();
    int iRet = 0;

    iobj->EnQueue(10);
    iobj->EnQueue(20);
    iobj->EnQueue(30);
    iobj->EnQueue(40);

    iobj->Display();

    iRet = iobj->Count();

    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    iRet = iobj->DeQueue();

    cout<<"Removed element is : "<<iRet<<"\n";

    iRet = iobj->DeQueue();

    cout<<"Removed element is : "<<iRet<<"\n";
    
    iobj->Display();

    iRet = iobj->Count();

    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    iobj->EnQueue(50);

    iobj->Display();

    iRet = iobj->Count();

    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    return 0;
}