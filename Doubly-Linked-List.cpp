
/*
||-----------------------------------||
||        Rahat Khan Pathan          ||
||      BGC Trust University         ||
||       Department of CSE           ||
||-----------------------------------||
*/
#include<bits/stdc++.h>
#define ll long long int
#define pub push_back
#define pob pop_back
#define PI 3.14159265359
#define vll vector<ll>
#define All(X) (X).begin(),(X).end()
#define Unique(X) (X).erase(unique(All(X)),(X).end())
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pi pair<ll,ll>
#define vpair vector<pair<ll,ll> >
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define minus cout<<-1<<endl
#define MAX 100000
using namespace std;
// create a node
template<typename T>
class List
{
public:
    T data;
    List<T>* next;
    List<T>* prev;
    List(T data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
// insert node at the end
template<typename T>
List<T>* ListInsert(List<T>* head,T data)
{
    if(head==NULL)
    {
        head=new List<T>(data);
    }
    else
    {
        List<T>* tmp=head;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=new List<T>(data);
        tmp->next->prev=tmp;
    }
    return head;
}
// insert node at nth position
template<typename T>
List<T>* ListInsert(List<T>* head,T data,int pos)
{
    List<T>* tmp=head;
    if(pos==0)
    {
        head=new List<T>(data);
        head->next=tmp;
        if(head->next!=NULL) head->next->prev=head;
    }
    else
    {
        pos--;
        while(pos--)
        {
            if(tmp==NULL) return head;
            tmp=tmp->next;
        }
        if(tmp==NULL) return head;
        List<T>* tmp2=tmp->next;
        tmp->next=new List<T>(data);
        tmp->next->next=tmp2;
        tmp->next->prev=tmp;
        if(tmp->next->next!=NULL) tmp->next->next->prev=tmp->next;
    }
    return head;
}
// delete the last node
template<typename T>
List<T>* ListDelete(List<T>* head)
{
    if(head==NULL) return NULL;
    else
    {
        List<T>* tmp=head;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        if(tmp->prev!=NULL) tmp->prev->next=NULL;
        else return NULL;
        delete tmp;
    }
    return head;
}
// delete nth node
template<typename T>
List<T>* ListDelete(List<T>* head,int pos)
{
    List<T>* tmp=head;
    if(head==NULL) return NULL;
    if(pos==0)
    {
        tmp=tmp->next;
        if(tmp!=NULL) tmp->prev=NULL;
        delete head;
        return tmp;
    }
    else
    {
        while(pos--)
        {
            if(tmp==NULL) return head;
            tmp=tmp->next;
        }
        if(tmp==NULL) return head;
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        delete tmp;
    }
    return head;
}
// print the list
template<typename T>
void ListPrint(List<T>* head)
{
    List<T>* tmp=head;
    if(head==NULL) return;
    while(tmp->next!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<tmp->data<<endl;
    while(tmp->prev!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->prev;
    }
    cout<<tmp->data<<endl;
}
// reverse the linked list iteratively
template<typename T>
List<T>* ListReverse(List<T>* head)
{
    List<T>* tmp=head;
    List<T>* next=NULL;
    List<T>* prev=NULL;
    while(tmp!=NULL)
    {
        head=tmp;
        next=tmp->next;
        prev=tmp->prev;
        tmp->next=prev;
        tmp->prev=next;
        tmp=next;
    }
    return head;
}
// reverse the list using recursion
template<typename T>
List<T>* ListReverseRecursion(List<T>* head,List<T>* p)
{
    if(head==NULL) return head;
    if(p->next==NULL)
    {
        List<T>* prev=p->prev;
        List<T>* next=p->next;
        p->next=prev;
        p->prev=next;
        head=p;
        return head;
    }
    head=ListReverseRecursion(head,p->next);
    List<T>* prev=p->prev;
    List<T>* next=p->next;
    p->next=prev;
    p->prev=next;
    return head;
}
void solve()
{
    List<int>*head=new List<int>(2);
    ListInsert(head,5);
    ListInsert(head,10);
    head=ListInsert(head,20,0);
    head=ListDelete(head);
    head=ListDelete(head);
    head=ListDelete(head);
    head=ListDelete(head);
    head=ListDelete(head);
    head=ListInsert(head,20);
    head=ListDelete(head,1);
    head=ListInsert(head,40,1);
//    head=ListInsert(head,10,1);
//    head=ListInsert(head,10);
//    head=ListReverse(head);
    head=ListReverseRecursion(head,head);
    ListPrint(head);
}
int main()
{
    fast;
    solve();
    return 0;
}
