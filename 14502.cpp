#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int main(void)
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> map(n, vector<int>(m)); // 지도
    vector<pair<int, int>> empty; // 빈칸 정보가 담긴 벡터
    queue<pair<int, int>> virus; // 바이러스칸의 정보가 담긴 큐
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>map[i][j];
            if(map[i][j]==0) // 빈 칸을 vector에 담아놓고 관리
                empty.push_back({i, j});
            if(map[i][j]==2) // 바이러스를 queue에 담음
                virus.push({i, j});
        }

    int total=0;
    
    for(int i=0; i<empty.size(); i++)
    {
        for(int j=i+1; j<empty.size(); j++)
        {
            for(int k=j+1; k<empty.size(); k++)
            {
                queue<pair<int, int>> vrs(virus); // 바이러스
                vector<vector<int>> mp(map); // 지도
                mp[empty[i].first][empty[i].second]=mp[empty[j].first][empty[j].second]=mp[empty[k].first][empty[k].second]=1;
                while(!vrs.empty())
                {
                    pair<int, int> c = vrs.front();
                    vrs.pop();
                    for(int l=0; l<4; l++)
                    {
                        if(c.first+dx[l]<0||c.first+dx[l]>n-1||c.second+dy[l]<0||c.second+dy[l]>m-1)
                            continue;
                        if(mp[c.first+dx[l]][c.second+dy[l]]!=0)
                            continue;
                        mp[c.first+dx[l]][c.second+dy[l]]=2; // 바이러스 퍼짐
                        vrs.push({c.first+dx[l], c.second+dy[l]});
                    }
                }
                int count=0;
                for(int l=0; l<n; l++)
                {
                    for(int o=0; o<m; o++)
                    {
                        if(mp[l][o]==0)
                            count++;
                    }
                }
                total=max(count, total);
            }
        }
    }
    cout<<total;
    return 0;
}