#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
    deque<char> left;
    deque<char> right;

    string input;
    cin>>input;
   
    for(char c : input)
    {
        left.push_back(c);
    }

    int t;
    cin>>t;

    while(t-->0)
    {
        char order;
        cin>>order;
        if(order=='P')
        {
            char letter;
            cin>>letter;
            left.push_back(letter);
        }
        else if(order=='L')
        {
            if(left.empty())
                continue;
            right.push_front(left.back());
            left.pop_back();
        }
        else if(order=='D')
        {
            if(right.empty())
                continue;
            left.push_back(right.front());
            right.pop_front();
        }
        else if(order=='B')
        {
            if(left.empty())
                continue;
            left.pop_back();
        }
    }

    for(char c : left)
        cout<<c;
    for(char c : right)
        cout<<c;

    return 0;
}