#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    
    stack<int>st;
    queue<int> q;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    int flag=1;
    if(st.size()!=q.size())
    {
        flag=0;
    }
    while(!st.empty() && !q.empty())
    {
        if(st.top()!=q.front())
        {
            flag=0;
            break;
        }
        st.pop();
        q.pop();
    }
    if(flag==1)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}