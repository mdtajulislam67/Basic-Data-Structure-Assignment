#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
void print_left(Node* root)
{
    if(root->left)
    {
        print_left(root->left);
        cout << root->left->val << " ";
        return;
    }
    else if(root->right)
    {
        print_left(root->right);
        cout << root->right->val << " ";
        return;
    }

}

void print_right(Node* root)
{
    if(root->right)
    {
        cout << root->right->val << " ";
        print_right(root->right);
        
    }
    else if(root->left)
    {
        cout << root->left->val << " ";
        print_right(root->left);
        
    }
}

int main()
{
    Node *root = input_tree();
    if(root)
    {
        print_left(root->left);
        cout << root->val << " ";
    }
    else if(!root->left)
    {
        print_right(root->right);
        cout << root->val << " ";
    }
    else{
        print_left(root);
        cout << root->val << " ";
        print_right(root);
        
    }
    return 0;
}