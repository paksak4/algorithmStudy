#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;

vector<int> visit(n, 0); // 방문했는지
vector<vector<bool>> board(n, vector<bool>(n)); // 맵
queue<int> que;

int main(void)
{
    cin>>n>>m>>r;

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        board[x-1][y-1]=true;
    }
   
    que.push(r-1);
    int count=1;
    visit[r-1]=count++;
    while(!que.empty())
    {
        int t=que.front();
        que.pop();
        for(int i=n-1; i>=0; i--)
        {
            if(board[t][i]&&visit[i]==0)
            {
                que.push(i);
                visit[i]=count++;
            }
        }
    }
    for(int i:visit)
        cout<<i<<"\n";

    return 0;
}