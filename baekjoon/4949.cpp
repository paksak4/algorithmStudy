#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    while(true)
    {
        string str;
        stack<char> stk;

        //cin>>str;
        getline(cin, str);
        //cout<<str;
        if(str == ".")
            break;

        for(char c : str)
        {
            if(c=='[' || c=='(')
            {
                stk.push(c);
            }
            else if(c==']')
            {
                if(!stk.empty() && stk.top()=='[')
                    stk.pop();
                else
                {
                    cout<<"no\n";
                    break;
                }
            }
            else if(c==')')
            {
                if(!stk.empty() && stk.top()=='(')
                    stk.pop();
                else
                {
                    cout<<"no\n";
                    break;
                }
            }
            else if(c=='.')
            {
                if(stk.empty())
                    cout<<"yes\n";
                else
                    cout<<"no\n";
            }
        }

    }

    return 0;
}