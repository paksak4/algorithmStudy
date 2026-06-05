#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    stack<int> stk;
    while(n--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;
            cin>>x;
            stk.push(x);
        }
        else if(t==2)
        {
            if(stk.empty())
                cout<<"-1\n";
            else
            {
                cout<<stk.top()<<"\n";
                stk.pop();
            }
        }
        else if(t==3)
        {
            cout<<stk.size()<<"\n";
        }
        else if(t==4)
        {
            if(stk.empty())
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if(t==5)
        {
            if(stk.empty())
                cout<<"-1\n";
            else
                cout<<stk.top()<<"\n";
        }
    }
    return 0;
}