
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
    List(T data)
    {
        this->data=data;
        this->next=NULL;
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
    }
    return head;
}
// delete the last node
template<typename T>
List<T>* ListDelete(List<T>* head)
{
    if(head==NULL) return head;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        List<T>* tmp=head;
        while(tmp->next->next!=NULL)
        {
            tmp=tmp->next;
        }
        List<T>* tmp2=tmp->next;
        tmp->next=NULL;
        delete tmp2 ;
    }
    return head;
}
// delete nth node
template<typename T>
List<T>* ListDelete(List<T>* head,int pos)
{
    if(head==NULL) return head;
    List<T>* tmp=head;
    if(pos==0)
    {
        delete head;
        return tmp->next;
    }
    else
    {
        pos--;
        while(pos--)
        {
            if(tmp==NULL) return head;
            tmp=tmp->next;
        }
        List<T>* tmp2=tmp->next;
        tmp->next=tmp2->next;
        delete tmp2;
    }
    return head;
}
// print the list
template<typename T>
void ListPrint(List<T>* head)
{
    if(head==NULL) return;
    List<T>* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
// reverse the linked list iteratively
template<typename T>
List<T>* ListReverse(List<T>* head)
{
    if(head==NULL) return head;
    List<T>* tmp=head;
    List<T>* prev=NULL;
    while(tmp!=NULL)
    {
        head=tmp;
        List<T>* next=tmp->next;
        tmp->next=prev;
        prev=tmp;
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
        head=p;
        return head;
    }
    head=ListReverseRecursion(head,p->next);
    p->next->next=p;
    p->next=NULL;
    return head;
}
void solve()
{
    List<int>*head=new List<int>(2);
    head=ListInsert(head,5);
    head=ListInsert(head,10);
    head=ListInsert(head,20,0);
    head=ListDelete(head,0);
    head=ListDelete(head,0);
    head=ListDelete(head);
    head=ListDelete(head);
    head=ListDelete(head,0);
    head=ListDelete(head,1);
    head=ListInsert(head,10);
    head=ListInsert(head,20,1);
//    head=ListInsert(head,100,0);
//    head=ListReverse(head);
//    head=ListReverseRecursion(head,head);
    ListPrint(head);
}
int main()
{
    fast;
    solve();
    return 0;
}
