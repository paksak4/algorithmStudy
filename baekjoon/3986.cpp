#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    int t;
    cin>>t;

    int total = 0;

    for(int i=0; i<t; i++)
    {
        string str;
        cin>>str;

        stack<char> stk;
        for(char c : str)
        {
            if(c=='A')
            {
                if(!stk.empty() && stk.top()=='A')
                    stk.pop();
                else
                    stk.push('A');
            }
            else if(c=='B')
            {
                if(!stk.empty() && stk.top()=='B')
                    stk.pop();
                else
                    stk.push('B');
            }
        }

        if(stk.empty())
            total++;

    }

    cout<<total;

    return 0;
}