#include <iostream>

using namespace std;

int board[128][128];
int white = 0;
int blue = 0;

void rec(int rS, int rE, int cS, int cE) // 행과 열 시작, 끝
{
    bool isSame = true;
    for(int i=rS; i<rE; i++)
    {
        for(int j=cS; j<cE; j++)
        {
            if(board[i][j]!=board[rS][cS])
                isSame = false;
        }
    }

    if(isSame) // base
    {
        if(board[rS][cS]==0)
            white++;
        else
            blue++;
        return;
    }
    
    // 4등분
    rec(rS, (rS+rE)/2, cS, (cS+cE)/2); // 1
    rec((rS+rE)/2, rE, cS, (cS+cE)/2); // 3
    rec(rS, (rS+rE)/2, (cS+cE)/2, cE); // 2
    rec((rS+rE)/2, rE, (cS+cE)/2, cE); // 4

    return;
}

int main(void)
{
    int n;
    cin>>n; 

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>board[i][j];

    rec(0, n, 0, n);
    
    cout<<white<<"\n"<<blue;

    return 0;
}