//#2178 bfs로 풂
// dfs로도 풀어볼 것

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

int main(void)
{
    int n, m;
    cin >> n >> m;

    char array[100][100]; // 지도
    int visit[100][100] = {0,}; // 방문 여부

    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j<m; j++)
        {
            array[i][j] = str[j];
        }
    }

    queue<pair<pair<int, int>, int>> que; // 좌표들을 담아놓을 큐
    // 좌표, 이동한 칸 수, 

    int block = n*m;

    que.push({{0,0}, 1});
    
    while(!que.empty())
    {
        int cn = que.front().first.first; // 현재 탐색하고 있는 x좌표
        int cm = que.front().first.second; // 현재 탐색하고 있는 y좌표
        int cb = que.front().second; // 현재 이동한 칸 수

        que.pop();

        if(cn==n-1 && cm==m-1 && cb<=block)
        {
            block = cb;
            continue;
        }

        if(visit[cn][cm]!=0)
            continue;
        else
            visit[cn][cm]++;

        //cout<<"좌표: "<< cn << " " << cm;
        //cout<<", 이동한 칸: "<< cb << "\n";
        
        for(int i=0; i<4; i++)
        {
            int tcn = cn+x[i];
            int tcm = cm+y[i];
            if(tcn < 0 || tcn > n-1 || tcm < 0|| tcm > m-1)
                continue;
            else if(array[tcn][tcm]=='1')
            {    
                que.push({{tcn, tcm}, cb+1});
            }
        }
        
        //array[cn][cm]='2'; // 2로 표시하면 방문했다는 뜻
    }

    cout<<block;

    return 0;
}