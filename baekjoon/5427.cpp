#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

typedef struct
{
    int x, y, m; // x, y좌표, 움직인칸
} info;

int main(void)
{
    int t;
    cin>>t;

    while(t--)
    {
        int w,h; // 너비, 높이
        cin>>w>>h;

        queue<info> sQue; // 상근이 위치 큐
        queue<info> fQue; // 불 위치 큐

        char board[1000][1000]; // 보드판
        int n=0; // n번째 움직임을 의미

        for(int i=0; i<h; i++)
        {
            //cout<<"입력해라: ";
            string str;
            cin>>str;
            for(int j=0; j<w; j++)
            {
                board[i][j] = str[j];
                if(board[i][j]=='@')
                    sQue.push({i, j, n});
                else if(board[i][j]=='*')
                    fQue.push({i, j, n});
            }
        }

        // cout<<"\n";

        // for(int i=0; i<h; i++)
        // {
        //     for(int j=0; j<w; j++)
        //     {
        //         cout<<board[i][j];
        //     }
        //     cout<<"\n";
        // }

        // cout<<"\n";

        if((sQue.front().x==0 || sQue.front().x==h-1) && (sQue.front().y==0 || sQue.front().y==w-1))
        {
            cout<<n+1<<"\n";
            continue;
        }

        //cout<<"옴1\n";

        bool escape = false; // 탈출했는지

        while(!sQue.empty() && !escape)
        {
            while(!fQue.empty() && fQue.front().m == n)
            {
                info c = fQue.front();
                fQue.pop();

                for(int i=0; i<4; i++)
                {
                    if(c.x+dx[i] > h-1 || c.x+dx[i] < 0 || c.y+dy[i] > w-1 || c.y+dy[i] < 0)
                        continue;
                    if(board[c.x+dx[i]][c.y+dy[i]]=='*' || board[c.x+dx[i]][c.y+dy[i]]=='#')
                        continue;
                    fQue.push({c.x+dx[i], c.y+dy[i], c.m+1});
                    board[c.x+dx[i]][c.y+dy[i]]='*';
                }
            }

            while(!sQue.empty() && sQue.front().m == n && !escape)
            {
                info c = sQue.front();
                sQue.pop();

                for(int i=0; i<4; i++)
                {
                    if(c.x+dx[i] > h-1 || c.x+dx[i] < 0 || c.y+dy[i] > w-1 || c.y+dy[i] < 0)
                        continue;
                    if(board[c.x+dx[i]][c.y+dy[i]]!='.')
                        continue;
                    sQue.push({c.x+dx[i], c.y+dy[i], c.m+1});
                    board[c.x+dx[i]][c.y+dy[i]]='@';
                    if(c.x+dx[i]==0 || c.x+dx[i]==h-1 || c.y+dy[i]==0 || c.y+dy[i]==w-1)
                    {   
                        cout<<n+2<<"\n";
                        escape=true;
                        break;
                    }
                }
            }

            // for(int i=0; i<h; i++)
            // {
            //     for(int j=0; j<w; j++)
            //     {
            //         cout<<board[i][j];
            //     }
            //     cout<<"\n";
            // }

            // cout<<"\n";

            n++;
        }
        //cout<<"옴2\n";
        if(!escape)
            cout<<"IMPOSSIBLE\n";
    }

    return 0;
}