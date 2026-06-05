#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct INFO
{
    int x, y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main(void)
{
    int n;
    cin>>n;
    char board[25][25];
    //bool visit[25][25]={false,};
    for(int i=0; i<n; i++)
    {    
        string str;
        cin>>str;
        for(int j=0; j<n; j++)
            board[i][j]=str[j];
    }

    int numV = 0; // 단지 수
    vector<int> numH; // 각 단지의 집 수

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]!='1')
                continue;
            numV++;
            queue<INFO> q;
            q.push({i, j});
            board[i][j]='0';
            int h = 0;
            while(!q.empty())
            {
                INFO C = q.front();
                q.pop();
                h++; // 집 수
                for(int k=0; k<4; k++)
                {
                    if(C.x+dx[k]>n-1 || C.x+dx[k]<0 || C.y+dy[k]>n-1 || C.y+dy[k]<0)
                        continue;
                    if(board[C.x+dx[k]][C.y+dy[k]]=='0')
                        continue;
                    board[C.x+dx[k]][C.y+dy[k]]='0';
                    q.push({C.x+dx[k], C.y+dy[k]});
                }
            }
            numH.push_back(h);
        }
    }
    
    cout<<numV<<"\n";
    sort(numH.begin(), numH.end());
    for(int n:numH)
        cout<<n<<"\n";

    return 0;
}