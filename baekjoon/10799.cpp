#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    string str;
    cin>>str;

    stack<char> stk;
    int total=0;
    for(int i=0; i<str.size(); i++)
    {
        char c = str[i];
        if(c=='('&&str[i+1]==')')
        {
            total+=stk.size();
            i++;
        }
        else if(c=='(')
        {
            total++;
            stk.push('(');
        }
        else if(c==')')
            stk.pop();
    }
    cout<<total;
    return 0;
}