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
void insert_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    
}
void insert_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        insert_head(head,val);
        return;
    }
    else{
        Node*tmp=head;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next = newNode;
    }
    
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
void delete_node(Node *&head, int index)
{
    if(index>=size(head))
    {
        return;
    }
    else if(index==0)
    {
        Node *tmp= head;
        head=head->next;
        delete tmp;
        return;
    }
    Node *tmp = head;
    for (int i = 1; i <= index-1; i++)
    {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
    return;
    
}
void print_linked_list(Node *&head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    int q;
    cin>>q;
    while(q--)
    {
        int x, v;
        cin>>x>>v;
        if(x==0)
        {
            insert_head(head,v);
        }
        else if(x==1)
        {
            insert_tail(head,v);
        }
        else
        {
            delete_node(head,v); 
        }
        print_linked_list(head); 
    }
    
    return 0;
}