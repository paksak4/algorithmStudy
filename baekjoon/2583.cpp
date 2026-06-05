#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[100][100]; // -1: 벽, 0: 아직 방문 x, 1: 방문함

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main(void)
{
    int m,n,k;
    cin>>m>>n>>k;

    for(int i=0; i<k; i++)
    {
        int x1, y1, x2, y2; // 좌하, 우상 좌표
        cin>>x1>>y1>>x2>>y2;
        for(int k=x1; k<x2; k++)
        {   
            for(int j=y1; j<y2; j++)
                board[j][k] = -1;
        }
    }

    vector<int> vec;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]!=0)
                continue;
            
            queue<pair<int, int>> que;
            int space = 0; // 공간 너비
            que.push({i, j});
            board[i][j]=1;
            space++;
            
            while(!que.empty())
            {
                pair<int, int> c = que.front(); // 현재 좌표
                que.pop();
                for(int k=0; k<4; k++)
                {
                    if(c.first+dx[k]>m-1 || c.first+dx[k]<0 || c.second+dy[k]>n-1 || c.second+dy[k]<0)
                        continue;
                    if(board[c.first+dx[k]][c.second+dy[k]]!=0)
                        continue;
                    
                    que.push({c.first+dx[k], c.second+dy[k]});
                    board[c.first+dx[k]][c.second+dy[k]]=1;
                    space++;
                }

            }
            if(space!=0)
            {    
                //cout<<space<<endl;
                vec.push_back(space);
            }
        }
    }

    sort(vec.begin(), vec.end());
    cout<<vec.size()<<"\n";
    for(int i:vec)
        cout<<i<<" ";

    return 0;
}