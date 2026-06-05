#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main(void)
{
    int m, n;
    cin>>m>>n;

    int array[1000][1000] = {0, };

    queue<pair<pair<int, int>, int>> que;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>array[i][j];
            if(array[i][j]==1)
            {
                que.push({{i,j}, 0});
            }
        }
    }

    if(que.size()==m*n)
    {
        cout<<"0";
        return 0;
    }

    int t;

    while(!que.empty())
    {
        pair<pair<int, int>, int> p;
        p = que.front();
        que.pop();

        if(que.empty())
        {
            t = p.second;
        }

        for(int i=0; i<4; i++)
        {
            if((p.first.first+dx[i] >= 0 && p.first.first+dx[i] < n) && (p.first.second+dy[i] >= 0 && p.first.second+dy[i] < m))
            {
                if(array[p.first.first+dx[i]][p.first.second+dy[i]] == 0)
                {   
                    que.push({{p.first.first+dx[i], p.first.second+dy[i]}, p.second+1});
                    array[p.first.first+dx[i]][p.first.second+dy[i]] = 1;
                }
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(array[i][j]==0)
            {
                cout<<"-1";
                return 0;
            }
        }
        //cout<<endl;
    }

    cout<<t;

    return 0;
}