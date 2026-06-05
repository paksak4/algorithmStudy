#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    vector<char> board;
    string s;
    cin>>s;
    for(char c : s)
        board.push_back(c);

    for(int i=0; i<s.size(); )
    {
        if(i+3<s.size() && board[i]=='X' && board[i+1]=='X' && board[i+2]=='X' && board[i+3]=='X')
        {
            board[i]=board[i+1]=board[i+2]=board[i+3]='A';
            i+=4;
        }
        else if(i+1<s.size() && board[i]=='X' && board[i+1]=='X')
        {
            board[i]=board[i+1]='B';
            i+=2;
        }
        else 
            i++;
    }

    for(char c : board)
        if(c=='X')
        {    
            cout<<"-1";
            return 0;
        }

    for(char c:board)
        cout<<c;

    return 0;
}