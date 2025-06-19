#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct COR
{
    int c, v;
};

int main(void)
{
    int n, m;
    cin>>n>>m;
    vector<vector<COR>> board(n, vector<COR>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j].c;
            board[i][j].v = false;
        }
    }
    queue<pair<int, int>> que;
    int count = 0; // 봉우리 갯수
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j].v) // 방문했으면 그냥 스킵
                continue;
            que.push({i, j}); // 큐에 좌표 넣기
            board[i][j].v=true;
            bool isTop = true;
            while(!que.empty())
            {
                pair<int, int> cur = que.front();
                que.pop();
                for(int i=0; i<8; i++)
                {
                    int x = cur.first+dx[i];
                    int y = cur.second+dy[i];
                    if(x<0||x>n-1||y<0||y>m-1)
                        continue;
                    // 더 큰 거 발견하면 봉우리가 아님을 확인
                    // 같은거 발견하면 방문했는지 확인하고 담음
                    // -> 작은것도 담게 되면 작은거를 기준으로 탐색할때 큰게 나오면 isTop에도 영향을 미침
                    if(board[x][y].c>board[cur.first][cur.second].c)
                        isTop=false;
                    else if(board[x][y].c==board[cur.first][cur.second].c && !board[x][y].v)
                    {
                        que.push({x, y});
                        board[x][y].v=true;
                    }
                }
            }
            if(isTop)
            {
                //cout<<i<<", "<<j<<"\n";
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}