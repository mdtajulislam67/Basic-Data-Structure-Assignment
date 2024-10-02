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
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void remove(Node *&head)
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    Node *tmp= head;
    while(tmp!=NULL)
    {
        Node *newNode=tmp;
        while(newNode->next!=NULL)
        {
            if(newNode->next->val==tmp->val)
            {
                Node* delete_node=newNode->next;
                newNode->next=newNode->next->next;
                delete delete_node;
            }
            else{
                newNode=newNode->next;
            }
        }
        tmp=tmp->next;
    }
   
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }
    remove(head);
    print_linked_list(head);
    return 0;
}