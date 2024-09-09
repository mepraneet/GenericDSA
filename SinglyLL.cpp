//////////////////////////////////////////////////////////////////
// Singly Linear Linked List 
/////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
    public:
        PNODE First;
        int iCount;

        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL()
{
    First=NULL;
    iCount=0;
}

void SinglyLL::Display()
{
    PNODE temp=First;

    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
int SinglyLL::Count()
{
    return iCount;
}

void SinglyLL::InsertFirst(int No)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=No;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
     iCount++;
}
void SinglyLL::InsertLast(int No)
{
    PNODE newn=NULL;
    PNODE temp=NULL;

    newn=new NODE;

    newn->data=No;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
       temp=First;

       while(temp->next!=NULL)
       {
        temp=temp->next;
       }
       temp->next=newn;
    }
     iCount++;
}
void SinglyLL::InsertAtPos(int No, int iPos)
{
    PNODE newn=NULL;
    PNODE temp=NULL;

    int i=0;

    if((iPos<1) || (iPos>iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp=First;
        newn= new NODE;
        newn->data=No;
        newn->next=NULL;

        for(i=1; i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        iCount++;
    }
}

void SinglyLL::DeleteFirst()
{
    PNODE temp=NULL;

    if(First==NULL)
    {
        cout<<"LL is Empty";
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        temp=First;
        First=First->next;
        delete temp;
    }
    iCount--;
}
void SinglyLL::DeleteLast()
{
    PNODE temp=NULL;
    
    if(First==NULL)
    {
        cout<<"LL is Empty";
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        temp=First;
        
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    iCount--;
}
void SinglyLL::DeleteAtPos(int iPos)
{
    PNODE temp1=NULL;
    PNODE temp2=NULL;

    int i=0;

    if((iPos<1) || (iPos>iCount))
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

        for(i=1; i<iPos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        iCount--;
    }
}

int main()
{
    SinglyLL obj;
    int iRet=0;

    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj.InsertLast(201);
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj.InsertAtPos(30,3);
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj.DeleteAtPos(3);
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj.DeleteFirst();
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj.DeleteLast();
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;



    return 0;
}