#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str;

int decode(int s)
{
    int total=0;
    for(int i=s; i<str.size(); i++)
    {
        if(str[i]=='/')
            continue;
        else if(str[i]==')')
        {    
            str[i]='/';
            return total;
        }
        else if(str[i+1]=='(')
        {
            str[i+1]='/';
            total+=((str[i]-48)*decode(i+1));
            str[i]='/';
        }
        else
        {
            str[i]='/';
            total++;
        }
    }
    return total;
}

int main(void)
{
    cin>>str;
    cout<<decode(0)<<"\n";
    //cout<<str;

    return 0;
}