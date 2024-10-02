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
vector<int> v;
void print_leaf(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
       v.push_back(root->val);
    }
    print_leaf(root->left);
    print_leaf(root->right);

}

vector<int> print_leaf_reverse(Node*root)
{
    print_leaf(root);
    reverse(v.begin(), v.end());
    return v;

}
    
int main()
{
    Node* root = input_tree();
    vector<int> v = print_leaf_reverse(root);
    for (int val : v) 
    {
        cout << val << " ";
    }
    cout<<endl;
    return 0;
}