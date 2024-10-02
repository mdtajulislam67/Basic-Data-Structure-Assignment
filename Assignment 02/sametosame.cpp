#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
int size(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
void same_same(Node *head1,Node *head2)
{
    Node *tmp1 = head1;
    Node *tmp2 = head2;
    int flag=1;
    if(size(tmp1)!=size(tmp2))
    {
        flag=0;
    }
    while(tmp1!=NULL && tmp2!=NULL)
    {
        if(tmp1->val!=tmp2->val)
        {
            flag=0;
        }
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    if(flag==1)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head1, tail, val);
    }
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head2, tail, val);
    }
    same_same(head1,head2);
    return 0;
}