#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

typedef struct
{
    int x, y, m;
    
} info;

int main(void)
{
    int r, c;
    cin >> r >> c;

    queue<info> jP; // j의 위치
    queue<info> fP; // 불의 위치

    char board[1000][1000];

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='J')
            {
                jP.push({i, j, 0});
            }
            if(board[i][j]=='F')
            {
                fP.push({i, j ,0});
            }
        }
    }

    //cout<<"\n";
    
    int t = 0;
    while(!jP.empty())
    {
        while(!jP.empty() && jP.front().m==t)
        {
            info jI = jP.front();
            jP.pop();
            if(board[jI.x][jI.y]=='J')
            {
                if(jI.x==0 || jI.x==r-1 || jI.y==0 || jI.y==c-1)
                {
                    cout<<jI.m+1;
                    return 0;
                }

                for(int i=0; i<4; i++)
                {
                    if(board[jI.x+dx[i]][jI.y+dy[i]]=='.')
                    {
                        board[jI.x+dx[i]][jI.y+dy[i]]='J';
                        jP.push({jI.x+dx[i], jI.y+dy[i], jI.m+1});
                    }
                }
            }
        }

        while(!fP.empty() && fP.front().m == t)
        {    
            info fI = fP.front();
            fP.pop();

            for(int i=0; i<4; i++)
            {
                if((fI.x+dx[i] >= 0 && fI.x+dx[i]<r) && (fI.y+dy[i]>=0 && fI.y+dy[i]<c) && (board[fI.x+dx[i]][fI.y+dy[i]]=='.' || board[fI.x+dx[i]][fI.y+dy[i]]=='J'))
                {
                    board[fI.x+dx[i]][fI.y+dy[i]]='F';
                    fP.push({fI.x+dx[i], fI.y+dy[i], fI.m+1});
                }
            }
        }  
        t++;
    }

    cout<<"IMPOSSIBLE";

    return 0;
}