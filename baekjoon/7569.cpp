#include <iostream>
#include <queue>

using namespace std;

int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

typedef struct 
{
    int x, y, z, d; // x, y, z, 날짜
} coord;

int main(void)
{
    int m, n, h;
    cin>>m>>n>>h;

    int array[100][100][100] = {0, };

    queue<coord> que;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {    
                cin>>array[i][j][k];
                if(array[i][j][k]==1)
                {
                    //cout<<i<<j<<k;
                    que.push({j,k,i,0});
                }
            }
        }
    }

    //cout<<"\n";

    if(que.size()==m*n*h)
    {
        cout<<"0";
        return 0;
    }

    int t;

    while(!que.empty())
    {
        coord p;
        p = que.front();
        que.pop();

        if(que.empty())
        {
            t = p.d;
        }

        for(int i=0; i<6; i++)
        {
            if((p.x+dx[i] >= 0 && p.x+dx[i] < n) && (p.y+dy[i] >= 0 && p.y+dy[i] < m) && (p.z+dz[i] >= 0 && p.z+dz[i] < h))
            {
                if(array[p.z+dz[i]][p.x+dx[i]][p.y+dy[i]] == 0)
                {   
                    que.push({p.x+dx[i], p.y+dy[i], p.z+dz[i], p.d+1});
                    array[p.z+dz[i]][p.x+dx[i]][p.y+dy[i]] = 1;
                }
            }
        }

        //cout<<"기준 좌표: "<<p.x<<", "<<p.y<<", "<<p.z<<"\n";

        // for(int i = 0; i<h; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         for(int k=0; k<m; k++)
        //         {
        //             cout<<array[i][j][k]<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        //cout<<"------------------------\n";
    }

    for(int i = 0; i<h; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                if(array[i][j][k]==0)
                {
                    cout<<"-1";
                    return 0;
                }
            }
        }
        //cout<<endl;
    }

    cout<<t;

    return 0;
}