#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n-1][n-1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==n/2 && j==n/2)
            {
                cout<<"X";
            }
            else if(a[i]==a[j])
            {
                cout<<"\\";
            }
            else if(a[i]+[j]==n-1)
            {
                cout<<"/";
            }
            else{
                cout<<" ";
            }
        }
    }
    return 0;
}
