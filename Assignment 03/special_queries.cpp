#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<string>que;
    int q;
    cin>>q;
    while(q--)
    {
        char com;
        cin>>com;
        if(com =='0')
        {
            string name;
            cin>>name;
            que.push(name);
        }
        else if(com=='1')
        {
            if(!que.empty())
            {
                cout<<que.front()<<endl;
                que.pop();
            }
            else{
                cout<<"Invalid"<<endl;
            }
        }
    }
    return 0;
}