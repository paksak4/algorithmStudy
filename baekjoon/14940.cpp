#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int board[1000][1000];
int dist[1000][1000] = {0,}; // 거리
int visit[1000][1000] = {0,}; // 방문 

int main(void)
{
    int n, m;
    cin>>n>>m;

    queue<pair<int, int>> que;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
            if(board[i][j]==2)
            {
                que.push({i,j});
                visit[i][j] = 1;
            }   
        }
    }

    while(!que.empty())
    {
        pair<int, int> p = que.front();
        que.pop();
        
        for(int i=0; i<4; i++)
        {
            if(p.first+dx[i]<0 || p.first+dx[i]>=n || p.second+dy[i]<0 || p.second+dy[i]>=m)
                continue;
            if(visit[p.first+dx[i]][p.second+dy[i]]!=0)
                continue;
            
            visit[p.first+dx[i]][p.second+dy[i]] = 1;
            if(board[p.first+dx[i]][p.second+dy[i]]==1)
            {
                que.push({p.first+dx[i], p.second+dy[i]});
                dist[p.first+dx[i]][p.second+dy[i]] = dist[p.first][p.second]+1;
                
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visit[i][j]==0 && board[i][j]==1)
            {
                dist[i][j]=-1;
            }
            cout<<dist[i][j] << " ";
        }
        cout<<"\n";
    }

    return 0;
}