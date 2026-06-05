#include <iostream>
#include <deque>
#include <string>

using namespace std;

// - < > 

int main(void)
{
    int t; 
    cin>>t;

    while(t-->0)
    {
        deque<char> left;
        deque<char> right;
        string input;
        cin>>input;

        for(char c : input)
        {
            if(c=='-')
            {
                if(!left.empty())
                {
                    left.pop_back();
                }
            }
            else if(c=='<')
            {
                if(!left.empty())
                {
                    right.push_front(left.back());
                    left.pop_back();
                }
            }
            else if(c=='>')
            {
                if(!right.empty())
                {
                    left.push_back(right.front());
                    right.pop_front();
                }
            }
            else
            {
                left.push_back(c);
            }
        }
        for(char c : left)
            cout<<c;
        for(char c : right)
            cout<<c;
        cout<<endl;
    }

    return 0;
}