#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
struct INFO
{
    int x, y, m, w; // x y 좌표, 몇번움직였는지, 벽을부셨는지아닌지
};

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int main(void)
{
    int n, m;
    cin>>n>>m;
    if(n==1 && m==1)
    {
        cout<<"1";
        return 0;
    }
    vector<vector<char>> board(n, vector<char>(m)); // 지도
    bool visit[2][1000][1000]={false,}; // 0은 벽을 부신적이 없을때, 1은 벽을 부신적이 있을때

    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j<m; j++)
            board[i][j]=str[j];
    }

    queue<INFO> que; // 현재 탐색하고 있는 위치들 넣을 큐
    que.push({0,0,1,0}); // w 의 0은 벽을 부시지 않음, 1은 벽을 부심
    visit[0][0][0]=true;

    int min;
    bool check = true;
    while(!que.empty()&&check)
    {
        INFO c = que.front();
        que.pop();
        for(int i=0; i<4; i++)
        {
            if(c.x+dx[i]<0||c.x+dx[i]>n-1||c.y+dy[i]<0||c.y+dy[i]>m-1)
                continue;
            if(board[c.x+dx[i]][c.y+dy[i]]=='1') // 벽일경우
            {
                if(c.w==0&&visit[0][c.x+dx[i]][c.y+dy[i]]==0)//한 번도 부순적이 없을 경우
                {
                    que.push({c.x+dx[i], c.y+dy[i], c.m+1, 1});
                    visit[0][c.x+dx[i]][c.y+dy[i]]=visit[1][c.x+dx[i]][c.y+dy[i]]=1;
                }
                continue;
            }
            if(visit[c.w][c.x+dx[i]][c.y+dy[i]])
                continue;
            que.push({c.x+dx[i], c.y+dy[i], c.m+1, c.w});
            c.w==0?visit[0][c.x+dx[i]][c.y+dy[i]]=1:visit[1][c.x+dx[i]][c.y+dy[i]]=1;
            
            if(c.x+dx[i]==n-1 && c.y+dy[i]==m-1)
            {
                min=c.m+1;
                check=false;
            }
        }
    }
    cout<<(min?min:-1);
    return 0;
}