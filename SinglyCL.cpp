//////////////////////////////////////////////////////////////////
// Singly Circular Linked List 
/////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template <class T>

struct nodeSC
{
    T data;
    struct nodeSC* next;
};

template <class T>
class SinglyCL
{
    public:
        struct nodeSC<T> * First;
        struct nodeSC<T> * Last;
        int iCount;

        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First=NULL;
    Last=NULL;
    iCount=0;
}

template <class T>
void SinglyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}


template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeSC<T> * newn=NULL;
    newn=new nodeSC<T>;

    newn->data=No;
    newn->next=NULL;

    if((First==NULL) && (Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
    Last->next=First;
     iCount++;
}


template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn=NULL;
    newn=new nodeSC<T>;

    newn->data=No;
    newn->next=NULL;

    if((First==NULL) && (Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
       Last->next=newn;
       Last=newn;
    }
    Last->next=First;
     iCount++;
}


template <class T>
void SinglyCL<T>::DeleteFirst()
{
    struct nodeSC<T> * temp=NULL;

    if((First==NULL) && (Last==NULL))
    {
        cout<<"LL is Empty";
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        temp=First;
        First=First->next;
        delete temp;
    }
    Last->next=First;

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSC<T> * temp=NULL;

    if((First==NULL) && (Last==NULL))
    {
        cout<<"LL is Empty";
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        temp=First;
        First=First->next;
        delete temp;
    }
    Last->next=First;
    
    iCount--;
}


template <class T>
void SinglyCL<T>::InsertAtPos(T No,int iPos)
{
    struct nodeSC<T> * newn=NULL;
    struct nodeSC<T> * temp=NULL;
    int i=0;

    if((iPos<1) && (iPos>iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(No,iPos);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(No,iPos);
    }
    else
    {
        temp=First;

        newn=new nodeSC<T>;
        newn->data=No;
        newn->next=NULL;

        for(i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        Last->next=First;

    }

}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeSC<T> * newn=NULL;
    struct nodeSC<T> * temp1=NULL;
    struct nodeSC<T> * temp2=NULL;
    int i=0;

    if((iPos<1) && (iPos>iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1=First;

        for(i=1;i<iPos-1;i++)
        {
            temp1=temp1->next;
        }
        
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        Last->next=First;
    }
}

int main()
{

    SinglyCL <int> *iobj=new SinglyCL<int>();
    int iRet=0;

   iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);
    
    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();

    iobj->DeleteAtPos(5);
    
    iobj->Display();
    iRet = iobj->Count();
    
    return 0;
}