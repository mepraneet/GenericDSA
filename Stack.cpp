#include<iostream>
using namespace std;

template <class T>
struct nodeStack
{
    T data;
    struct nodeStack *next;
};

template <class T>
class Stack
{
    private:
        struct nodeStack<T> *  First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  // InsertFirst()
        int Pop();   // DeleteFirst()
};


template <class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}


template <class T>
void Stack <T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeStack<T> *  temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Stack <T>::Count()
{
    return iCount;
}


template <class T>
void Stack <T>::Push(T No)
{
    struct nodeStack<T> *  newn = NULL;

    newn = new nodeStack<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}


template <class T>
int Stack <T>::Pop()
{
    int iValue = 0;
    struct nodeStack<T> *  temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
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
    Stack<int> *iobj = new Stack<int>();

    int iRet = 0;

    iobj->Push(10);
    iobj->Push(20);
    iobj->Push(30);
    iobj->Push(40);

    iobj->Display();

    iRet = iobj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    iRet = iobj->Pop();

    cout<<"Poped element is : "<<iRet<<"\n";

    iRet = iobj->Pop();

    cout<<"Poped element is : "<<iRet<<"\n";
    
    iobj->Display();

    iRet = iobj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    iobj->Push(50);

    iobj->Display();

    iRet = iobj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    return 0;
}